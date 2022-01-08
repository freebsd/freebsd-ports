PORTNAME=	kcrash
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	devel kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 library to handle crash analysis and bug report from apps

USES=		cmake compiler:c++11-lib kde:5 qt:5 tar:xz xorg
USE_KDE=	coreaddons windowsystem \
		ecm_build
USE_QT=		core gui widgets x11extras \
		buildtools_build qmake_build testlib_build
USE_XORG=	ice sm x11 xext

.include <bsd.port.mk>
