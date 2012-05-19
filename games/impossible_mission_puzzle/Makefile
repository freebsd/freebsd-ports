# New Ports collection makefile for:	impossible_mission_puzzle
# Date created:		2012-04-27
# Whom:			nemysis@gmx.ch
#
# $FreeBSD$
#

PORTNAME=	impossible_mission_puzzle
PORTVERSION=	1.0.1
CATEGORIES=	games
MASTER_SITES=	http://www.linuxmotors.com/puzzle/downloads/
DISTNAME=	puzzle-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	nemysis@gmx.ch
COMMENT=	This is a puzzle from the old C64 Impossible Mission game

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/puzzle-${PORTVERSION}

USE_SDL=	sdl
MAKE_JOBS_SAFE=	yes

PLIST_FILES=	bin/impossible_mission_puzzle

PORTDOCS=	README

do-build:
	@cd ${WRKSRC} && ${CC} -o ${PORTNAME} ${CFLAGS} \
	`${SDL_CONFIG} --cflags --libs` puzzle.c

do-install:
# Executable
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

# Documentation
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
