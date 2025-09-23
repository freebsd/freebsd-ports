PORTNAME=	LibreMines
PORTVERSION=	2.2.0
DISTVERSIONPREFIX=	v
CATEGORIES=	games

MAINTAINER=	pkubaj@FreeBSD.org
COMMENT=	Free/Libre and Open Source Software Qt based Minesweeper
WWW=		https://github.com/Bollos00/LibreMines

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake gl qt:6
USE_GL=		gl opengl
USE_QT=		base multimedia svg

USE_GITHUB=	yes
GH_ACCOUNT=	Bollos00

CMAKE_ARGS+=	-DUSE_QT6=TRUE

.include <bsd.port.mk>
