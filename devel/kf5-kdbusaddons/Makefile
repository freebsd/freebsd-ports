PORTNAME=	kdbusaddons
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
PORTREVISION=	1
CATEGORIES=	devel kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 addons to QtDBus
WWW=		https://api.kde.org/frameworks-api/frameworks5-apidocs/kdbusaddons/html/index.html

LICENSE=	LGPL21+

USES=		cmake compiler:c++11-lib kde:5 qt:5 tar:xz
USE_KDE=	ecm_build
USE_QT=		core dbus gui x11extras \
		buildtools_build linguisttools_build qmake_build testlib_build

.include <bsd.port.mk>
