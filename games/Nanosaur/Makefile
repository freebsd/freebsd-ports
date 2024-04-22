PORTNAME=	Nanosaur
DISTVERSIONPREFIX=	v
PORTVERSION=	1.4.4
CATEGORIES=	games

MAINTAINER=	pkubaj@FreeBSD.org
COMMENT=	Nanosaur source port
WWW=		https://pangeasoft.net/nano/

LICENSE=	CC-BY-NC-SA-4.0
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		cmake gl sdl

USE_GITHUB=	yes
GH_ACCOUNT=	jorio
GH_TUPLE=	jorio:Pomme:d57c28e:Pomme/extern/Pomme
USE_GL=		opengl
USE_SDL=	sdl2

SUB_FILES=	Nanosaur

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/${PORTNAME} ${STAGEDIR}${DATADIR}
	@cd ${WRKSRC}/Data && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/Data
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
