PORTNAME=	kdbusaddons
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	devel kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 addons to QtDBus

LICENSE=	LGPL21+

USES=		cmake compiler:c++11-lib kde:5 qt:5 tar:xz
USE_KDE=	ecm:build
USE_QT=		core dbus gui x11extras \
		buildtools:build linguisttools:build qmake:build testlib:build

.include <bsd.port.mk>
