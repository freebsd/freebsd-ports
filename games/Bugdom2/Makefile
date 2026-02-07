PORTNAME=	Bugdom2
PORTVERSION=	4.0.0
DISTVERSIONPREFIX=	v
CATEGORIES=	games

MAINTAINER=	pkubaj@FreeBSD.org
COMMENT=	Pangea Software's Bugdom 2 for modern systems
WWW=		https://pangeasoft.net/bug2/

LICENSE=	CC-BY-NC-SA-4.0
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		cmake gl sdl

USE_GITHUB=	yes
GH_ACCOUNT=	jorio
GH_TUPLE=	jorio:Pomme:c6a38ea:Pomme/extern/Pomme
USE_GL=		gl opengl
USE_SDL=	sdl2

SUB_FILES=	Bugdom2

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/${PORTNAME} ${STAGEDIR}${DATADIR}
	@cd ${WRKSRC}/Data && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/Data
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
