PORTNAME=	solver
DISTVERSION=	0.1
PORTREVISION=	2
CATEGORIES=	games

MAINTAINER=	modex@danwin1210.de
COMMENT=	Math training game using C and SDL2
WWW=		https://github.com/modexsoft/solver

LICENSE=	BSD3CLAUSE

USES=		sdl
USE_SDL=	image2 mixer2

USE_GITHUB=	yes
GH_ACCOUNT=	modexsoft

do-build:
	${CC} ${WRKSRC}/main.c -I${LOCALBASE}/include -L${LOCALBASE}/lib \
		-lSDL2 -lSDL2_image -lSDL2_mixer -o ${WRKSRC}/solver
	${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC}/data && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/solver ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
