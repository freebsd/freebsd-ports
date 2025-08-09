PORTNAME=	cdogs-sdl
DISTVERSION=	2.3.1
CATEGORIES=	games

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Classic overhead run-and-gun game
WWW=		https://github.com/cxong/cdogs-sdl

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake gl sdl
USE_GITHUB=	yes
GH_ACCOUNT=	cxong
USE_GL=		opengl
USE_SDL=	image2 mixer2 sdl2

CMAKE_ARGS=	-DCDOGS_DATA_DIR=${DATADIR}/

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/cdogs-sdl
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/cdogs-sdl-editor

.include <bsd.port.mk>
