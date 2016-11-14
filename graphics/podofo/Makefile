# Created by: stas
# $FreeBSD$

PORTNAME=	podofo
PORTVERSION=	0.9.4
PORTREVISION=	1
CATEGORIES=	graphics print
MASTER_SITES=	SF

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	PDF manipulation library and tools

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

LIB_DEPENDS=	libidn.so:dns/libidn \
		libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig

USES=		cmake compiler dos2unix ssl
CMAKE_ARGS=	-DPODOFO_BUILD_SHARED:BOOL=TRUE \
		-DPODOFO_BUILD_STATIC:BOOL=FALSE \
		-DOPENSSL_INCLUDE_DIR:PATH="${OPENSSLINC}" \
		-DOPENSSL_LIBRARIES:PATH="${OPENSSLDIR}"
USE_LDCONFIG=	yes
DOS2UNIX_FILES=	cmake/modules/FindFREETYPE.cmake

OPTIONS_DEFINE=		IMPOSE JPEG PNG TIFF
OPTIONS_DEFAULT=	JPEG PNG TIFF

IMPOSE_DESC=		Build impose tool (needs Lua)
IMPOSE_USES=		lua:51
IMPOSE_CMAKE_ON=	-DWANT_LUA:BOOL=TRUE
IMPOSE_CXXFLAGS=	-I${LUA_INCDIR}
IMPOSE_LDFLAGS=		-L${LUA_LIBDIR}

JPEG_CMAKE_ON=		-DWANT_LIBJPEG:BOOL=TRUE
JPEG_USES=		jpeg

PNG_CMAKE_ON=		-DWANT_PNG:BOOL=TRUE
PNG_LIB_DEPENDS=	libpng.so:graphics/png

TIFF_CMAKE_ON=		-DWANT_TIFF:BOOL=TRUE
TIFF_LIB_DEPENDS=	libtiff.so:graphics/tiff

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == gcc && ${COMPILER_VERSION} >= 50
CXXFLAGS+=	-std=gnu++11 -D_GLIBCXX_USE_C99=1
.endif

.include <bsd.port.post.mk>
