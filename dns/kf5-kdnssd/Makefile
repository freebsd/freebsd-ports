# Created by: tcberner
# $FreeBSD$

PORTNAME=	kdnssd
PORTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	dns kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 abstraction to system DNSSD features

# TODO: options to depend on avahi and/or dnssd
USES=		cmake:outsource compiler:c++11-lib kde:5 pkgconfig tar:xz
USE_KDE=	ecm
USE_QT5=	core dbus linguisttools network \
		buildtools_build qmake_build

.include <bsd.port.mk>
