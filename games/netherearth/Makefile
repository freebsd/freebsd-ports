# Created by: Ginzburg Oleg

PORTNAME=	netherearth
PORTVERSION=	0.51
PORTREVISION=	12
CATEGORIES=	games
MASTER_SITES=	http://move.kirishi.ru/soft/netherearth/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Remake of the first real time strategy game on the SPECTRUM

GNU_CONFIGURE=	yes

USES=		compiler gl sdl
USE_GL=		gl glu glut
USE_SDL=	sdl mixer

CXXFLAGS+=	${CXXFLAGS_${CHOSEN_COMPILER_TYPE}}
CXXFLAGS_clang=	-Wno-c++11-narrowing

pre-install:
	if [ ! -d ${STAGEDIR}${PREFIX}/share/netherearth ] ; then \
		${MKDIR} ${STAGEDIR}${PREFIX}/share/netherearth ;\
	fi
	${CP} -R ${WRKSRC}/maps ${STAGEDIR}${PREFIX}/share/netherearth/
	${CP} -R ${WRKSRC}/models ${STAGEDIR}${PREFIX}/share/netherearth/
	${CP} -R ${WRKSRC}/sound ${STAGEDIR}${PREFIX}/share/netherearth/
	${CP} -R ${WRKSRC}/textures ${STAGEDIR}${PREFIX}/share/netherearth/

.include <bsd.port.mk>
