# New ports collection makefile for:	Rock Dodger
# Date created:				02 Dec 2002
# Whom:					Neil Blakey-Milner <nbm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	rockdodger
PORTVERSION=	0.6.0a
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/spacerocks/spacerocks/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Addictive rock-dodging greeblie-killing platform game

USE_SDL=	mixer image sdl
USE_GMAKE=	yes

GAMESDIR?=	/var/games

pre-patch:
	@${REINPLACE_CMD} \
		-e "s%/usr/share/rockdodger/.highscore%${GAMESDIR}/rockdodger.highscore%" \
		-e "s%/usr/share/rockdodger%${PREFIX}/share/rockdodger%" \
		-e "s%/usr/games%${PREFIX}/bin%" \
		-e "s%data/\*.{bmp,png,wav,mod}%data/*%" \
		${WRKSRC}/Makefile ${WRKSRC}/main.c
	@cd ${WRKSRC} && ${REINPLACE_CMD} -e "s%#include <SDL/%#include <%" SFont.c SFont.h main.c sound.c

pre-install:
	@${MKDIR} ${GAMESDIR}

.include <bsd.port.mk>
