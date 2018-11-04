# Created by: Robert Crossfield <robcrossfield@gmail.com>
# $FreeBSD$

PORTNAME=	drcreep
PORTVERSION=	1.1
PORTEPOCH=	1
CATEGORIES=	games
MASTER_SITES=	SF/creep/

MAINTAINER=	robcrossfield@gmail.com
COMMENT=	Castles of Dr. Creep

LICENSE=	GPLv3

BROKEN=		fails to build

USE_SDL=	sdl

WRKSRC=		${WRKDIR}/DrCreep

SUB_FILES+=	pkg-message

do-build:
	@(cd ${WRKSRC} && ${CXX} -DFREEBSD -o ${PORTNAME} ${CXXFLAGS} \
		`${SDL_CONFIG} --cflags --libs` -I./src src/*.cpp src/graphics/*.cpp \
		src/graphics/scale/*.cpp src/castle/*.cpp src/castle/objects/*.cpp \
		src/vic-ii/*.cpp src/resid-0.16/*.cpp src/sound/*.cpp -lcompat)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}/data
	@${MKDIR} ${STAGEDIR}${DATADIR}/data/castle
	@${MKDIR} ${STAGEDIR}${DATADIR}/data/castles
	@${MKDIR} ${STAGEDIR}${DATADIR}/data/save

	${INSTALL_DATA} ${WRKSRC}/run/data/char.rom ${STAGEDIR}${DATADIR}/data

.include <bsd.port.mk>
