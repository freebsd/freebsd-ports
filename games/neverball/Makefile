# New ports collection makefile for:	neverball
# Date created:				26 October 2003
# Whom:					Mezz <mezz7@cox.net>
#
# $FreeBSD$
#

PORTNAME=	neverball
PORTVERSION=	0.25.11
CATEGORIES=	games
MASTER_SITES=	http://icculus.org/neverball/

MAINTAINER=	mezz7@cox.net
COMMENT=	Tilt the floor to guide a ball through an obstacle course

LIB_DEPENDS=	SDL_ttf.3:${PORTSDIR}/graphics/sdl_ttf \
		SDL_mixer.2:${PORTSDIR}/audio/sdl_mixer \
		SDL_image.10:${PORTSDIR}/graphics/sdl_image

USE_BZIP2=	yes
USE_SDL=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_REINPLACE=	yes

DIRS=		back bgm map mtrl png shot snd sol ttf

post-patch:
	@${REINPLACE_CMD} -e 's|./data|${DATADIR}/data|g' \
		${WRKSRC}/config.h

do-install:
.for ii in ${DIRS}
	@${MKDIR} ${DATADIR}/data/${ii}
	@${INSTALL_DATA} ${WRKSRC}/data/${ii}/* ${DATADIR}/data/${ii}/
.endfor
	@${INSTALL_DATA} ${WRKSRC}/data/*.txt ${DATADIR}/data/
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/

.include <bsd.port.mk>
