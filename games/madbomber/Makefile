# New ports collection makefile for:	madbomber
# Date created:				28 September 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	madbomber
PORTVERSION=	0.2.5
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.sonic.net/pub/users/nbs/unix/x/madbomber/src/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A clone of Activision's classic Atari 2600 console game "Kaboom!"

LIB_DEPENDS=	SDL_mixer.2:${PORTSDIR}/audio/sdl_mixer \
		SDL_image.10:${PORTSDIR}/graphics/sdl_image

USE_SDL=	yes

CPPFLAGS=	`${SDL_CONFIG} --cflags` -DDATA_PREFIX=\"${DATADIR}/\"
LDFLAGS=	`${SDL_CONFIG} --libs`

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} ${CPPFLAGS} -o ${PORTNAME} \
		${PORTNAME}.c ${LDFLAGS} -lSDL_mixer -lSDL_image

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/madbomber ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${TAR} -C ${WRKSRC}/data  --exclude embedded -cf - . | \
		${TAR} -C ${DATADIR} --unlink -xf -
	@${FIND} ${DATADIR} | ${XARGS} ${CHOWN} ${SHAREOWN}:${SHAREGRP}
	@${FIND} ${DATADIR} -type f | ${XARGS} ${CHMOD} ${SHAREMODE}

.include <bsd.port.mk>
