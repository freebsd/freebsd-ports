# ex:ts=8
# New ports collection makefile for:    vim
# Version required:     5.x
# Date created:         Sat June 29, 1996
# Whom:                 David O'Brien (obrien@cs.ucdavis.edu)
#
# $FreeBSD$
#

PKGVER=		5.5.67
DISTNAME=	vim-5.5
PKGNAME?=	vim-${PKGVER}
CATEGORIES=	editors
MASTER_SITES=	ftp://nuxi.ucdavis.edu/pub/vim/unix/ \
		ftp://ftp.nuxi.com/pub/vim/unix/ \
		ftp://ftp.vim.org/pub/misc/vim/unix/  \
		ftp://ftp.prz.tu-berlin.de/pub/unix/editors/vim/unix/  \
		ftp://ftp.is.co.za/applications/editors/vim/  \
		ftp://ftp.progsoc.uts.edu.au/pub/vim/
DISTFILES=	${DISTNAME}-src${EXTRACT_SUFX} ${DISTNAME}-rt${EXTRACT_SUFX}

PATCH_SITES=	${MASTER_SITES:S/unix/patches/}
.for p in 01 02 03 04 05 06 08 09 11 12 13 14 15 17 18 19 20 21 22 23 25 26 27 29 30 32 33 34 35 36 37 38 39 40 41 42 43 44 45 47 48 49 50 51 52 53 54 55 56 57 58 59 61 63 64 65 66 67
PATCHFILES+=	5.5.0${p}
.endfor

MAINTAINER=     obrien@FreeBSD.org

Y2K=		http://www.vim.org/y2k.html

.if defined(PACKAGE_BUILDING) && !defined(LITE)
BUILD_DEPENDS=	tclsh8.0:${PORTSDIR}/lang/tcl80
LIB_DEPENDS=	tcl80.1:${PORTSDIR}/lang/tcl80
USE_PERL5=	yes
.endif

DIST_SUBDIR=	vim
WRKSRC=		${WRKDIR}/${DISTNAME}/src
PATCH_DIST_ARGS=	-d ${WRKDIR}/${DISTNAME} --forward --quiet -E ${PATCH_DIST_STRIP}
MAKE_FLAGS=	CONF_ARGS="--prefix=${PREFIX} --with-tlib=termlib" -f
ALL_TARGET=	#
PLIST_SUB=	VIM_VER=${DISTNAME:S/-//:S/.//}
MAN1=		vim.1 vimtutor.1 xxd.1 ectags.1
MLINKS=		vim.1 rvim.1  vim.1 rview.1  ectags.1 etags.1

.if !defined(LITE)
MLINKS+=	vim.1 gvim.1  vim.1 gview.1  vim.1 rgvim.1  vim.1 rgview.1

MAKE_FLAGS:=	CONF_OPT_MAX="--enable-max-features" ${MAKE_FLAGS}

.if defined(HAVE_GTK)
LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12
MAKE_FLAGS:=	CONF_OPT_GUI="--enable-gui=gtk --with-gtk-prefix=${X11BASE} --enable-multibyte --enable-fontset --enable-multibyte --enable-xim" ${MAKE_FLAGS}
.elif defined(HAVE_MOTIF)
REQUIRES_MOTIF=	yes
MAKE_FLAGS:=	CONF_OPT_GUI="--enable-gui=motif --with-motif-lib=\"${MOTIFLIB}\"" MOTIFHOME=${X11BASE} ${MAKE_FLAGS}
.else
MAKE_FLAGS:=	CONF_OPT_GUI="--enable-gui=athena" ${MAKE_FLAGS}
.endif

.if defined(PACKAGE_BUILDING)
MAKE_FLAGS:=	CONF_OPT_PERL="--enable-perlinterp --enable-tclinterp --enable-cscope" ${MAKE_FLAGS}
.endif

.else	# LITE
PLIST=		${WRKDIR}/PLIST.nogui
MAKE_FLAGS:=	CONF_OPT_GUI="--enable-gui=no --without-x" ${MAKE_FLAGS}
MAKE_FLAGS:=	CONF_OPT_PERL="--disable-perlinterp --disable-tclinterp" ${MAKE_FLAGS}
.endif	# LITE

pre-build:
	@(cd ${WRKSRC}; ${MAKE} distclean)
	@${SED} -e '/gvi/d' ${PKGDIR}/PLIST > ${WRKDIR}/PLIST.nogui

post-install:
.if !defined(LITE)
	[ -e ${PREFIX}/bin/gvim ] || ${LN} -s ${PREFIX}/bin/vim ${PREFIX}/bin/gvim
.endif
	@${RM} -f ${PREFIX}/man/man1/etags.1
	@${MV} ${PREFIX}/man/man1/ctags.1 ${PREFIX}/man/man1/ectags.1

.include <bsd.port.mk>
