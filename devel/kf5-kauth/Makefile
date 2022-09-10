PORTNAME=	kauth
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	devel kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 abstraction to system policy and authentication features

LIB_DEPENDS=	libpolkit-qt5-core-1.so:sysutils/polkit-qt

USES=		cmake compiler:c++11-lib cpe kde:5 qt:5 tar:xz
CPE_VENDOR=	kde
USE_KDE=	coreaddons \
		ecm_build
USE_QT=		core dbus gui linguisttools widgets \
		buildtools_build qmake_build

.include <bsd.port.mk>
