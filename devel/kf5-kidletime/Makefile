# Created by: tcberner
# $FreeBSD$

PORTNAME=	kidletime
PORTVERSION=	${KDE_FRAMEWORKS_VERSION}
PORTREVISION=	1
CATEGORIES=	devel kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 library for monitoring user activity

USES=		cmake:outsource compiler:c++11-lib kde:5 pkgconfig tar:xz
USE_KDE=	ecm
USE_QT5=	buildtools_build core dbus gui qmake_build widgets x11extras
USE_XORG=	ice sm x11 xext xcb xscrnsaver

.include <bsd.port.mk>
