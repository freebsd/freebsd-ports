# New ports collection makefile for:   drcreep
# Date created:        2011-07-03
# Whom:                Robert Crossfield <robcrossfield@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	drcreep
PORTVERSION=	394
CATEGORIES=	games
MASTER_SITES=	SF/creep/

MAINTAINER=	robcrossfield@gmail.com
COMMENT=	The Castles of Dr. Creep

LICENSE=	GPLv3

USE_SDL=	sdl

WRKSRC=		${WRKDIR}/head

do-build:
	cd ${WRKSRC} && ${CXX} -DFREEBSD -o ${PORTNAME} ${CXXFLAGS} \
		`${SDL_CONFIG} --cflags --libs` -I./src src/*.cpp src/graphics/*.cpp \
		src/graphics/scale/*.cpp src/castle/*.cpp src/castle/objects/*.cpp \
		src/vic-ii/*.cpp src/resid-0.16/*.cpp src/sound/*.cpp -lcompat

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${MKDIR} ${DATADIR}/data
	${MKDIR} ${DATADIR}/data/castle
	${MKDIR} ${DATADIR}/data/castles
	${MKDIR} ${DATADIR}/data/save

	${INSTALL_DATA} ${WRKSRC}/run/data/char.rom ${DATADIR}/data

	@echo '------------------------------------------------------'
	@echo ''
	@echo 'Please copy your Castles of Dr. Creep disk image (D64) to ${DATADIR}/data'
	@echo ''
	@echo ''

.include <bsd.port.mk>
