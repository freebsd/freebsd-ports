# ex:ts=8
# New ports collection makefile for:    vim
# Version required:     5.x
# Date created:         Sat June 29, 1996
# Whom:                 David O'Brien (obrien@cs.ucdavis.edu)
#
# $FreeBSD$
#

DISTNAME=	vim-5.4
PKGNAME?=	vim-5.4.49
CATEGORIES=	editors
MASTER_SITES=	ftp://nuxi.ucdavis.edu/pub/vim/unix/ \
		ftp://ftp.nuxi.com/pub/vim/unix/ \
		ftp://ftp.vim.org/pub/misc/vim/unix/  \
		ftp://ftp.prz.tu-berlin.de/pub/unix/editors/vim/unix/  \
		ftp://ftp.is.co.za/applications/editors/vim/  \
		ftp://ftp.progsoc.uts.edu.au/pub/vim/
DISTFILES=	${DISTNAME}-src${EXTRACT_SUFX} ${DISTNAME}-rt${EXTRACT_SUFX}

PATCH_SITES=	${MASTER_SITES:S/unix/patches/}
PATCHFILES=	5.4.1 5.4.2 5.4.3 5.4.4 5.4.5 5.4.6 5.4.7 5.4.8 5.4.9 5.4.10 \
		5.4.11 5.4.12 5.4.13 5.4.14 5.4.15 5.4.16 5.4.17 5.4.18 \
		5.4.19 5.4.20 5.4.21 5.4.22 5.4.23 5.4.24 5.4.25 5.4.26 5.4.27 \
		5.4.28 5.4.29 5.4.30 5.4.31 5.4.32 5.4.33 5.4.34 5.4.35 5.4.36 \
		5.4.37 5.4.38 5.4.39 5.4.40 5.4.41 5.4.42 5.4.43 5.4.44 5.4.45 \
		5.4.46 5.4.47 5.4.48 5.4.49

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

.if defined(HAVE_MOTIF)
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
MAKE_FLAGS:=	CONF_OPT_MAX="--enable-min-features" ${MAKE_FLAGS}
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
