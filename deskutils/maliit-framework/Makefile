PORTNAME=	framework
DISTVERSION=	2.1.1
CATEGORIES=	deskutils kde
PKGNAMEPREFIX=	maliit-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Core libraries of Maliit and server

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto \
		wayland-protocols>0:graphics/wayland-protocols
LIB_DEPENDS=	libharfbuzz.so:print/harfbuzz \
		libudev.so:devel/libudev-devd \
		libwayland-client.so:graphics/wayland \
		libxkbcommon.so:x11/libxkbcommon

USES=		cmake compiler:c++11-lang gnome pkgconfig qt:5 xorg
USE_GITHUB=	yes
GH_ACCOUNT=	maliit
USE_GNOME=	atk cairo gdkpixbuf2 glib20 gtk30 pango
USE_QT=		core dbus declarative gui network wayland widgets \
		buildtools_build qmake_build
USE_XORG=	xcb

CMAKE_ON=	enable-dbus-activation \
		enable-wayland-gtk
CMAKE_OFF=	enable-tests \
		enable-docs

BINARY_ALIAS=	qtwaylandscanner=${QT_BINDIR}/qtwaylandscanner

.include <bsd.port.mk>
