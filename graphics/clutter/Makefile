PORTNAME=	clutter
DISTVERSION=	1.26.4
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	OpenGL based interactive canvas library
WWW=		https://clutter-project.org/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto
LIB_DEPENDS=	libjson-glib-1.0.so:devel/json-glib \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libcogl.so:graphics/cogl \
		libharfbuzz.so:print/harfbuzz \
		libxkbcommon.so:x11/libxkbcommon \
		libwayland-client.so:graphics/wayland \
		libgudev-1.0.so:devel/libgudev \
		libinput.so:x11/libinput

PORTSCOUT=	limit:1,even

USES=		cpe gettext gl gmake gnome libtool localbase pathfix pkgconfig \
		tar:xz xorg
USE_GNOME=	atk cairo gdkpixbuf pango introspection:build gtk30
USE_GL=		egl
USE_XORG=	x11 xcomposite xdamage xext xfixes xi xrandr
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--with-x --enable-conformance=no \
		--enable-evdev-input \
		--enable-egl-backend=yes \
		--enable-x11-backend=yes \
		--enable-gdk-backend=yes \
		--enable-wayland-backend=yes \
		--enable-wayland-compositor=no
INSTALL_TARGET=	install-strip
CPE_VENDOR=	clutter_project

.include <bsd.port.mk>
