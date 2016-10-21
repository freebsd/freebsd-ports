# $FreeBSD$

PORTNAME=	pouetchess
PORTVERSION=	0.1.1
PORTREVISION=	13
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/0.11
DISTNAME=	pouetChess_0.11_src

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Open-source 3D chess game

USE_SDL=	sdl image
USE_GL=		gl
USES=		dos2unix gmake
DOS2UNIX_GLOB=	*.cpp *.h Makefile config.ini

WRKSRC=		${WRKDIR}/pouetChess_0.11

PORTDATA=	*

DESKTOP_ENTRIES="pouetChess" \
		"Play chess" \
		"${DATADIR}/textures/1.png" \
		"pouetChess" \
		"Game;BoardGame;" \
		false

post-patch:
	@${REINPLACE_CMD} -e 's|sdl-config|${SDL_CONFIG}|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e '/^LIBS/ s|$$| -L${LOCALBASE}/lib|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e '/CXX	/ d' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e '/CXXFLAGS.*+=/ d' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e '/^CXXFLAGS/ s|:=|+=|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e '/^CXXFLAGS/ s|$$| -I${LOCALBASE}/include|' ${WRKSRC}/Makefile

	@${REINPLACE_CMD} -e 's|config\.ini|${PREFIX}/etc/pouetChess.conf|' ${WRKSRC}/src/globalInfos.cpp
	@${REINPLACE_CMD} -e 's|data/|${DATADIR}/|' ${WRKSRC}/src/globalInfos.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/pouetChess ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/bin/config.ini ${STAGEDIR}${PREFIX}/etc/pouetChess.conf.sample
	cd ${WRKSRC}/bin/data && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
