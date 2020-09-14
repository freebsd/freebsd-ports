# $FreeBSD$

PORTNAME=	kconfig
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	devel kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 widgets for configuration dialogs

# Sources say LGPL20+, KDE policy says LGPL21+, license file is LGPL21
LICENSE=	LGPL21+

USES=		cmake compiler:c++11-lib kde:5 qt:5 tar:xz
USE_KDE=	ecm
USE_QT=		concurrent core dbus gui linguisttools testlib xml \
		buildtools_build qmake_build

.include <bsd.port.mk>
