# New ports collection makefile for:	linwarrior
# Date created:		31 Dec 2008
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	linwarrior
PORTVERSION=	20081224
CATEGORIES=	games
MASTER_SITES=	http://www.hackcraft.de/games/linwarrior_3d/downloads/ \
		http://mirror.amdmi3.ru/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Navigate a mech through a 3D world and fire at enemies

USE_SDL=	sdl mixer
USE_GL=		gl glu

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/linwarrior

SRCS=		cBackground cBuilding cController cMech cMission cObject \
		cTree cWeapon cWorld main

do-build:
.for s in ${SRCS}
	cd ${WRKSRC}/source && ${CXX} ${CXXFLAGS} `${SDL_CONFIG} --cflags` \
	       	-I.. -I../psi3d -c ${s}.cpp -o ${s}.o
.endfor
	cd ${WRKSRC}/source && ${CXX} `${SDL_CONFIG} --libs` -lGL -lGLU \
	       	${SRCS:C/$/.o/} -o ${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/source/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
