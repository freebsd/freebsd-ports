PORTNAME=	goonies
PORTVERSION=	1.4.1528
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://braingames.jorito.net/goonies/downloads/ \
		http://mirror.amdmi3.ru/distfiles/
DISTNAME=	${PORTNAME}.src_${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Remake of the 8 bit classic game 'The Goonies'

LICENSE=	NONE

USES=		gl gmake sdl tar:tgz
USE_SDL=	sdl mixer image
USE_GL=		gl glu
USE_CXXSTD=	c++98

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PORTDATA=	*

post-patch:
	@${REINPLACE_CMD} -e 's|sound/|${DATADIR}/sound/|g' \
		${WRKSRC}/src/SoundManager.cpp
	@${REINPLACE_CMD} -e 's|graphics/|${DATADIR}/graphics/|g; \
		s|"graphics"|"${DATADIR}/graphics"|' \
		${WRKSRC}/src/GLTManager.cpp ${WRKSRC}/src/TheGooniesApp.cpp
	@${REINPLACE_CMD} -e 's|maps/|${DATADIR}/maps/|g' \
		${WRKSRC}/src/TheGoonies.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	@cd ${WRKSRC} && ${COPYTREE_SHARE} 'graphics maps sound' ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/build/linux/${PORTNAME}.png ${STAGEDIR}${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/build/linux/${PORTNAME}.desktop ${STAGEDIR}${PREFIX}/share/applications

.include <bsd.port.mk>
