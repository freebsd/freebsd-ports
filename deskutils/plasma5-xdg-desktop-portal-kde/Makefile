PORTNAME=	xdg-desktop-portal-kde
DISTVERSION=	${KDE_PLASMA_VERSION}.1
CATEGORIES=	deskutils kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Backend implementation for xdg-desktop-portal
WWW=		https://kde.org/plasma-desktop/

BUILD_DEPENDS=	wayland-protocols>0:graphics/wayland-protocols \
		${LOCALBASE}/include/linux/input-event-codes.h:devel/evdev-proto
LIB_DEPENDS=	libwayland-client.so:graphics/wayland \
		libxkbcommon.so:x11/libxkbcommon

USES=		cmake gl kde:5 pkgconfig qt:5 tar:xz xorg
USE_GL=		gl
USE_KDE=	auth bookmarks codecs completion config configwidgets \
		coreaddons globalaccel guiaddons i18n iconthemes itemviews \
		jobwidgets kdeclarative kio kirigami2 notifications package \
		plasma-framework service solid wayland widgetsaddons \
		windowsystem xmlgui \
		ecm:build plasma-wayland-protocols:build
USE_QT=		concurrent core dbus declarative gui network printsupport \
		wayland widgets xml \
		buildtools:build qmake:build
USE_XORG=	x11

.include <bsd.port.mk>
