PORTNAME=	podofo
PORTVERSION=	0.9.8
CATEGORIES=	graphics print
MASTER_SITES=	SF

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	PDF manipulation library and tools

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libidn.so:dns/libidn

USES=		cmake compiler:c++11-lang cpe dos2unix pkgconfig ssl

CMAKE_ARGS=	-DFONTCONFIG_LIBRARIES=${LOCALBASE}/lib/libfontconfig.so \
		-DOPENSSL_INCLUDE_DIR=${OPENSSLINC} \
		-DOPENSSL_LIBRARIES=${OPENSSLDIR}
CMAKE_ON=	PODOFO_BUILD_SHARED PODOFO_BUILD_STATIC
USE_LDCONFIG=	yes

CPE_VENDOR=	podofo_project

DOS2UNIX_FILES=	cmake/modules/FindFREETYPE.cmake

OPTIONS_DEFINE=	IMPOSE JPEG PNG TIFF
OPTIONS_DEFAULT=JPEG PNG TIFF
IMPOSE_DESC=	Build impose tool (Lua required)

IMPOSE_CMAKE_BOOL=	WANT_LUA
IMPOSE_CXXFLAGS=	-I${LUA_INCDIR}
IMPOSE_LDFLAGS=		-L${LUA_LIBDIR}
IMPOSE_USES=		lua
JPEG_CMAKE_BOOL=	WANT_LIBJPEG
JPEG_USES=		jpeg
PNG_CMAKE_BOOL=		WANT_PNG
PNG_LIB_DEPENDS=	libpng.so:graphics/png
TIFF_CMAKE_BOOL=	WANT_TIFF
TIFF_LIB_DEPENDS=	libtiff.so:graphics/tiff

.include <bsd.port.mk>
