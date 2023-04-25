PORTNAME=	kquickcharts
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
PORTREVISION=	1
CATEGORIES=	graphics kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 QtQuick plugin providing high-performance charts

USES=		cmake compiler:c++11-lib kde:5 qt:5 tar:xz
USE_KDE=	ecm:build \
		kirigami2:run
USE_QT=		core declarative gui network quickcontrols2 \
		buildtools:build qmake:build \
		quickcontrols2:run

.include <bsd.port.mk>
