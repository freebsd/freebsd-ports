PORTNAME=	wyrmsun
PORTVERSION=	5.3.3
DISTVERSIONPREFIX=	v
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Strategy game based on history, mythology and fiction

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/license.txt

RUN_DEPENDS=	wyrmgus:games/wyrmgus

USE_GITHUB=	yes
GH_ACCOUNT=	Andrettin
GH_PROJECT=	Wyrmsun

USES=		cmake gnome
INSTALL_TARGET=	install
NO_ARCH=	yes
NO_BUILD=	yes
CMAKE_ARGS=	-DBIN_DIR=bin

PORTDATA=	*
PORTDOCS=	*

PORTSCOUT=	limit:^[0-9]\..*

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
