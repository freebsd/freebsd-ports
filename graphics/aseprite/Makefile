PORTNAME=		aseprite
DISTVERSIONPREFIX=	v
DISTVERSION=		1.3.18.3
CATEGORIES=		graphics

MAINTAINER=		yuri@FreeBSD.org
COMMENT=		Animated sprite editor and pixel art tool
WWW=		https://www.aseprite.org/

LICENSE=		EULA
LICENSE_NAME=		END-USER LICENSE AGREEMENT FOR ASEPRITE
LICENSE_FILE=		${WRKSRC}/EULA.txt
LICENSE_PERMS=		dist-mirror auto-accept

BROKEN_armv6=		fails to compile: undefined reference to __va_copy
BROKEN_armv7=		fails to compile: undefined reference to __va_copy

BUILD_DEPENDS=		skia124>0:graphics/skia124
LIB_DEPENDS=		libcmark.so:textproc/cmark \
			libcurl.so:ftp/curl \
			libGL.so:graphics/libglvnd \
			libfontconfig.so:x11-fonts/fontconfig \
			libfreetype.so:print/freetype2 \
			libgif.so:graphics/giflib \
			libharfbuzz.so:print/harfbuzz \
			libicuuc.so:devel/icu \
			libpixman-1.so:x11/pixman \
			libpng16.so:graphics/png \
			libXi.so:x11/libXi \
			libXrandr.so:x11/libXrandr

USES=			cmake compiler:c++17-lang gnome iconv:wchar_t jpeg \
			localbase:ldflags ninja pkgconfig ssl xorg
USE_GL=			gl
USE_XORG+=		xrandr
USE_GITHUB=		yes
GH_TUPLE=		aseprite:laf:1761fb8:laf/laf \
			aseprite:clip:964847c:clip \
			aseprite:googletest:155b337:googletest \
			aseprite:flic:a37fe2d:flic/src/flic \
			aseprite:observable:b21d07f:observable/src/observable \
			aseprite:psd:87af728:psd/src/psd \
			aseprite:tga:cd3420c:tga/src/tga \
			aseprite:undo:2209ac5:undo/src/undo \
			aseprite:IXWebSocket:89c9209:IXWebSocket/third_party/IXWebSocket \
			aseprite:TinyEXIF:21d6cf7:TinyEXIF/third_party/TinyEXIF \
			aseprite:benchmark:c58e6d0:benchmark/third_party/benchmark \
			aseprite:cityhash:e2a9a15:cityhash/third_party/cityhash \
			aseprite:cmark:9e2a654:cmark/third_party/cmark \
			aseprite:curl:09cf6fd:curl/third_party/curl \
			aseprite:fmt:f781d2b:fmt/third_party/fmt \
			aseprite:freetype2:66a04dd:freetype2/third_party/freetype2 \
			aseprite:giflib:94a7edb:giflib/third_party/giflib \
			aseprite:harfbuzz:d14c2d1:harfbuzz/third_party/harfbuzz \
			aseprite:json11:a4e1714:json11/third_party/json11 \
			aseprite:libarchive:7bde8b8:libarchive/third_party/libarchive \
			aseprite:libpng:34005e3:libpng/third_party/libpng \
			aseprite:libwebp:9ce5843:libwebp/third_party/libwebp \
			aseprite:lua:2a00e6b:lua/third_party/lua \
			aseprite:pixman:285b9a9:pixman/third_party/pixman \
			aseprite:qoi:c3dcfe7:qoi/third_party/qoi \
			aseprite:simpleini:9fa7622:simpleini/third_party/simpleini \
			aseprite:tinyexpr:24b9db0:tinyexpr/third_party/tinyexpr \
			aseprite:tinyxml2:312a809:tinyxml2/third_party/tinyxml2 \
			aseprite:zlib:51b7f2a:zlib/third_party/zlib
USE_GNOME=		libxml2
USE_XORG=		x11 xcb xcursor xext ice sm

CMAKE_ON=		USE_SHARED_CMARK \
			USE_SHARED_CURL \
			USE_SHARED_FREETYPE \
			USE_SHARED_GIFLIB \
			USE_SHARED_HARFBUZZ \
			USE_SHARED_LIBPNG \
			USE_SHARED_PIXMAN \
			USE_SHARED_ZLIB
CMAKE_OFF=		UPDATE_VERSION_WITH_GIT \
			ENABLE_UPDATER \
			ENABLE_NEWS \
			ENABLE_WEBP
CMAKE_ARGS=		-DLAF_BACKEND=skia \
			-DSKIA_DIR=${LOCALBASE}/include/aseprite-skia \
			-DSKIA_LIBRARY_DIR=${LOCALBASE}/lib/aseprite-skia \
			-DSKIA_LIBRARY=${LOCALBASE}/lib/aseprite-skia/libskia.a \
			-DVERSION=${PORTVERSION}

OPTIONS_DEFINE=		STEAM
OPTIONS_DEFAULT=

STEAM_DESC=		Compile with Steam library
STEAM_CMAKE_BOOL=	ENABLE_STEAM

CONFLICTS_BUILD=	skia

post-extract:
	@${RM} -rf ${WRKSRC}/laf/clip
	@${LN} -sf ${WRKDIR}/clip-964847c ${WRKSRC}/laf/clip
	@${RM} -rf ${WRKSRC}/laf/third_party/googletest
	@${LN} -sf ${WRKDIR}/googletest-155b337 ${WRKSRC}/laf/third_party/googletest

post-install:
	@cd ${STAGEDIR}${PREFIX} && ${RM} -r bin/bsd* include lib libdata share/man # see https://github.com/aseprite/aseprite/issues/1602

.include <bsd.port.mk>
