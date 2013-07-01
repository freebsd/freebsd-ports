# ex:ts=8
# Created by:	David O'Brien <obrien@cs.ucdavis.edu>
# Created:	Sat June 29, 1996
# $FreeBSD$

PORTNAME?=	vim
#		! _NEVER_ reduce or lower PATCHLEVEL, even if the PATCHLEVEL
#		! value # is added to BADPATCHES.  Doing otherwise will cause
#		! PORTEPOCH to be needed, which we do NOT want.
#
#		! DO NOT increase PATCHLEVEL to a patch listed in BADPATCHES.
#		! Doing so is dis-genuine.  It implies we're at a level we are
#		! not.  The "PATCHLEVEL" patch needs to apply before bumping
#		! PATCHLEVEL to that level.
PATCHLEVEL=	1014
PORTVERSION=	7.3.${PATCHLEVEL}
RELEASE=	vim-${PORTVERSION:C/\.[0-9a-z]*$//}
PORTREVISION?=	1
CATEGORIES?=	editors
MASTER_SITES=	${MASTER_SITE_VIM}
DISTFILES=	${RELEASE}${EXTRACT_SUFX}

PATCH_SITES=	${MASTER_SITES:S|unix|patches/${PORTVERSION:C/\.[0-9a-z]*$//}|}\
		ftp://ftp.FreeBSD.org/pub/FreeBSD/ports/local-distfiles/obrien/:local
PATCHFILES!=	/usr/bin/jot -s " " -w ${PORTVERSION:C/\.[0-9]*$//}.%03d  \
			${PATCHLEVEL} 1 ${PATCHLEVEL}
#	bits to remove
BADPATCHES=	225 235 246 247 252 253 336 386 387 400 434 487 491 527 569 578 579 580 581 583 584 \
		611 640 650 654 655 656 657 658 659 660 670 671 672 683 684 688 711 748 \
		749 751 780 786 791 793 796 798 803 808 810 816 817 819 825 827 831 \
		838 861 873 881 887 890 893 895 896 898 904 906 907 908 909 910 911 914 922 924 \
		925 926 928 929 932 937 938 939 940 941 942 943 945 947 948 949 950 951 952 954 955 956 \
		957 958 959 960 961 962 963 964 965 966 967 969 970 973 975 976 977 978 979 980 981 982 \
		983 986 987 988 989 990 991 992 993 994 995 996 997 998 999 1001 1002 1003 1004 1005 1006 \
		1008 1009 1010 1011 1012 1013 1014

.for p in ${BADPATCHES}
PATCHFILES:=	${PATCHFILES:N7.3.${p}}
.endfor

MAINTAINER?=	obrien@FreeBSD.org
COMMENT?=	Vi "workalike", with many additional features

SLAVEDIRS=	editors/vim-lite

.if !defined(LITE)
.if defined(WITH_OPTIONS) || defined(WITH_VIM_OPTIONS)
.include "${.CURDIR}/../vim/options"
OPTIONS_DEFAULT+=	CSCOPE EXUBERANT_CTAGS PERL PYTHON RUBY \
			TCL LUA X11 GTK2
.else
VIM_PORT_SCRIPT_LANGS?=	LUA PERL PYTHON RUBY TCL
VIM_PORT_OPTIONS=	CSCOPE DOCS EXAMPLES EXUBERANT_CTAGS \
			${VIM_PORT_SCRIPT_LANGS}
PORT_OPTIONS?=	${VIM_PORT_OPTIONS}
.endif
.endif

.include <bsd.port.options.mk>

CONFLICTS=	vim6* vim*-gnome libsysinfo
.if defined(LITE)
CONFLICTS+=	vim*
.else
CONFLICTS+=	vim*-lite
.endif
MAKE_JOBS_UNSAFE=	yes
USE_BZIP2=	yes
DIST_SUBDIR=	vim
WRKSRC=		${WRKDIR}/vim${PORTVERSION:C/\.[0-9]*$//:S/.//g}/src
PATCH_DIST_ARGS= -d ${WRKSRC:S/src$//} --batch --forward --quiet -E ${PATCH_DIST_STRIP}
# consider
#PATCH_DIST_ARGS=	-t
REINPLACE_ARGS=		-i ""
MAKE_ARGS+=	CONF_ARGS="--prefix=${PREFIX} --with-tlib=termlib ${CSCOPE_ARG}"
ALL_TARGET=	#
_DATADIR=	${RELEASE:S/-//g:S/.//g}
DATADIR=	${PREFIX}/share/vim/${_DATADIR}
PLIST_SUB=	VIM_VER=${_DATADIR}
MAN1=		evim.1 vim.1 vimdiff.1 vimtutor.1 xxd.1
MLINKS=		vim.1 rvim.1	vim.1 rview.1
.if !defined(LITE)
MLINKS+=	vim.1 gvim.1	vim.1 gview.1	vimdiff.1 gvimdiff.1 \
		vim.1 rgvim.1	vim.1 rgview.1	evim.1 eview.1
.endif

.if ${PORT_OPTIONS:MNLS}
MANLANG=	"" ru.KOI8-R ru.UTF-8 pl.ISO8859-2 pl.UTF-8 pl fr.ISO8859-1 \
		fr.UTF-8 fr it.ISO8859-1 it.UTF-8 it
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
MAKE_ARGS+=	CONF_OPT_NLS="--disable-nls"
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MPYTHON}
USE_PYTHON=	yes
MAKE_ARGS+=	CONF_OPT_PYTHON="--enable-pythoninterp"
.endif

.if ${PORT_OPTIONS:MRUBY}
USE_RUBY=	yes
MAKE_ARGS+=	CONF_OPT_RUBY="--enable-rubyinterp"
.endif

.if ${PORT_OPTIONS:MTCL}
USE_TCL=	85+
MAKE_ARGS+=	CONF_OPT_TCL="--enable-tclinterp --with-tclsh="${TCLSH:S/${LOCALBASE}\/bin\///g}""
.endif

.if ${PORT_OPTIONS:MLUA}
USE_LUA=	yes
MAKE_ARGS+=	CONF_OPT_LUA="--enable-luainterp=dynamic"
MAKE_ARGS+=	CONF_OPT_LUA_PREFIX="--with-lua-prefix=${LOCALBASE}"
.endif

.if ${PORT_OPTIONS:MPERL}
USE_PERL5=	yes
MAKE_ARGS+=	CONF_OPT_PERL="--enable-perlinterp"
.endif

WANT_GNOME=	yes

.if defined(LITE)
PKGNAMESUFFIX=	-lite
CONF_OPT_GUI="--enable-gui=no --without-x --enable-multibyte"
MAKE_ARGS+=	CONF_OPT_PERL="--disable-perlinterp --disable-pythoninterp --disable-tclinterp --disable-rubyinterp --disable-luainterp"
.else	# !LITE
MAKE_ARGS+=	CONF_OPT_FEAT="--with-features=big"
I18N=		CONF_OPT_MULTIBYTE="--enable-multibyte --enable-fontset --enable-xim"
CONF_OPT_GUI="--enable-gui=no --without-x"
.endif

.if ${PORT_OPTIONS:MCSCOPE}
RUN_DEPENDS+=	cscope:${PORTSDIR}/devel/cscope
MAKE_ARGS+=	CONF_OPT_CSCOPE="--enable-cscope"
.endif

.if ${PORT_OPTIONS:MEXUBERANT_CTAGS}
RUN_DEPENDS+=	exctags:${PORTSDIR}/devel/ctags
CTAGS_CMD=	exctags -R .
.else
CTAGS_CMD=	${FIND} . -type f \\|${XARGS} ctags
.endif

.if ${PORT_OPTIONS:MX11}
CONF_OPT_GUI="--enable-gui=no --with-x"

. if ${PORT_OPTIONS:MATHENA}
CONF_OPT_GUI="--enable-gui=athena"
USE_XORG+=	xaw
. endif

. if ${PORT_OPTIONS:MGTK2}
USE_GNOME=	gtk20
CONF_OPT_GUI="--enable-gui=gtk2 --with-gtk-prefix=${LOCALBASE}"
MAKE_ARGS+=	X_LIBS="$(X_LIBS) -lXt"
USE_XORG+=	xt
. endif

. if ${PORT_OPTIONS:MGNOME}
USE_GNOME=	libgnomeui
PKGNAMESUFFIX=	-gnome2
CONF_OPT_GUI="--enable-gui=gnome2"
MAKE_ARGS+=	X_LIBS="$(X_LIBS) -lXt"
USE_XORG+=	xt glproto
. endif

. if ${PORT_OPTIONS:MMOTIF}
USE_MOTIF=	yes
CONF_OPT_GUI="--enable-gui=motif --with-motif-lib=\"${MOTIFLIB}\""
MAKE_ARGS+=	MOTIFHOME=${LOCALBASE}
. endif

.endif
MAKE_ARGS+=	CONF_OPT_GUI=${CONF_OPT_GUI} ${I18N}


.if exists(${LOCALBASE}/lib/libiconv.so)
USES+=	iconv
.endif


pre-patch:
	@${REINPLACE_CMD} -e 's/newwin/new_wp/g' ${WRKSRC}/window.c

post-patch:
	@(${FIND} ${WRKSRC}/../runtime/ -name menu\*.vim -print0 | ${XARGS} -0 \
		${REINPLACE_CMD} -e 's,ctags -R \.,${CTAGS_CMD},g')
.if !defined(STRIP) || ${STRIP} == ""
	${REINPLACE_CMD} '/$$(STRIP)/d' ${WRKSRC}/Makefile
.endif

pre-configure:
	@${CP} -pv ${WRKSRC}/config.mk.dist ${WRKSRC}/auto/config.mk
	@(cd ${WRKSRC} ; ${MAKE} distclean)
	@${REINPLACE_CMD} -e ' \
		s|\$$gtk_config_prefix/bin/gtk-config|\$${GTK_CONFIG}|g; \
		s|\$$gtk_config_exec_prefix/bin/gtk-config|\$${GTK_CONFIG}|g; \
		s|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/auto/configure
.if ${PORT_OPTIONS:MXTERM_SAVE}
	@${REINPLACE_CMD} -e ' \
		s|/\* #define FEAT_XTERM_SAVE \*/|#define FEAT_XTERM_SAVE|g' \
		${WRKSRC}/feature.h
.endif

post-configure:
	@(cd ${WRKSRC} ; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_ARGS} scratch config)
	${REINPLACE_CMD} -e 's@#define HAVE_SYSINFO 1@/* #undef HAVE_SYSINFO */@' ${WRKSRC}/auto/config.h

#	Clean up junk files to keep them from being installed.
pre-install:
	@${FIND} ${WRKSRC:H} -type f -name '*.orig' -delete

post-install:
	[ -e ${PREFIX}/bin/gvim ] || (cd ${PREFIX}/bin ; ${LN} -sf vim gvim)
	#	below needed for `vim-lite' port
	${TEST} -e ${PREFIX}/bin/rgvim  || (cd ${PREFIX}/bin ; ${LN} -sf vim rgvim)
	${TEST} -e ${PREFIX}/bin/gview  || (cd ${PREFIX}/bin ; ${LN} -sf vim gview)
	${TEST} -e ${PREFIX}/bin/rgview || (cd ${PREFIX}/bin ; ${LN} -sf vim rgview)
	${TEST} -e ${PREFIX}/bin/evim   || (cd ${PREFIX}/bin ; ${LN} -sf vim evim)
	${TEST} -e ${PREFIX}/bin/eview  || (cd ${PREFIX}/bin ; ${LN} -sf vim eview)
	${TEST} -e ${PREFIX}/bin/gvimdiff  \
		|| (cd ${PREFIX}/bin ; ${LN} -sf vim gvimdiff)
	${TEST} -e ${PREFIX}/bin/gvimtutor  \
		|| (cd ${PREFIX}/bin ; ${LN} -sf vimtutor gvimtutor)
	${INSTALL_DATA} ${FILESDIR}/vietnamese_viscii.vim ${DATADIR}/keymap
	cd ${PREFIX} ;						\
	    ${FIND} share/vim/${_DATADIR} -type f -o -type l	\
	    	| ${SORT}					\
	    	>${WRKDIR}/PLIST.share-vim
	cd ${PREFIX} ;						\
	    ${FIND} share/vim/${_DATADIR} -type d		\
	    	| ${SORT} -r | ${SED} -e 's/^/@dirrm /g'	\
		>>${WRKDIR}/PLIST.share-vim
	${ECHO_CMD} "r ${TMPPLIST}"			> ${WRKDIR}/ex.script
	${ECHO_CMD} "/Insert PLIST.share-vim"		>> ${WRKDIR}/ex.script
	${ECHO_CMD} "d"					>> ${WRKDIR}/ex.script
	${ECHO_CMD} "r ${WRKDIR}/PLIST.share-vim"	>> ${WRKDIR}/ex.script
	${ECHO_CMD} "x!"				>> ${WRKDIR}/ex.script
	${CP} -p ${TMPPLIST} ${TMPPLIST}.pre-share-vim
	cd ${WRKDIR} ; ex < ex.script

show-options:
	@${MAKE} -DWITH_OPTIONS showconfig

.if defined(ONT_CHECKSUM)
checksum:
.endif

cklatest: .PHONY
	@${ECHO} -n "Currently at: "
	@${MAKE} -V PATCHLEVEL
	-(${SED} -i '' "s/^PATCHLEVEL=.*$$/PATCHLEVEL=	`ncftpls \
	    ftp://ftp.vim.org/pub/vim/patches/${PORTVERSION:C/\.[0-9a-z]*$//}/ \
		| grep "^${PORTVERSION:C/\.[0-9a-z]*$//}" \
		| ${SED} -n -e 's/${PORTVERSION:C/[0-9]*$//}\([0-9][0-9][0-9]\)$$/\1/p' \
		| ${TAIL} -1`/" Makefile)
	@${ECHO} -n "Now at: "
	@${MAKE} -V PATCHLEVEL

find-bad-patches:
	@cd ${DISTDIR} ; egrep -l \
		'(src/if_(ole|mzsch)|src/gui_(w32|w48|mac)|src/os_(riscos|cyg|os2|vms|amiga|win32|mswin))|src(/testdir)?/Make_(dos|cyg|vms|mvc|ming|os2|amiga|mms)'\
		vim/${PORTVERSION:C/\.[0-9a-z]*$//}*

ckp:
	/usr/bin/time -h ${MAKE} -DPATCH_DEBUG -DONT_CHECKSUM clean patch

ckmtree:
	${MTREE_CMD} -f ${MTREE_FILE} -p ${PREFIX}

.include <bsd.port.mk>
