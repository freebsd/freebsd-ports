# Created by: tcberner
# $FreeBSD$

PORTNAME=	solid
PORTVERSION=	${KDE_FRAMEWORKS_VERSION}
PORTREVISION=	1
CATEGORIES=	devel kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 hardware integration and detection

USES=		bison cmake:outsource compiler:c++11-lib kde:5 tar:xz
USE_KDE=	ecm
USE_QT5=	buildtools_build concurrent core dbus gui linguisttools \
		network qmake_build qml testlib widgets xml

OPTIONS_DEFINE=		BSDISKS
BSDISKS_DESC=		Use bsdisks instead of hald to mount drives
BSDISKS_CMAKE_BOOL=	EXPERIMENTAL_BSDISKS
BSDISKS_RUN_DEPENDS=	bsdisks:sysutils/bsdisks

.include <bsd.port.mk>
