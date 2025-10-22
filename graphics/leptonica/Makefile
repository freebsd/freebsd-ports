PORTNAME=	leptonica
DISTVERSION=	1.86.0
CATEGORIES=	graphics
MASTER_SITES=	https://github.com/user-attachments/files/22412990/ \
		http://www.${PORTNAME}.org/source/

PATCH_SITES=   https://github.com/DanBloomberg/leptonica/commit/
PATCHFILES=    e0936377f9094b72f7f2ea6bc34311ccc69b2f71.patch:-p1

MAINTAINER=	hiroto.kagotani@gmail.com
COMMENT=	C library for efficient image processing and image analysis operations
WWW=		http://www.leptonica.org/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/leptonica-license.txt

USES=		cmake cpe localbase pathfix pkgconfig
USE_LDCONFIG=	yes

CONFLICTS=	leptonlib

CMAKE_ON=	BUILD_SHARED_LIBS

OPTIONS_DEFINE=		BIN GIF JPEG JPEG2000 PNG TIFF WEBP
OPTIONS_DEFAULT=	BIN GIF JPEG PNG TIFF WEBP
OPTIONS_SUB=		yes

BIN_DESC=		Build additional programs

BIN_CMAKE_BOOL=		BUILD_PROG

GIF_LIB_DEPENDS=	libgif.so:graphics/giflib
GIF_CMAKE_BOOL=		ENABLE_GIF

JPEG2000_LIB_DEPENDS=	libopenjp2.so:graphics/openjpeg
JPEG2000_CMAKE_BOOL=	ENABLE_OPENJPEG

JPEG_USES=		jpeg
JPEG_CMAKE_BOOL=	ENABLE_JPEG

PNG_LIB_DEPENDS=	libpng.so:graphics/png
PNG_CMAKE_BOOL=		ENABLE_PNG

TIFF_LIB_DEPENDS=	libtiff.so:graphics/tiff
TIFF_CMAKE_BOOL=	ENABLE_TIFF

WEBP_LIB_DEPENDS=	libwebp.so:graphics/webp
WEBP_CMAKE_BOOL=	ENABLE_WEBP

post-install:
	${RLN} ${STAGEDIR}${PREFIX}/lib/libleptonica.so.6.0.0 \
		${STAGEDIR}${PREFIX}/lib/liblept.so
	${RLN} ${STAGEDIR}${PREFIX}/lib/libleptonica.so.6.0.0 \
		${STAGEDIR}${PREFIX}/lib/liblept.so.6
	${RLN} ${STAGEDIR}${PREFIX}/lib/libleptonica.so.6.0.0 \
		${STAGEDIR}${PREFIX}/lib/liblept.so.6.0.0
	${MKDIR} ${STAGEDIR}${PREFIX}/share/cmake/Modules
	${INSTALL_DATA} ${WRKSRC}/cmake/FindLeptonica.cmake \
		${STAGEDIR}${PREFIX}/share/cmake/Modules/

.include <bsd.port.mk>
