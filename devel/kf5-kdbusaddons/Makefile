# $FreeBSD$

PORTNAME=	kdbusaddons
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	devel kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 addons to QtDBus

LICENSE=	LGPL21+

USES=		cmake compiler:c++11-lib kde:5 qt:5 tar:xz
USE_KDE=	ecm
USE_QT=		core dbus gui linguisttools testlib x11extras \
		buildtools_build qmake_build

.include <bsd.port.mk>
