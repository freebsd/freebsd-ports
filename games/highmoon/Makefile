# New ports collection makefile for:	HighMoon
# Date created:				20 Jan 2005
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	highmoon
PORTVERSION=	1.0.2
CATEGORIES=	games
MASTER_SITES=	http://highmoon.gerdsmeier.net/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Duel in the universe

USE_REINPLACE=	yes
USE_SDL=	sdl

WRKSRC=		${WRKDIR}/${PORTNAME}

pre-patch:
	@${REINPLACE_CMD} -E 's,"(snd|gfx)/,"${DATADIR}/\1/,' \
		${WRKSRC}/galaxy.cpp ${WRKSRC}/graphics.cpp ${WRKSRC}/sound.cpp
	@${REINPLACE_CMD} -e 's,[[:cntrl:]]*$$,,' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's,^#include <SDL/,#include <,' \
		${WRKSRC}/constants.hpp ${WRKSRC}/graphics.hpp \
		${WRKSRC}/main.cpp ${WRKSRC}/main.cpp ${WRKSRC}/sound.hpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ufo ${PREFIX}/bin/${PORTNAME}
	@${MKDIR} ${DATADIR}/snd ${DATADIR}/gfx
	${INSTALL_DATA} ${WRKSRC}/snd/* ${DATADIR}/snd
	${INSTALL_DATA} ${WRKSRC}/gfx/* ${DATADIR}/gfx

.include <bsd.port.mk>
