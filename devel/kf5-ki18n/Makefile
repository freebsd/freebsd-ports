# Created by: tcberner
# $FreeBSD$

PORTNAME=	ki18n
PORTVERSION=	${KDE_FRAMEWORKS_VERSION}
PORTREVISION=	1
CATEGORIES=	devel kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 advanced internationalization framework

USES=		cmake:outsource compiler:c++11-lib gettext-runtime \
		gettext-tools:build,run kde:5 tar:xz
USE_KDE=	ecm
USE_QT5=	buildtools_build concurrent core qmake_build qml script testlib

.include <bsd.port.mk>
