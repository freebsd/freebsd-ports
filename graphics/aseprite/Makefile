# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=		aseprite
PORTVERSION=		1.1.5.6
DISTVERSIONPREFIX=	v
CATEGORIES=		graphics

MAINTAINER=		yuri@rawbw.com
COMMENT=		Animated sprite editor & pixel art tool

LICENSE=		GPLv2
LICENSE_FILE=		${WRKSRC}/LICENSE.txt

EXTRACT_DEPENDS=	${NONEXISTENT}:x11/pixman:extract
LIB_DEPENDS=		libfreetype.so:print/freetype2 \
			liballeg.so:devel/allegro \
			libpng.so:graphics/png \
			libgif.so:graphics/giflib \
			libcurl.so:ftp/curl \
			libtinyxml.so:textproc/tinyxml

BROKEN_FreeBSD_9=	Fails due to compiler issues

OPTIONS_DEFINE=		WEBP
OPTIONS_DEFAULT=	WEBP

WEBP_LIB_DEPENDS=	libwebp.so:graphics/webp

USE_GITHUB=		yes
GH_TUPLE=		aseprite:aseprite:b659747
GH_TUPLE+=		aseprite:flic:da184cb:flic
GH_TUPLE+=		aseprite:gtest:d63c625:gtest
GH_TUPLE+=		aseprite:simpleini:d4a436a:simpleini
GH_TUPLE+=		aseprite:duktape:90090c7:duk

USES=			cmake:outsource compiler:c++11-lib jpeg pkgconfig
USE_XORG=		x11 xcursor xext xpm ice pixman sm xxf86dga xxf86vm

CMAKE_ARGS+=		-DUSE_SHARED_ALLEGRO4=1
CMAKE_ARGS+=		-DUSE_SHARED_GIFLIB=1
CMAKE_ARGS+=		-DUSE_SHARED_ZLIB=1
CMAKE_ARGS+=		-DUSE_SHARED_JPEGLIB=1
CMAKE_ARGS+=		-DUSE_SHARED_LIBPNG=1
WEBP_CMAKE_ON+=		-DWITH_WEBP_SUPPORT=1
WEBP_CMAKE_ON+=		-DUSE_SHARED_LIBWEBP=1
CMAKE_ARGS+=		-DUSE_SHARED_FREETYPE=1
CMAKE_ARGS+=		-DUSE_SHARED_PIXMAN=1
CMAKE_ARGS+=		-DUSE_SHARED_CURL=1
CMAKE_ARGS+=		-DUSE_SHARED_TINYXML=1
CMAKE_ARGS+=		-DFREETYPE_INCLUDE_DIR=${LOCALBASE}/include/freetype2
CXXFLAGS+=		-I${LOCALBASE}/include
CXXFLAGS+=		-I${LOCALBASE}/include/freetype2
CXXFLAGS+=		-I${LOCALBASE}/include/freetype2/freetype

post-extract:
	@${RMDIR} ${WRKSRC}/src/flic ${WRKSRC}/third_party/gtest ${WRKSRC}/third_party/simpleini ${WRKSRC}/third_party/duktape
	@${MV} ${WRKDIR}/flic-* ${WRKSRC}/src/flic
	@${MV} ${WRKDIR}/gtest-* ${WRKSRC}/third_party/gtest
	@${MV} ${WRKDIR}/simpleini-* ${WRKSRC}/third_party/simpleini
	@${MV} ${WRKDIR}/duktape-* ${WRKSRC}/third_party/duktape
	@${MKDIR} ${WRKSRC}/third_party/pixman/pixman
	@${CP} `${MAKE} -C ${PORTSDIR}/x11/pixman -V WRKSRC`/pixman/pixman-combine32.h \
		${WRKSRC}/third_party/pixman/pixman/

post-configure:
	@${REINPLACE_CMD} -e 's|-lXxf86dga |-L${LOCALBASE}/lib -lXxf86dga |g' \
		`find ${WRKDIR} -name link.txt`
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/src/app/resource_finder.cpp

.include <bsd.port.mk>
