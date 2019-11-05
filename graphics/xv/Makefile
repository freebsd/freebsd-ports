# Created by: smace
# $FreeBSD$

PORTNAME=	xv
PORTVERSION=	3.10a
PORTREVISION=	16
CATEGORIES+=	graphics
MASTER_SITES=	ftp://ftp.cis.upenn.edu/pub/xv/:base \
		SF/png-mng/XV%20jumbo%20patches/20070520

DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:base \
		${DISTNAME}-jumbo-patches-20070520.tar.gz
DIST_SUBDIR=	${PORTNAME}

PATCH_SITES=	http://www.gregroelofs.com/code/
PATCHFILES=	xv-3.10a-enhancements.20070520-20081216.diff

MAINTAINER?=	dinoex@FreeBSD.org
COMMENT?=	X11 program that displays images of various formats

LIB_DEPENDS=	libtiff.so:graphics/tiff \
		libpng.so:graphics/png \
		libjasper.so:graphics/jasper

USES=		imake jpeg xorg
USE_XORG=	xext x11 xt

OPTIONS_DEFINE=	M17N DOCS
M17N_DESC=	build with Multilingualization support

.include <bsd.port.options.mk>

.if defined(CC) && ${CC:T:Mclang}
# Optimizer crashes with
# Assertion failed: (isPtrIV == IndVar->getType()->isPointerTy() && "IndVar type must match IVInit type")
CFLAGS:= ${CFLAGS:S/-O2//g}
.endif

.if ${PORT_OPTIONS:MM17N}
MAKE_ENV=	LOCALE_EXTENSION=-DTV_MULTILINGUAL
DESCR=	${FILESDIR}/pkg-descr
.endif

pre-patch:
	${PATCH} -d ${PATCH_WRKSRC} ${PATCH_ARGS} -p1 < ${WRKDIR}/xv-3.10a-jumbo-fix-enh-patch-20070520.txt

post-patch:
	${REINPLACE_CMD} -e "s@%%LOCALBASE%%@${LOCALBASE}@" \
		${WRKSRC}/config.h
.for i in bggen.1 vdcomp.1 xcmap.1 xv.1 xvp2p.1
	${CP} ${WRKSRC}/docs/${i:R}.man ${WRKSRC}
.endfor

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/README.jumbo ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/README.pcd ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/docs/epsf.ps ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/docs/xpm.ps ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/docs/xvdocs.ps ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/docs/xvtitle.ps ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/docs/help ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/docs/bmp.doc ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/docs/gif* ${STAGEDIR}${DOCSDIR}/
.endif

.include <bsd.port.mk>
