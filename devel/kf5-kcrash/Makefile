# Created by: tcberner
# $FreeBSD$

PORTNAME=	kcrash
PORTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	devel kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 library to handle crash analysis and bug report from apps

USES=		cmake:outsource compiler:c++11-lib kde:5 tar:xz
USE_KDE=	coreaddons ecm windowsystem
USE_QT5=	buildtools_build core gui qmake_build widgets x11extras
USE_XORG=	ice sm x11 xext

.include <bsd.port.mk>
