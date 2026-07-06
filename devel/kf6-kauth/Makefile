PORTNAME=	kauth
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	devel kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Execute actions as privileged user

LIB_DEPENDS=	libpolkit-qt6-core-1.so:sysutils/polkit-qt-1@qt6

USES=		cmake cpe kde:6 qt:6 tar:xz
CPE_VENDOR=	kde
USE_KDE=	coreaddons kded windowsystem \
		ecm:build
USE_QT=		base

.include <bsd.port.mk>
