# New ports collection makefile for: rockdodger
# Date created:		02 Dec 2002
# Whom:			nbm
#
# $FreeBSD$
#

PORTNAME=	rockdodger
PORTVERSION=	0.6
CATEGORIES=	games
MASTER_SITES= 	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	spacerocks

MAINTAINER=	ports@freebsd.org

LIB_DEPENDS=	SDL-1.1.5:${PORTSDIR}/devel/sdl12 \
		SDL_mixer.2:${PORTSDIR}/audio/sdl_mixer \
		SDL_image.10:${PORTSDIR}/graphics/sdl_image

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
