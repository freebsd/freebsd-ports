# $FreeBSD$

PORTNAME=	latte-dock
DISTVERSION=	0.7.2
CATEGORIES=	deskutils kde
MASTER_SITES=	KDE/stable/latte-dock

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Launcher for Qt and Plasma desktops

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libxcb-util.so:x11/xcb-util

USES=		cmake:outsource gettext kde:5 tar:xz
USE_KDE=	activities archive auth codecs config configwidgets \
		coreaddons crash dbusaddons globalaccel i18n iconthemes \
		kdeclarative notifications package plasma-framework service \
		wayland widgetsaddons windowsystem xmlgui \
		ecm_build
USE_QT5=	core dbus gui network qml quick widgets x11extras xml \
		buildtools_build qmake_build
USE_XORG=	ice sm x11 xcb xext

.include <bsd.port.mk>
