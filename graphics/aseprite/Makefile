PORTNAME=		aseprite
DISTVERSION=		1.3.18.5
CATEGORIES=		graphics
MASTER_SITES=		https://github.com/aseprite/aseprite/releases/download/v${DISTVERSION}/
DISTNAME=		Aseprite-v${DISTVERSION}-Source

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
			localbase:ldflags ninja pkgconfig ssl xorg zip
USE_GL=			gl
USE_XORG+=		xrandr
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

NO_WRKSUBDIR=		yes

post-install:
	@cd ${STAGEDIR}${PREFIX} && ${RM} -r bin/bsd* include lib libdata share/man # see https://github.com/aseprite/aseprite/issues/1602

.include <bsd.port.mk>
