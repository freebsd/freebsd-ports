PORTNAME=	xdg-desktop-portal-kde
DISTVERSION=	${KDE_PLASMA_VERSION}
PORTREVISION=	1
CATEGORIES=	deskutils kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Backend implementation for xdg-desktop-portal that is using Qt/KDE

BUILD_DEPENDS=	${LOCALBASE}/include/linux/input-event-codes.h:devel/evdev-proto \
		wayland-protocols>=0:graphics/wayland-protocols
LIB_DEPENDS=	libwayland-client.so:graphics/wayland \
		libxkbcommon.so:x11/libxkbcommon

USES=		cmake gettext gl kde:6 pkgconfig qt:6 tar:xz xorg
USE_KDE=	bookmarks completion config coreaddons globalaccel guiaddons \
		i18n iconthemes itemviews jobwidgets kio kirigami2 \
		notifications service solid statusnotifieritem wayland \
		widgetsaddons windowsystem \
		ecm:build plasma-wayland-protocols:build
USE_QT=		base declarative wayland
USE_XORG=	x11
USE_GL=		gl opengl

CMAKE_ARGS=	-DQT_MAJOR_VERSION=6

.include <bsd.port.mk>
