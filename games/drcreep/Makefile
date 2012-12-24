# Created by: Robert Crossfield <robcrossfield@gmail.com>
# $FreeBSD$

PORTNAME=	drcreep
PORTVERSION=	1.0
PORTEPOCH=	1
CATEGORIES=	games
MASTER_SITES=	SF/creep/

MAINTAINER=	robcrossfield@gmail.com
COMMENT=	Castles of Dr. Creep

LICENSE=	GPLv3

USE_SDL=	sdl

WRKSRC=		${WRKDIR}/DrCreep

SUB_FILES+=	pkg-message

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 801000
EXTRA_PATCHES=	${FILESDIR}/extra-patch-src_stdafx.cpp
.endif

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
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
