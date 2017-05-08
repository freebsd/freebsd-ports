# Created by: stas
# $FreeBSD$

PORTNAME=	podofo
PORTVERSION=	0.9.5
CATEGORIES=	graphics print
MASTER_SITES=	SF

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	PDF manipulation library and tools

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libidn.so:dns/libidn

OPTIONS_DEFINE=	IMPOSE JPEG PNG TIFF
OPTIONS_DEFAULT=JPEG PNG TIFF
IMPOSE_DESC=	Build impose tool (Lua required)

CMAKE_ARGS=	-DOPENSSL_INCLUDE_DIR="${OPENSSLINC}" \
		-DOPENSSL_LIBRARIES="${OPENSSLDIR}" \
		-DPODOFO_BUILD_SHARED=TRUE \
		-DPODOFO_BUILD_STATIC=TRUE
USE_LDCONFIG=	yes
USES=		cmake compiler dos2unix ssl

DOS2UNIX_FILES=	cmake/modules/FindFREETYPE.cmake

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

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == gcc && ${COMPILER_VERSION} >= 50
CXXFLAGS+=	-std=gnu++11 -D_GLIBCXX_USE_C99=1
.endif

.include <bsd.port.post.mk>
