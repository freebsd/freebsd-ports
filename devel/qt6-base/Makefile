PORTNAME=	base
DISTVERSION=	${QT6_VERSION}
PORTREVISION=	2
CATEGORIES=	devel
PKGNAMEPREFIX=	qt6-

PATCH_SITES=	https://github.com/qt/qtbase/commit/
PATCHFILES=	3f45905953d57e0174059d7d9d6bc75c3c1c406c.patch:-p1

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt base (core, gui, widgets, network,...)
WWW=		https://www.qt.io/

BUILD_DEPENDS=	xml:textproc/xmlstarlet \
		${LOCALBASE}/include/vulkan/vulkan.h:graphics/vulkan-headers \
		${LOCALBASE}/include/linux/input.h:devel/evdev-proto
LIB_DEPENDS=	\
		libatk-1.0.so:accessibility/at-spi2-core \
		libatk-bridge-2.0.so:accessibility/at-spi2-core \
		libatspi.so:accessibility/at-spi2-core \
		libavahi-client.so:net/avahi-app \
		libbrotlidec.so:archivers/brotli \
		libdbus-1.so:devel/dbus \
		libdouble-conversion.so:devel/double-conversion \
		libdrm.so:graphics/libdrm \
		libepoll-shim.so:devel/libepoll-shim \
		libepoxy.so:graphics/libepoxy \
		libevdev.so:devel/libevdev \
		libexpat.so:textproc/expat2 \
		libffi.so:devel/libffi \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libfribidi.so:converters/fribidi \
		libgmp.so:math/gmp \
		libgnutls.so:security/gnutls \
		libgraphite2.so:graphics/graphite2 \
		libgudev-1.0.so:devel/libgudev \
		libharfbuzz.so:print/harfbuzz \
		libicui18n.so:devel/icu \
		libidn2.so:dns/libidn2 \
		libinput.so:x11/libinput \
		libintl.so:devel/gettext-runtime \
		libjpeg.so:graphics/jpeg-turbo \
		libmtdev.so:devel/libmtdev \
		libnettle.so:security/nettle \
		libp11-kit.so:security/p11-kit \
		libpcre.so:devel/pcre \
		libpcre2-16.so:devel/pcre2 \
		libpng16.so:graphics/png \
		libtasn1.so:security/libtasn1 \
		libudev.so:devel/libudev-devd \
		libunistring.so:devel/libunistring \
		libvulkan.so:graphics/vulkan-loader \
		libwacom.so:x11/libwacom \
		libwayland-client.so:graphics/wayland \
		libxkbcommon.so:x11/libxkbcommon \
		libzstd.so:archivers/zstd

USES=		cmake compiler:c++17-lang gl gnome jpeg perl5 pkgconfig python \
		qt-dist:6 shebangfix
USE_GL=		egl opengl
USE_GNOME=	cairo gdkpixbuf2 glib20 gtk30 pango
CMAKE_ON=	QT_AVOID_CMAKE_ARCHIVING_API \
		QT_FIND_ALL_PACKAGES_ALWAYS
CMAKE_OFF=	QT_FEATURE_eglfs \
		QT_FEATURE_gssapi
# sql drivers are handled in the qt6-base-sqldriver port
CMAKE_OFF+=	FEATURE_sql_mysql \
		FEATURE_sql_odbc \
		FEATURE_sql_psql \
		FEATURE_sql_sqlite

SHEBANG_FILES=	${WRKSRC}/mkspecs/features/uikit/device_destinations.sh \
		${WRKSRC}/mkspecs/features/uikit/devices.py \
		${WRKSRC}/mkspecs/features/data/mac/objc_namespace.sh \
		${WRKSRC}/util/android/android_emulator_launcher.sh \
		${WRKSRC}/util/testrunner/qt-testrunner.py
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

# zstd from base fails to compress files during the build (error 11: unsupported argument)
BINARY_ALIAS=	zstd=${LOCALBASE}/bin/zstd

OPTIONS_DEFINE=		CUPS X11
OPTIONS_DEFAULT=	CUPS X11
OPTIONS_SUB=		yes

CUPS_LIB_DEPENDS=	libcups.so:print/cups
CUPS_CMAKE_OFF=		-DFEATURE_cups=OFF

X11_USES=		xorg
X11_USE=		XORG=ice,pixman,sm,x11,xau,xcb,xcomposite,xcursor,xdamage,xdmcp,xext,xfixes,xi,xinerama,xrandr,xrender
X11_CMAKE_BOOL=		FEATURE_xcb FEATURE_xlib
X11_LIB_DEPENDS=	libxcb-cursor.so:x11/xcb-util-cursor \
			libxcb-icccm.so:x11/xcb-util-wm \
			libxcb-image.so:x11/xcb-util-image \
			libxcb-keysyms.so:x11/xcb-util-keysyms \
			libxcb-render-util.so:x11/xcb-util-renderutil \
			libxcb-util.so:x11/xcb-util

.include <bsd.port.pre.mk>

.if ${ARCH} == "armv6" || ${ARCH} == "armv7"
BUILD_DEPENDS+=	as:devel/binutils
CMAKE_ARGS+=	-DCMAKE_ASM_FLAGS=-no-integrated-as
.endif

# TODO: do this cleaner -- somewhere cmake/qmake still creates empty directories
# for the cmake files in INSTALL_PREFIX/lib/cmake
post-install:
	${RM} -vr ${STAGEDIR}${PREFIX}/${QT_LIBDIR_REL}/cmake
	# Install symlinks for user-facing tools
	${REINPLACE_CMD} -e "s#^#${STAGEDIR}#" -e "s# # ${STAGEDIR}#" \
		${WRKDIR}/.build/user_facing_tool_links.txt
	while read t; do \
		${RLN} $$t; \
	done <${WRKDIR}/.build/user_facing_tool_links.txt

.include <bsd.port.post.mk>
