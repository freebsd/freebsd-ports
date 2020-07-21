# $FreeBSD$

PORTNAME=	kidletime
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	devel kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 library for monitoring user activity

USES=		cmake compiler:c++11-lib kde:5 pkgconfig qt:5 tar:xz xorg
USE_KDE=	ecm
USE_QT=		core dbus gui widgets x11extras \
		buildtools_build qmake_build
USE_XORG=	ice sm x11 xext xcb xscrnsaver

.include <bsd.port.mk>
