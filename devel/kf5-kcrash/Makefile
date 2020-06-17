# $FreeBSD$

PORTNAME=	kcrash
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	devel kde kde-frameworks

PATCH_SITES=	https://github.com/KDE/kcrash/commit/
PATCHFILES=	223908ac1030a3a4fe297748101aafcf81076dbc.patch:-p1

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 library to handle crash analysis and bug report from apps

USES=		cmake compiler:c++11-lib kde:5 qt:5 tar:xz xorg
USE_KDE=	coreaddons ecm windowsystem
USE_QT=		buildtools_build core gui qmake_build widgets x11extras
USE_XORG=	ice sm x11 xext

.include <bsd.port.mk>
