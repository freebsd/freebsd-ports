# $FreeBSD$

PORTNAME=	solid
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	devel kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 hardware integration and detection

USES=		bison cmake:outsource compiler:c++11-lib kde:5 qt:5 tar:xz
USE_KDE=	ecm
USE_QT=		buildtools_build concurrent core dbus declarative gui linguisttools \
		network qmake_build testlib widgets xml

OPTIONS_DEFINE=		BSDISKS
BSDISKS_DESC=		Use bsdisks instead of hald to mount drives
BSDISKS_CMAKE_BOOL=	EXPERIMENTAL_BSDISKS
BSDISKS_RUN_DEPENDS=	bsdisks:sysutils/bsdisks

.include <bsd.port.mk>
