# New ports collection makefile for: rockdodger
# Date created:		02 Dec 2002
# Whom:			nbm
#
# $FreeBSD$
#

PORTNAME=	rockdodger
PORTVERSION=	0.6
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES= 	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	spacerocks

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Addictive rock-dodging greeblie-killing platform game

USE_SDL=	mixer image sdl
USE_REINPLACE=	yes
USE_GMAKE=	yes

GAMESDIR?=	/var/games

pre-patch:
	@${REINPLACE_CMD} \
		-e "s%sdl-config%sdl11-config%" \
		-e "s%/usr/share/rockdodger/.highscore%${GAMESDIR}/rockdodger.highscore%" \
		-e "s%/usr/share/rockdodger%${PREFIX}/share/rockdodger%" \
		-e "s%/usr/games%${PREFIX}/bin%" \
		-e "s%data/\*.{bmp,png,wav,mod}%data/*%" \
		${WRKSRC}/Makefile ${WRKSRC}/main.c
	@cd ${WRKSRC} && ${REINPLACE_CMD} -e "s%#include <SDL/%#include <%" SFont.c SFont.h main.c sound.c sound.h

pre-install:
	@${MKDIR} ${GAMESDIR}

.include <bsd.port.mk>
