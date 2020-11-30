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

OPTIONS_DEFINE=	IMOBILE

IMOBILE_DESC=		Apple iPhone/iPod Touch support
IMOBILE_LIB_DEPENDS=	libimobiledevice.so:comms/libimobiledevice \
			libplist.so:devel/libplist
IMOBILE_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_IMobileDevice \
			CMAKE_DISABLE_FIND_PACKAGE_PList

.include <bsd.port.mk>
