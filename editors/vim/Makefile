# ex:ts=8
# Ports collection makefile for:  vim
# Date created:			  Sat June 29, 1996
# Whom:				  David O'Brien (obrien@cs.ucdavis.edu)
#
# $FreeBSD$
#

PORTNAME?=	vim
PORTVERSION=	6.0.143
PORTREVISION?=	0
CATEGORIES?=	editors
MASTER_SITES=	ftp://nuxi.ucdavis.edu/pub/vim/unix/ \
		ftp://ftp.nuxi.com/pub/vim/unix/ \
		ftp://ftp.vim.org/pub/vim/unix/  \
		ftp://ftp.is.co.za/applications/editors/vim/unix/  \
		ftp://ftp.prz.tu-berlin.de/pub/unix/editors/vim/unix/  \
		ftp://ftp.mirror.ac.uk/sites/ftp.vim.org/pub/vim/unix/ \
		ftp://ftp.progsoc.uts.edu.au/pub/vim/unix/
DISTNAME=	vim-${PORTVERSION:C/\.[0-9]*$//}

PATCH_SITES=	${MASTER_SITES:S/unix/patches/}
.for p in	01 02 03 04 05 06 07 08 09 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 28 29 30 31 32 33 34 36 37 38 39 40 41 42 43 44 45 46 47 49 50 51 52 54 55 56 57 58 59 60 61 62 63 65 66 67 68 69 71 72 74 75 76 77 78 79 80 81 82 83 84 85 86 88 89 90 91 92 94 95 96 97 98 99
PATCHFILES+=	${PORTVERSION:C/\.[0-9]*$//}.0${p}
.endfor
.for q in	0 1 2 3
.for p in	0 1 2 3 4 5 6 7 8 9
PATCHFILES+=	${PORTVERSION:C/\.[0-9]*$//}.1${q}${p}
.endfor
.endfor
.for p in	0 1 2 3
PATCHFILES+=	${PORTVERSION:C/\.[0-9]*$//}.14${p}
.endfor

BADPATCHES=	012 106 107 115 116 117 119 121 122 123 125 135 137 138

.for i in ${BADPATCHES}
PATCHFILES:=	${PATCHFILES:N6.0.${i}}
.endfor

MAINTAINER?=	obrien@FreeBSD.org

SLAVEDIRS=	editors/vim-lite

.if defined(PACKAGE_BUILDING) && !defined(LITE)
BUILD_DEPENDS=	tclsh8.0:${PORTSDIR}/lang/tcl80
LIB_DEPENDS=	tcl80.1:${PORTSDIR}/lang/tcl80
USE_PERL5=	yes
USE_PYTHON=	yes
.endif

USE_BZIP2=	yes
DIST_SUBDIR=	vim
WRKSRC=		${WRKDIR}/vim${PORTVERSION:C/\.[0-9]*$//:S/.//g}/src
PATCH_DIST_ARGS=	-d ${WRKDIR}/${PORTNAME}${PORTVERSION:C/\.[0-9]*$//:S/.//g} --forward --quiet -E ${PATCH_DIST_STRIP}
# consider
#PATCH_DIST_ARGS=	-t
MAKE_ARGS+=	CONF_ARGS="--prefix=${PREFIX} --with-tlib=termlib ${CSCOPE_ARG}"
ALL_TARGET=	#
PLIST_SUB=	VIM_VER=${DISTNAME:S/-//:S/.//}
DATADIR=	${PREFIX}/share/vim/${DISTNAME:S/-//:S/.//}
MAN1=		evim.1 vim.1 vimdiff.1 vimtutor.1 xxd.1
MLINKS=		vim.1 rvim.1  vim.1 rview.1

.include <bsd.port.pre.mk>

.if !defined(LITE)
MLINKS+=	vim.1 gvim.1  vim.1 gview.1  vim.1 rgvim.1  vim.1 rgview.1  \
		eview.1 gvimdiff.1

MAKE_ARGS+=	CONF_OPT_FEAT="--with-features=big"
I18N=		CONF_OPT_MULTIBYTE="--enable-multibyte --enable-fontset --enable-xim"

.if defined(NO_GUI)
WITHOUT_X11=	yes
.endif

.if defined(WITH_CSCOPE)
RUN_DEPENDS+=	cscope:${PORTSDIR}/devel/cscope
CSCOPE_ARG=	--enable-cscope
.endif

.if !defined(WITHOUT_X11)
#	for now default the GUI to the GTK+ one
#	will be reviewed when the GTK+ 1.{3,4} behemoth is released
.if !defined(WITH_ATHENA) && !defined(WITH_GTK) && !defined(WITH_MOTIF)
WITH_GTK=	yes
.endif

.if defined(WITH_ATHENA)
MAKE_ARGS+=	CONF_OPT_GUI="--enable-gui=athena" ${I18N}
.elif defined(WITH_GTK)
USE_GTK=	yes
MAKE_ARGS+=	CONF_OPT_GUI="--enable-gui=gtk --with-gtk-prefix=${X11BASE}" ${I18N}
MAKE_ARGS+=	X_LIBS="$(X_LIBS) -lXt"
.elif defined(WITH_MOTIF)
USE_MOTIF=	yes
MAKE_ARGS+=	CONF_OPT_GUI="--enable-gui=motif --with-motif-lib=\"${MOTIFLIB}\"" MOTIFHOME=${X11BASE} ${I18N}
.endif
.else	# WITHOUT_X11
MAKE_ARGS+=	CONF_OPT_GUI="--enable-gui=no --without-x" ${I18N}
.endif	# WITHOUT_X11

.if defined(PACKAGE_BUILDING)
MAKE_ARGS+=	CONF_OPT_PERL="--enable-perlinterp --enable-pythoninterp --enable-tclinterp --enable-cscope"
.endif

.else	# LITE
PKGNAMESUFFIX=	-lite
MAKE_ARGS+=	CONF_OPT_GUI="--enable-gui=no --without-x --enable-multibyte"
MAKE_ARGS+=	CONF_OPT_PERL="--disable-perlinterp --disable-pythoninterp --disable-tclinterp"
.endif	# LITE

pre-build:
	@(cd ${WRKSRC}; ${MAKE} distclean)

post-install:
	[ -e ${PREFIX}/bin/gvim ] || (cd ${PREFIX}/bin ; ${LN} -sf vim gvim)
	#	below needed for `vim-lite' port
	test -e ${PREFIX}/bin/rgvim  || (cd ${PREFIX}/bin ; ${LN} -s vim rgvim) 
	test -e ${PREFIX}/bin/gview  || (cd ${PREFIX}/bin ; ${LN} -s vim gview)
	test -e ${PREFIX}/bin/rgview || (cd ${PREFIX}/bin ; ${LN} -s vim rgview)
	test -e ${PREFIX}/bin/evim   || (cd ${PREFIX}/bin ; ${LN} -s vim evim) 
	test -e ${PREFIX}/bin/eview  || (cd ${PREFIX}/bin ; ${LN} -s vim eview)
	test -e ${PREFIX}/bin/gvimdiff  \
		|| (cd ${PREFIX}/bin ; ${LN} -s vim gvimdiff)
	${INSTALL_DATA} ${FILESDIR}/vietnamese_viscii.vim ${DATADIR}/keymap
	cd ${PREFIX} ;\
	    find share/vim/${DISTNAME:S/-//:S/.//}/ -type f -o -type l	\
	    	| sort \
	    	>${WRKDIR}/PLIST.share-vim
	cd ${PREFIX} ;\
	    find share/vim/${DISTNAME:S/-//:S/.//}/ -type d \
	    	| sort -r | ${SED} -e 's/^/@dirrm /g' \
		>>${WRKDIR}/PLIST.share-vim
	${ECHO} "r ${TMPPLIST}"			> ${WRKDIR}/ex.script
	${ECHO} "/Insert PLIST.share-vim"	>> ${WRKDIR}/ex.script
	${ECHO} "d"				>> ${WRKDIR}/ex.script
	${ECHO} "r ${WRKDIR}/PLIST.share-vim"	>> ${WRKDIR}/ex.script
	${ECHO} "x!"				>> ${WRKDIR}/ex.script
	${CP} -p ${TMPPLIST} ${TMPPLIST}.pre-share-vim
	cd ${WRKDIR} ; ex < ex.script

.include <bsd.port.post.mk>
