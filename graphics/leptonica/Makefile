PORTNAME=	leptonica
DISTVERSION=	1.82.0
CATEGORIES=	graphics
MASTER_SITES=	https://github.com/DanBloomberg/${PORTNAME}/releases/download/${DISTVERSION}/ \
		http://www.${PORTNAME}.org/source/

PATCH_SITES=	https://github.com/DanBloomberg/leptonica/commit/
PATCHFILES=	b282ed9482e335439ccc429d4cd1dba517ba0c4d.patch:-p1

MAINTAINER=	hiroto.kagotani@gmail.com
COMMENT=	C library for efficient image processing and image analysis operations

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/leptonica-license.txt

USES=		cmake cpe localbase pkgconfig
USE_LDCONFIG=	yes

CONFLICTS=	leptonlib

CMAKE_ON=	BUILD_SHARED_LIBS

OPTIONS_DEFINE=		BIN GIF JPEG JPEG2000 PNG TIFF WEBP
OPTIONS_DEFAULT=	BIN GIF JPEG PNG TIFF WEBP
OPTIONS_SUB=		yes

BIN_DESC=		Build additional programs

BIN_CMAKE_BOOL=		BUILD_PROG
GIF_LIB_DEPENDS=	libgif.so:graphics/giflib
GIF_CMAKE_OFF=		CMAKE_DISABLE_FIND_PACKAGE_GIF:BOOL=True
JPEG2000_LIB_DEPENDS=	libopenjp2.so:graphics/openjpeg
JPEG2000_CMAKE_BOOL=	OPENJPEG_SUPPORT
JPEG_USES=		jpeg
JPEG_CMAKE_OFF=		CMAKE_DISABLE_FIND_PACKAGE_JPEG:BOOL=True
PNG_LIB_DEPENDS=	libpng.so:graphics/png
PNG_CMAKE_OFF=		CMAKE_DISABLE_FIND_PACKAGE_PNG:BOOL=True
TIFF_LIB_DEPENDS=	libtiff.so:graphics/tiff
TIFF_CMAKE_OFF=		CMAKE_DISABLE_FIND_PACKAGE_TIFF
WEBP_LIB_DEPENDS=	libwebp.so:graphics/webp
WEBP_CMAKE_BOOL=	LIBWEBP_SUPPORT

post-install:
	${RLN} ${STAGEDIR}${PREFIX}/lib/libleptonica.so.5.4.0 \
		${STAGEDIR}${PREFIX}/lib/liblept.so
	${RLN} ${STAGEDIR}${PREFIX}/lib/libleptonica.so.5.4.0 \
		${STAGEDIR}${PREFIX}/lib/liblept.so.5
	${RLN} ${STAGEDIR}${PREFIX}/lib/libleptonica.so.5.4.0 \
		${STAGEDIR}${PREFIX}/lib/liblept.so.5.4.0
	${MKDIR} ${STAGEDIR}${PREFIX}/share/cmake/Modules
	${INSTALL_DATA} ${WRKSRC}/cmake/FindLeptonica.cmake \
		${STAGEDIR}${PREFIX}/share/cmake/Modules/

.include <bsd.port.mk>
