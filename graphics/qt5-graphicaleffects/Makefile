# $FreeBSD$

PORTNAME=	graphicaleffects
DISTVERSION=	${QT5_VERSION}
CATEGORIES=	graphics
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt Quick graphical effects

BROKEN_aarch64=		fails to install: pkg-static: Unable to access file DropShadowBase.qmlc: No such file or directory

USES=		qmake
USE_QT5=	buildtools_build core gui quick qml
QT_DIST=	${PORTNAME}

.include <bsd.port.mk>
