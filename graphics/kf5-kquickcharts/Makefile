# $FreeBSD$

PORTNAME=	kquickcharts
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	graphics kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 QtQuick plugin providing high-performance charts

USES=		cmake compiler:c++11-lib kde:5 qt:5 tar:xz
USE_KDE=	ecm \
		kirigami2_run
USE_QT=		core declarative gui network quickcontrols2 \
		buildtools_build qmake_build \
		quickcontrols2_run

.include <bsd.port.mk>
