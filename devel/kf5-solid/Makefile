# $FreeBSD$

PORTNAME=	solid
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	devel kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 hardware integration and detection

RUN_DEPENDS=	bsdisks:sysutils/bsdisks

USES=		bison cmake compiler:c++11-lib kde:5 qt:5 tar:xz
USE_KDE=	ecm
USE_QT=		concurrent core dbus declarative gui linguisttools \
		network testlib widgets xml \
		buildtools_build qmake_build

.include <bsd.port.mk>
