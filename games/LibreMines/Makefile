PORTNAME=	LibreMines
PORTVERSION=	2.0.1
DISTVERSIONPREFIX=	v
CATEGORIES=	games

MAINTAINER=	pkubaj@FreeBSD.org
COMMENT=	Free/Libre and Open Source Software Qt based Minesweeper
WWW=		https://github.com/Bollos00/LibreMines

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake gl qt:${FLAVOR:S/qt//}
FLAVORS=	qt5 qt6
FLAVOR?=	qt5
qt5_PKGNAMESUFFIX=	-qt5
qt6_PKGNAMESUFFIX=	-qt6
_USE_QT5=	buildtools:build core gui multimedia network qmake:build svg widgets
_USE_QT6=	base multimedia svg
USE_GL=		gl opengl
USE_QT=		${_USE_QT${FLAVOR:S/qt//}}

USE_GITHUB=	yes
GH_ACCOUNT=	Bollos00

CMAKE_ARGS+=	-DUSE_QT6=${"${FLAVOR}"==qt5:?FALSE:TRUE}

.include <bsd.port.mk>
