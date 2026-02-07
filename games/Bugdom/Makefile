PORTNAME=	Bugdom
PORTVERSION=	1.3.4
CATEGORIES=	games

MAINTAINER=	pkubaj@FreeBSD.org
COMMENT=	Pangea Software's Bugdom for modern systems
WWW=		https://pangeasoft.net/bug/

LICENSE=	CC-BY-NC-SA-4.0
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		cmake gl sdl

USE_GITHUB=	yes
GH_ACCOUNT=	jorio
GH_TUPLE=	jorio:Pomme:ef94150:Pomme/extern/Pomme
USE_GL=		gl opengl
USE_SDL=	sdl2

SUB_FILES=	Bugdom

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/${PORTNAME} ${STAGEDIR}${DATADIR}
	@cd ${WRKSRC}/Data && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/Data
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
