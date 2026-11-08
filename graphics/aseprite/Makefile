PORTNAME=		aseprite
DISTVERSION=		1.3.18.6
CATEGORIES=		graphics
MASTER_SITES=		https://github.com/aseprite/aseprite/releases/download/v${DISTVERSION}/
DISTNAME=		Aseprite-v${DISTVERSION}-Source

MAINTAINER=		yuri@FreeBSD.org
COMMENT=		Animated sprite editor and pixel art tool
WWW=			https://www.aseprite.org/ \
			https://github.com/aseprite/aseprite

LICENSE=		EULA
LICENSE_NAME=		END-USER LICENSE AGREEMENT FOR ASEPRITE
LICENSE_FILE=		${WRKSRC}/EULA.txt
LICENSE_PERMS=		dist-mirror auto-accept

BROKEN_armv6=		fails to compile: undefined reference to __va_copy
BROKEN_armv7=		fails to compile: undefined reference to __va_copy

BUILD_DEPENDS=		skia124>0:graphics/skia124
LIB_DEPENDS=		libcmark.so:textproc/cmark \
			libGL.so:graphics/libglvnd \
			libfontconfig.so:x11-fonts/fontconfig \
			libfreetype.so:print/freetype2 \
			libgif.so:graphics/giflib \
			libharfbuzz.so:print/harfbuzz \
			libicuuc.so:devel/icu \
			libpixman-1.so:x11/pixman \
			libpng16.so:graphics/png

USES=			cmake compiler:c++17-lang jpeg \
			localbase:ldflags ninja pkgconfig ssl xorg
USE_GL=			gl
USE_XORG=		ice sm x11 xcb xcursor xext xi xrandr

EXTRACT_SUFX=		.zip
EXTRACT_AFTER_ARGS=	--exclude third_party/cmark \
			--exclude third_party/curl \
			--exclude third_party/freetype2 \
			--exclude third_party/giflib \
			--exclude third_party/harfbuzz \
			--exclude third_party/libpng \
			--exclude third_party/pixman-cmake \
			--exclude third_party/libwebp \
			--exclude third_party/zlib \
			--no-same-owner --no-same-permissions

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

STEAM_DESC=		Compile with Steam library
STEAM_CMAKE_BOOL=	ENABLE_STEAM

CONFLICTS_BUILD=	skia

NO_WRKSUBDIR=		yes

post-install:
	@cd ${STAGEDIR}${PREFIX} && ${RM} -r bin/bsd* include lib libdata share/man # see https://github.com/aseprite/aseprite/issues/1602

.include <bsd.port.mk>
