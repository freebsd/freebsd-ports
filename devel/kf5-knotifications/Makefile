# $FreeBSD$

PORTNAME=	knotifications
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
PORTREVISION=	1
CATEGORIES=	devel kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 abstraction for system notifications

LIB_DEPENDS=	libdbusmenu-qt5.so:devel/libdbusmenu-qt@qt5

USES=		cmake:outsource compiler:c++11-lib gettext kde:5 tar:xz
USE_KDE=	codecs config coreaddons ecm windowsystem
USE_QT5=	buildtools_build core dbus gui linguisttools phonon4 \
		qmake_build widgets x11extras
USE_XORG=	x11

.include <bsd.port.mk>
