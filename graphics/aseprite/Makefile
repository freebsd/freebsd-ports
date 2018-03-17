# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=		aseprite
DISTVERSIONPREFIX=	v
DISTVERSION=		1.2.7.2
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
			libfreetype.so:print/freetype2 \
			libgif.so:graphics/giflib \
			libharfbuzz.so:print/harfbuzz \
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

USES=			cmake:outsource compiler:c++11-lib iconv:wchar_t jpeg localbase:ldflags pkgconfig ssl
USE_GITHUB=		yes
GH_TUPLE=		aseprite:libarchive:687e298:libarchive/third_party/libarchive
GH_TUPLE+=		aseprite:clip:b26bf0c:clip/src/clip
GH_TUPLE+=		aseprite:flic:65a6072:flic/src/flic
GH_TUPLE+=		aseprite:fmt:933a33a:fmt/third_party/fmt
GH_TUPLE+=		aseprite:json11:ed35a09:json11/third_party/json11
GH_TUPLE+=		aseprite:laf:0246ba5:laf/laf
GH_TUPLE+=		aseprite:mujs:81388eb:mujs/third_party/mujs
GH_TUPLE+=		aseprite:observable:f9a56dc:observable/src/observable
GH_TUPLE+=		aseprite:simpleini:0687587:simpleini/third_party/simpleini
GH_TUPLE+=		aseprite:stringencoders:f963507:stringencoders/laf/third_party/stringencoders
GH_TUPLE+=		aseprite:undo:faf19f0:undo/src/undo
USE_GNOME=		libxml2
USE_XORG=		x11 xcursor xext xpm ice pixman sm xxf86dga xxf86vm

CMAKE_ON=		USE_SHARED_ALLEGRO4 \
			USE_SHARED_CMARK \
			USE_SHARED_CURL \
			USE_SHARED_FREETYPE \
			USE_SHARED_GIFLIB \
			USE_SHARED_HARFBUZZ \
			USE_SHARED_JPEGLIB \
			USE_SHARED_LIBPNG \
			USE_SHARED_PIXMAN \
			USE_SHARED_TINYXML \
			USE_SHARED_ZLIB

CXXFLAGS+=		-D_GLIBCXX_USE_C99 # XXX ports/193528

OPTIONS_DEFINE=		STEAM WEBP
OPTIONS_DEFAULT=	WEBP

STEAM_DESC=		Compile with Steam library
STEAM_CMAKE_BOOL=	ENABLE_STEAM

WEBP_CMAKE_BOOL=	USE_SHARED_LIBWEBP
WEBP_CMAKE_ON=		-DWITH_WEBP_SUPPORT=1
WEBP_LIB_DEPENDS=	libwebp.so:graphics/webp

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
