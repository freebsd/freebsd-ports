PORTNAME=	wayland
DISTVERSION=	${QT6_VERSION}
PORTREVISION=	1
CATEGORIES=	graphics wayland
PKGNAMEPREFIX=	qt6-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt6 wrapper for Wayland
WWW=		https://qt-project.org

BUILD_DEPENDS=	${LOCALBASE}/include/vulkan/vulkan.h:graphics/vulkan-headers
LIB_DEPENDS=	libdouble-conversion.so:devel/double-conversion \
		libepoll-shim.so:devel/libepoll-shim \
		libexpat.so:textproc/expat2 \
		libffi.so:devel/libffi \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libgraphite2.so:graphics/graphite2 \
		libharfbuzz.so:print/harfbuzz \
		libicudata.so:devel/icu \
		libpcre.so:devel/pcre \
		libpcre2-16.so:devel/pcre2 \
		libpng16.so:graphics/png \
		libwayland-client.so:graphics/wayland \
		libxkbcommon.so:x11/libxkbcommon \
		libzstd.so:archivers/zstd

USES=		cmake compiler:c++17-lang gettext-runtime gl gnome pkgconfig xorg \
		qt-dist:6 xorg
USE_GL=		gl egl
USE_GNOME=	glib20
USE_QT=		base declarative
USE_XORG=	x11 xau xcb xcomposite xdmcp
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

.include <bsd.port.mk>
