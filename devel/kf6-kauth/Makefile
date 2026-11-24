PORTNAME=	kauth
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
PORTREVISION=	1
CATEGORIES=	devel kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Execute actions as privileged user

LIB_DEPENDS=	libpolkit-qt6-core-1.so:sysutils/polkit-qt-1@qt6

USES=		cmake cpe gl kde:6 qt:6 tar:xz xorg
CPE_VENDOR=	kde
USE_GL=		opengl
USE_KDE=	coreaddons windowsystem \
		ecm:build
USE_QT=		base \
		tools:build
USE_XORG=	x11

.include <bsd.port.mk>
