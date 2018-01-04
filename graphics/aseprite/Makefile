# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=		aseprite
DISTVERSIONPREFIX=	v
DISTVERSION=		1.2.6
CATEGORIES=		graphics

MAINTAINER=		yuri@FreeBSD.org
COMMENT=		Animated sprite editor & pixel art tool

LICENSE=		EULA
LICENSE_NAME=		END-USER LICENSE AGREEMENT FOR ASEPRITE
LICENSE_FILE=		${WRKSRC}/EULA.txt
LICENSE_PERMS=		dist-mirror pkg-mirror auto-accept

EXTRACT_DEPENDS=	${NONEXISTENT}:x11/pixman:extract
LIB_DEPENDS=		liballeg.so:devel/allegro \
			libcmark.so:textproc/cmark \
			libcurl.so:ftp/curl \
			libgif.so:graphics/giflib \
			libharfbuzz-icu.so:print/harfbuzz-icu \
			liblz4.so:archivers/liblz4 \
			libnettle.so:security/nettle \
			libpng.so:graphics/png \
			libtinyxml.so:textproc/tinyxml

BROKEN_aarch64=		fails to compile: undefined reference to __va_copy
BROKEN_armv6=		fails to compile: undefined reference to __va_copy
BROKEN_armv7=		fails to compile: undefined reference to __va_copy
BROKEN_powerpc64=	fails to compile: arena.h: Failed assertion: "arena_mapbits_allocated_get(chunk, pageind) != 0"
BROKEN_sparc64=		fails to compile: vsnprintf is not a member of std

OPTIONS_DEFINE=		WEBP
OPTIONS_DEFAULT=	WEBP

WEBP_LIB_DEPENDS=	libwebp.so:graphics/webp

USES=			cmake:outsource compiler:c++11-lib iconv:wchar_t jpeg localbase:ldflags pkgconfig ssl
USE_GITHUB=		yes
GH_TUPLE=		aseprite:libarchive:687e298:libarchive/third_party/libarchive
GH_TUPLE+=		aseprite:clip:361f687:clip/src/clip
GH_TUPLE+=		aseprite:flic:65a6072:flic/src/flic
GH_TUPLE+=		aseprite:fmt:933a33a:fmt/third_party/fmt
GH_TUPLE+=		aseprite:freetype2:8529e84:freetype2/third_party/freetype2 # https://github.com/aseprite/aseprite/issues/1601
GH_TUPLE+=		aseprite:gtest:d63c625:gtest/third_party/gtest
GH_TUPLE+=		aseprite:harfbuzz:681b0bc:harfbuzz/third_party/harfbuzz
GH_TUPLE+=		aseprite:json11:ed35a09:json11/third_party/json11
GH_TUPLE+=		aseprite:laf:9ed243c:laf/laf
GH_TUPLE+=		aseprite:mujs:81388eb:mujs/third_party/mujs
GH_TUPLE+=		aseprite:observable:f9a56dc:observable/src/observable
GH_TUPLE+=		aseprite:simpleini:0687587:simpleini/third_party/simpleini
GH_TUPLE+=		aseprite:stringencoders:f963507:stringencoders/laf/third_party/stringencoders
GH_TUPLE+=		aseprite:undo:f17044a:undo/src/undo
USE_GNOME=		libxml2
USE_XORG=		x11 xcursor xext xpm ice pixman sm xxf86dga xxf86vm
USE_LDCONFIG=		yes

CMAKE_ARGS=		-DUSE_SHARED_ALLEGRO4:BOOL=ON \
			-DUSE_SHARED_CMARK:BOOL=ON \
			-DUSE_SHARED_CURL:BOOL=ON \
			-DUSE_SHARED_GIFLIB:BOOL=ON \
			-DUSE_SHARED_JPEGLIB:BOOL=ON \
			-DUSE_SHARED_LIBPNG:BOOL=ON \
			-DUSE_SHARED_PIXMAN:BOOL=ON \
			-DUSE_SHARED_TINYXML:BOOL=ON \
			-DUSE_SHARED_ZLIB:BOOL=ON
CMAKE_ARGS+=		-DUSE_SHARED_FREETYPE:BOOL=OFF # needs files internal to freetype2
WEBP_CMAKE_BOOL=	USE_SHARED_LIBWEBP
WEBP_CMAKE_ON=		-DWITH_WEBP_SUPPORT=1
CXXFLAGS+=		-I${LOCALBASE}/include/freetype2
CXXFLAGS+=		-I${LOCALBASE}/include/freetype2/freetype
CXXFLAGS+=		-D_GLIBCXX_USE_C99 # XXX ports/193528

post-extract:
	@${RM} -r ${WRKSRC}/src/allegro
	@${MKDIR} ${WRKSRC}/third_party/pixman/pixman
	@${CP} `${MAKE} -C ${PORTSDIR}/x11/pixman -V WRKSRC`/pixman/pixman-combine32.h \
		${WRKSRC}/third_party/pixman/pixman/

post-patch:
	@${REINPLACE_CMD} -e 's|1.3-dev|${PORTVERSION}|' ${WRKSRC}/src/config.h ${WRKSRC}/data/gui.xml

post-install:
	@cd ${STAGEDIR}${PREFIX} && ${RM} -r bin/bsd* include lib libdata share/man # see https://github.com/aseprite/aseprite/issues/1602

.include <bsd.port.mk>
