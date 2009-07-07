# ex:ts=8
# Ports collection makefile for:  vim
# Date created:			  Sat June 29, 1996
# Whom:				  David O'Brien (obrien@cs.ucdavis.edu)
#
# $FreeBSD$
#

PORTNAME?=	vim
PATCHLEVEL=	209
PORTVERSION=	7.2.${PATCHLEVEL}
RELEASE=	vim-${PORTVERSION:C/\.[0-9a-z]*$//}
PORTREVISION?=	0
CATEGORIES?=	editors
MASTER_SITES=	${MASTER_SITE_VIM}
DISTFILES=	${RELEASE}${EXTRACT_SUFX}

PATCH_SITES=	${MASTER_SITES:S|unix|patches/${PORTVERSION:C/\.[0-9a-z]*$//}|}\
		ftp://ftp.FreeBSD.org/pub/FreeBSD/ports/local-distfiles/obrien/
PATCHFILES!=	/usr/bin/jot -s " " -w ${PORTVERSION:C/\.[0-9]*$//}.%03d  \
			${PATCHLEVEL} 1 ${PATCHLEVEL}
#	bits to remove
BADPATCHES=	007 036 049 071 072 074 088 089 093 101 138 150 172 191 194 204 205
#.if !defined(WITH_LANG)
#BADPATCHES+=
#.endif
.for p in ${BADPATCHES}
PATCHFILES:=	${PATCHFILES:N7.2.${p}}
.endfor
PATCHFILES:=	${PATCHFILES:S/041/041%/}

MAINTAINER?=	obrien@FreeBSD.org
COMMENT?=	Vi "workalike", with many additional features

SLAVEDIRS=	editors/vim-lite

.if defined(WITH_OPTIONS) || defined(WITH_VIM_OPTIONS)
.include "${.CURDIR}/../vim/options"
.endif

CONFLICTS=	vim6* vim*-lite
MAKE_JOBS_UNSAFE= yes
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
MANLANG=	"" ru.KOI8-R ru.UTF-8 pl.ISO8859-2 pl.UTF-8 pl fr.ISO8859-1 \
		fr.UTF-8 fr it.ISO8859-1 it.UTF-8 it

.if defined(PACKAGE_BUILDING) && !defined(LITE)
WITH_CSCOPE=	yes
WITH_EXUBERANT_CTAGS=yes
WITH_LANG=	yes
WITH_PERL=	yes
WITH_PYTHON=	yes
WITH_RUBY=	yes
WITH_TCL=	yes
.endif

.if defined(WITH_PYTHON)
USE_PYTHON=	yes
MAKE_ARGS+=	CONF_OPT_PYTHON="--enable-pythoninterp"
.endif

.if defined(WITH_RUBY)
USE_RUBY=	yes
MAKE_ARGS+=	CONF_OPT_RUBY="--enable-rubyinterp"
.endif

.if defined(WITH_TCL)
USE_TCL=	82+
USE_TCL_NO_THREADS=	yes
.endif

.if defined(WITH_PERL)
WANT_PERL=	yes
.endif

.if !defined(WITHOUT_X11)
WANT_GNOME=	yes
.endif

.include <bsd.port.pre.mk>

.if !defined(LITE)
MAKE_ARGS+=	CONF_OPT_FEAT="--with-features=big"
I18N=		CONF_OPT_MULTIBYTE="--enable-multibyte --enable-fontset --enable-xim"

.if defined(NO_GUI)
WITHOUT_X11=	yes
.endif

.if defined(WITH_CSCOPE)
RUN_DEPENDS+=	cscope:${PORTSDIR}/devel/cscope
MAKE_ARGS+=	CONF_OPT_CSCOPE="--enable-cscope"
.endif

.if defined(WITH_EXUBERANT_CTAGS)
RUN_DEPENDS+=	exctags:${PORTSDIR}/devel/ctags
.endif

.if defined(WITH_PERL)
USE_PERL5=	yes
MAKE_ARGS+=	CONF_OPT_PERL="--enable-perlinterp"
.endif

.if defined(WITH_TCL)
MAKE_ARGS+=	CONF_OPT_TCL="--enable-tclinterp --with-tclsh="${TCLSH:S/${LOCALBASE}\/bin\///g}""
.endif

.if !defined(WITHOUT_X11)
#	for now default the GUI to the GTK+ one
#	will be reviewed when the GTK+ 1.{3,4} behemoth is released
.if !defined(WITH_ATHENA) && !defined(WITH_MOTIF) && !defined(WITH_GNOME) && !defined(WITH_GTK2)
USE_GNOME=	gtk12
.endif

.if defined(WITH_ATHENA)
MAKE_ARGS+=	CONF_OPT_GUI="--enable-gui=athena" ${I18N}
.elif defined(WITH_GTK2)
USE_GNOME=	gtk20
PKGNAMESUFFIX=	-gtk2
MAKE_ARGS+=	CONF_OPT_GUI="--enable-gui=gtk2 --with-gtk-prefix=${LOCALBASE}" ${I18N}
MAKE_ARGS+=	X_LIBS="$(X_LIBS) -lXt"
USE_XORG+=	xt
.elif defined(WITH_GNOME)
.if ${WITH_GNOME:Mgnomelibs}!="" || ${WITH_GNOME}=="yes" || \
	${WITH_GNOME}=="1"
USE_GNOME=	gnomelibs gnomeprefix
PKGNAMESUFFIX=	-gnome
MAKE_ARGS+=	CONF_OPT_GUI="--enable-gui=gnome --with-gtk-prefix=${LOCALBASE}" ${I18N}
MAKE_ARGS+=	X_LIBS="$(X_LIBS) -lXt"
USE_XORG+=	xt
.else
USE_GNOME=	gtk12
MAKE_ARGS+=	CONF_OPT_GUI="--enable-gui=gtk --with-gtk-prefix=${LOCALBASE}" ${I18N}
MAKE_ARGS+=	X_LIBS="$(X_LIBS) -lXt"
USE_XORG+=	xt
.endif
.elif defined(WITH_MOTIF)
USE_MOTIF=	yes
MAKE_ARGS+=	CONF_OPT_GUI="--enable-gui=motif --with-motif-lib=\"${MOTIFLIB}\"" MOTIFHOME=${LOCALBASE} ${I18N}
.endif
.else	# WITHOUT_X11
MAKE_ARGS+=	CONF_OPT_GUI="--enable-gui=no --without-x" ${I18N}
.endif	# WITHOUT_X11

.else	# LITE
PKGNAMESUFFIX=	-lite
MAKE_ARGS+=	CONF_OPT_GUI="--enable-gui=no --without-x --enable-multibyte"
MAKE_ARGS+=	CONF_OPT_PERL="--disable-perlinterp --disable-pythoninterp --disable-tclinterp --disable-rubyinterp"
.endif	# LITE

.if exists(${PREFIX}/lib/libiconv.so)
USE_ICONV=	yes
.endif

.if defined(WITH_LANG)
LANG_FILE=	${RELEASE}-lang.tar.gz
DISTFILES+=    	${LANG_FILE}:lang_file
MASTER_SITES+=	${MASTER_SITE_VIM:S|unix/|extra/:lang_file|}
EXTRACT_ONLY=	${RELEASE}${EXTRACT_SUFX}
USE_GETTEXT=   	yes
.endif

post-extract:
.if defined(WITH_LANG)
	@${ECHO_MSG} ">>>   extracting ${LANG_FILE} ..."
	@${TAR} -C ${WRKDIR} -xzf ${DISTDIR}/${DIST_SUBDIR}/${LANG_FILE}
.endif

.if defined(WITH_EXUBERANT_CTAGS)
CTAGS_CMD=	exctags -R .
.else
CTAGS_CMD=	${FIND} . -type f \\|${XARGS} ctags
.endif

post-patch:
	@(${FIND} ${WRKSRC}/../runtime/ -name menu\*.vim -print0 | ${XARGS} -0 \
		${REINPLACE_CMD} -e 's,ctags -R \.,${CTAGS_CMD},g')

pre-configure:
	@(cd ${WRKSRC} ; ${MAKE} distclean)
	@${REINPLACE_CMD} -e ' \
		s|\$$gtk_config_prefix/bin/gtk-config|\$${GTK_CONFIG}|g; \
		s|\$$gtk_config_exec_prefix/bin/gtk-config|\$${GTK_CONFIG}|g; \
		s|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/auto/configure
.if defined(WITH_XTERM_SAVE)
	@${REINPLACE_CMD} -e ' \
		s|/\* #define FEAT_XTERM_SAVE \*/|#define FEAT_XTERM_SAVE|g' \
		${WRKSRC}/feature.h
.endif

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
	cd ${PREFIX} ;\
	    ${FIND} share/vim/${_DATADIR} -type f -o -type l	\
	    	| ${SORT}					\
	    	>${WRKDIR}/PLIST.share-vim
	cd ${PREFIX} ;\
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
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

show-options:
	@${MAKE} -DWITH_OPTIONS showconfig

cklatest:
	-ncftpls \
	    ftp://ftp.vim.org/pub/vim/patches/${PORTVERSION:C/\.[0-9a-z]*$//}/ \
		| fgrep ${PORTVERSION:C/[0-9]*$//} | ${TAIL}

find-bad-patches:
	@cd ${DISTDIR} ; egrep -l \
		'(src/if_ole|src/gui_(w32|w48|mac)|src/os_(riscos|cyg|os2|vms|amiga|win32|mswin))|src/Make_(cyg|vms|mvc)'\
		vim/${PORTVERSION:C/\.[0-9a-z]*$//}*

vim-makesum:
	${MAKE} WITH_LANG=yes makesum

ckp:
	${MAKE} -DPATCH_DEBUG clean patch

ckpl:
	${MAKE} -DPATCH_DEBUG WITH_LANG=yes clean patch

lang:
	${MAKE} WITH_LANG=yes

.include <bsd.port.post.mk>
