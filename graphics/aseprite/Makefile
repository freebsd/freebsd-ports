# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=		aseprite
PORTVERSION=		1.1.13
DISTVERSIONPREFIX=	v
PORTREVISION=		3
CATEGORIES=		graphics

MAINTAINER=		yuri@rawbw.com
COMMENT=		Animated sprite editor & pixel art tool

LICENSE=		EULA
LICENSE_NAME=		END-USER LICENSE AGREEMENT FOR ASEPRITE
LICENSE_FILE=		${WRKSRC}/EULA.txt
LICENSE_PERMS=		dist-mirror pkg-mirror auto-accept

EXTRACT_DEPENDS=	${NONEXISTENT}:x11/pixman:extract
LIB_DEPENDS=		libfreetype.so:print/freetype2 \
			liballeg.so:devel/allegro \
			libpng.so:graphics/png \
			libgif.so:graphics/giflib \
			libcurl.so:ftp/curl \
			libtinyxml.so:textproc/tinyxml

BROKEN_aarch64=		fails to compile: undefined reference to __va_copy
BROKEN_armv6=		fails to compile: undefined reference to __va_copy
BROKEN_powerpc64=	fails to compile: arena.h: Failed assertion: "arena_mapbits_allocated_get(chunk, pageind) != 0"
BROKEN_sparc64=		fails to compile: vsnprintf is not a member of std

OPTIONS_DEFINE=		WEBP
OPTIONS_DEFAULT=	WEBP

WEBP_LIB_DEPENDS=	libwebp.so:graphics/webp

USE_GITHUB=		yes
GH_TUPLE=		aseprite:clip:926e3cf:clip/src/clip
GH_TUPLE+=		aseprite:flic:65a6072:flic/src/flic
GH_TUPLE+=		aseprite:gtest:d63c625:gtest/third_party/gtest
GH_TUPLE+=		aseprite:cmark:5255e2d:cmark/third_party/cmark
GH_TUPLE+=		aseprite:simpleini:0687587:simpleini/third_party/simpleini
GH_TUPLE+=		aseprite:duktape:0de771c:duktape/third_party/duktape
GH_TUPLE+=		aseprite:undo:f39b188:undo/src/undo
GH_TUPLE+=		aseprite:laf:e6d79aa:laf/laf
GH_TUPLE+=		aseprite:stringencoders:f963507:stringencoders/laf/third_party/stringencoders
GH_TUPLE+=		dacap:observable:27fa7f6:observable/src/observable

USES=			cmake:outsource compiler:c++11-lib jpeg pkgconfig
USE_XORG=		x11 xcursor xext xpm ice pixman sm xxf86dga xxf86vm
USE_LDCONFIG=		yes

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
CXXFLAGS+=		-D_GLIBCXX_USE_C99 # XXX ports/193528

post-extract:
	@${RM} -r ${WRKSRC}/src/allegro
	@${MKDIR} ${WRKSRC}/third_party/pixman/pixman
	@${CP} `${MAKE} -C ${PORTSDIR}/x11/pixman -V WRKSRC`/pixman/pixman-combine32.h \
		${WRKSRC}/third_party/pixman/pixman/
	@${REINPLACE_CMD} -e 's|$${LIB_INSTALL_DIR}/pkgconfig|${PREFIX}/libdata/pkgconfig|' \
		${WRKDIR}/cmark-*/src/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|$${CMAKE_INSTALL_MANDIR}|${PREFIX}/man|' \
		${WRKDIR}/cmark-*/man/CMakeLists.txt

post-patch:
	@${REINPLACE_CMD} -e 's|1.1.6-dev|${PORTVERSION}|' ${WRKSRC}/src/config.h ${WRKSRC}/data/gui.xml

.include <bsd.port.mk>
