# New Ports collection makefile for:	SDL_jewels
# Date created:		2012-04-25
# Whom:			nemysis@gmx.ch
#
# $FreeBSD$
#

PORTNAME=	sdl_jewels
PORTVERSION=	1.1.1
CATEGORIES=	games
MASTER_SITES=	http://www.linuxmotors.com/gljewel/downloads/
DISTNAME=	${PORTNAME:S/sdl/SDL/}-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	nemysis@gmx.ch
COMMENT=	SDL Jewels is a tile-matching 8x8 puzzle game

LICENSE=	GPLv2

USE_SDL=	sdl image mixer
USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes

PLIST_FILES=	bin/sdljewels

PORTDATA=	*
PORTDOCS=	ChangeLog README

ALL_TARGET=

do-install:
# Scripts
	@${PRINTF} "#!/bin/sh\n\ncd ${DATADIR} &&\
		./gljewel\n" > ${WRKDIR}/sdljewels.sh
	@${INSTALL_SCRIPT} ${WRKDIR}/sdljewels.sh ${PREFIX}/bin/sdljewels
# Executable
	${MKDIR} ${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/gljewel ${DATADIR}
# Data
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} data ${DATADIR})

# Documentation
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
