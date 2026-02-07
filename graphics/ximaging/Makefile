PORTNAME=	ximaging
DISTVERSIONPREFIX=	src-
DISTVERSION=	1.9
CATEGORIES=	graphics
MASTER_SITES=	https://fastestcode.org/dl/

MAINTAINER=	corlat@ermaion.com
COMMENT=	Image Viewer and Browser for Unix/X11
WWW=		https://fastestcode.org/ximaging.html

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libpng16.so:graphics/png \
		libtiff.so:graphics/tiff

USES=		jpeg motif tar:xz
USE_XORG=	x11 xinerama xt

PLIST_FILES=	bin/ximaging \
		etc/X11/app-defaults/XImaging \
		share/man/man1/ximaging.1.gz

.if !exists(/usr/include/omp.h)
USES+=		compiler:gcc-c++11-lib
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_MAN} ${WRKSRC}/src/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/X11/app-defaults
	${INSTALL_DATA} ${WRKSRC}/src/XImaging.ad \
		${STAGEDIR}${PREFIX}/etc/X11/app-defaults/XImaging

.include <bsd.port.mk>
