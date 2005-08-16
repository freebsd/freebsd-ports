# ex:ts=8
# Ports collection makefile for:  vim
# Date created:			  Sat June 29, 1996
# Whom:				  David O'Brien (obrien@cs.ucdavis.edu)
#
# $FreeBSD$
#

PORTNAME?=	vim
PATCHLEVEL=	85
PORTVERSION=	6.3.${PATCHLEVEL}
PORTREVISION?=	0
CATEGORIES?=	editors
MASTER_SITES=	${MASTER_SITE_VIM}
DISTNAME=	vim-${PORTVERSION:C/\.[0-9a-z]*$//}

PATCH_SITES=	${MASTER_SITES:S|unix|patches/${PORTVERSION:C/\.[0-9a-z]*$//}|}
PATCHFILES!=	/usr/bin/jot -s " " -w ${PORTVERSION:C/\.[0-9]*$//}.%03d  \
			${PATCHLEVEL} 1 ${PATCHLEVEL}
#	bits to remove
BADPATCHES=	000 022 025 035 038 041 044 047 048 052 073 077 078 080 084
.for p in ${BADPATCHES}
PATCHFILES:=	${PATCHFILES:N6.3.${p}}
.endfor

MAINTAINER?=	obrien@FreeBSD.org
COMMENT?=	Vi "workalike", with many additional features

SLAVEDIRS=	editors/vim-lite

.if defined(PACKAGE_BUILDING) && !defined(LITE)
WITH_TCL=	yes
WITH_PERL=	yes
WITH_PYTHON=	yes
WITH_CSCOPE=	yes
.endif

USE_BZIP2=	yes
USE_REINPLACE=	yes
DIST_SUBDIR=	vim
WRKSRC=		${WRKDIR}/vim${PORTVERSION:C/\.[0-9]*$//:S/.//g}/src
PATCH_DIST_ARGS= -d ${WRKSRC:S/src$//} --batch --forward --quiet -E ${PATCH_DIST_STRIP}
# consider
#PATCH_DIST_ARGS=	-t
MAKE_ARGS+=	CONF_ARGS="--prefix=${PREFIX} --with-tlib=termlib ${CSCOPE_ARG}"
ALL_TARGET=	#
_DATADIR=	${DISTNAME:S/-//g:S/.//g}
DATADIR=	${PREFIX}/share/vim/${_DATADIR}
PLIST_SUB=	VIM_VER=${_DATADIR}
MAN1=		evim.1 vim.1 vimdiff.1 vimtutor.1 xxd.1
MLINKS=		vim.1 rvim.1	vim.1 rview.1
.if !defined(LITE)
MLINKS+=	vim.1 gvim.1	vim.1 gview.1	vimdiff.1 gvimdiff.1 \
		vim.1 rgvim.1	vim.1 rgview.1	evim.1 eview.1
.endif

WANT_GNOME=	yes

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

.if defined(WITH_PYTHON)
USE_PYTHON=	yes
MAKE_ARGS+=	CONF_OPT_PYTHON="--enable-pythoninterp"
.endif

.if defined(WITH_PERL)
USE_PERL5=	yes
MAKE_ARGS+=	CONF_OPT_PERL="--enable-perlinterp"
.endif

.if defined(WITH_TCL)
BUILD_DEPENDS=	tclsh8.4:${PORTSDIR}/lang/tcl84
LIB_DEPENDS=	tcl84.1:${PORTSDIR}/lang/tcl84
MAKE_ARGS+=	CONF_OPT_TCL="--enable-tclinterp"
.endif

.if defined(WITH_RUBY)
USE_RUBY=	yes
MAKE_ARGS+=	CONF_OPT_RUBY="--enable-rubyinterp"
.endif

.if !defined(WITHOUT_X11)
#	for now default the GUI to the GTK+ one
#	will be reviewed when the GTK+ 1.{3,4} behemoth is released
.if !defined(WITH_ATHENA) && !defined(WITH_MOTIF) && !defined(WITH_GNOME) && !defined(WITH_GTK2)
WITH_GNOME=	gtk12
.endif

.if defined(WITH_ATHENA)
MAKE_ARGS+=	CONF_OPT_GUI="--enable-gui=athena" ${I18N}
.elif defined(WITH_GTK2)
USE_GNOME=	gtk20
PKGNAMESUFFIX=	-gtk2
MAKE_ARGS+=	CONF_OPT_GUI="--enable-gui=gtk2 --with-gtk-prefix=${X11BASE}" ${I18N}
MAKE_ARGS+=	X_LIBS="$(X_LIBS) -lXt"
.elif defined(WITH_GNOME)
.if ${WITH_GNOME:Mgnomelibs}!="" || ${WITH_GNOME}=="yes" || \
	${WITH_GNOME}=="1"
USE_GNOME=	gnomelibs gnomeprefix
PKGNAMESUFFIX=	-gnome
MAKE_ARGS+=	CONF_OPT_GUI="--enable-gui=gnome --with-gtk-prefix=${X11BASE}" ${I18N}
MAKE_ARGS+=	X_LIBS="$(X_LIBS) -lXt"
.else
USE_GNOME=	gtk12
MAKE_ARGS+=	CONF_OPT_GUI="--enable-gui=gtk --with-gtk-prefix=${X11BASE}" ${I18N}
MAKE_ARGS+=	X_LIBS="$(X_LIBS) -lXt"
.endif
.elif defined(WITH_MOTIF)
USE_MOTIF=	yes
MAKE_ARGS+=	CONF_OPT_GUI="--enable-gui=motif --with-motif-lib=\"${MOTIFLIB}\"" MOTIFHOME=${X11BASE} ${I18N}
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

pre-configure:
	@(cd ${WRKSRC} ; ${MAKE} distclean)
	@${REINPLACE_CMD} -e 's|8\.2|8.4|; \
		s|\$$gtk_config_prefix/bin/gtk-config|\$${GTK_CONFIG}|; \
		s|\$$gtk_config_exec_prefix/bin/gtk-config|\$${GTK_CONFIG}|' \
		${WRKSRC}/auto/configure

#	Clean up junk files to keep them from being installed.
pre-install:
	@${RM} -f ${WRKSRC}/../runtime/macros/maze/*.orig

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

cklatest:
	@-ncftpls \
	    ftp://ftp.vim.org/pub/vim/patches/${PORTVERSION:C/\.[0-9a-z]*$//}/ \
		| fgrep ${PORTVERSION:C/[0-9]*$//} | ${TAIL}

find-bad-patches:
	cd ${DISTDIR} ; egrep -l \
		'(src/os_win32|src/os_mswin|src/if_ole|src/proto/gui_w32|src/gui_w48|src/gui_mac|src/os_riscos|cyg|vms)'\
		vim/${PORTVERSION:C/\.[0-9a-z]*$//}*

.include <bsd.port.post.mk>
