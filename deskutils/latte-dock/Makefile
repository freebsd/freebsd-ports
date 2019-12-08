# $FreeBSD$

PORTNAME=	latte-dock
DISTVERSION=	0.9.5
CATEGORIES=	deskutils kde
MASTER_SITES=	KDE/stable/latte-dock

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Launcher for Qt and Plasma desktops

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libxcb-util.so:x11/xcb-util

USES=		cmake compiler:c++11-lang gettext kde:5 qt:5 tar:xz xorg
USE_KDE=	activities archive attica auth codecs config configwidgets \
		coreaddons crash dbusaddons globalaccel guiaddons i18n \
		iconthemes libksysguard kdeclarative newstuff notifications \
		package plasma-framework service wayland widgetsaddons \
		windowsystem xmlgui \
		ecm_build
USE_QT=		core dbus declarative gui network widgets x11extras xml \
		buildtools_build qmake_build
USE_XORG=	ice sm x11 xcb xext

.include <bsd.port.mk>
