PORTNAME=	xdg-desktop-portal-kde
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	deskutils kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Backend implementation for xdg-desktop-portal that is using Qt/KDE

BUILD_DEPENDS=	${LOCALBASE}/include/linux/input-event-codes.h:devel/evdev-proto \
		wayland-protocols>=0:graphics/wayland-protocols

USES=		cmake gettext kde:6 pkgconfig qt:6 tar:xz
USE_KDE=	config coreaddons globalaccel guiaddons i18n iconthemes kio \
		kirigami2 notifications statusnotifieritem wayland \
		widgetsaddons windowsystem \
		ecm:build plasma-wayland-protocols:build
USE_QT=		base declarative wayland

CMAKE_ARGS=	-DQT_MAJOR_VERSION=6

.include <bsd.port.mk>
