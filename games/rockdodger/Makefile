# Created by: Neil Blakey-Milner <nbm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rockdodger
PORTVERSION=	0.6.0a
PORTREVISION=	6
CATEGORIES=	games
MASTER_SITES=	SF/spacerocks/spacerocks/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Addictive rock-dodging greeblie-killing platform game

USE_SDL=	mixer image sdl
USES=		gmake

GAMESDIR?=	/var/games

pre-patch:
	@${REINPLACE_CMD} \
		-e "s%/usr/share/rockdodger/.highscore%${GAMESDIR}/rockdodger.highscore%" \
		-e "s%/usr/share/rockdodger%${PREFIX}/share/rockdodger%" \
		-e "s%/usr/games%${PREFIX}/bin%" \
		${WRKSRC}/main.c
	@${REINPLACE_CMD} \
		-e "s%/usr/share/rockdodger/.highscore%${STAGEDIR}${GAMESDIR}/rockdodger.highscore%" \
		-e "s%/usr/games%${STAGEDIR}${PREFIX}/bin%" \
		-e "s%/usr/share/rockdodger%${STAGEDIR}${PREFIX}/share/rockdodger%" \
		-e "s%data/\*.{bmp,png,wav,mod}%data/*%" \
		${WRKSRC}/Makefile
	@cd ${WRKSRC} && ${REINPLACE_CMD} -e "s%#include <SDL/%#include <%" SFont.c SFont.h main.c sound.c

pre-install:
	@${MKDIR} ${STAGEDIR}${GAMESDIR}

.include <bsd.port.mk>
