# New ports collection makefile for:	madbomber
# Date created:				28 September 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	madbomber
PORTVERSION=	0.1.8
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.sonic.net/pub/users/nbs/unix/x/madbomber/

MAINTAINER=	sobomax@FreeBSD.org

LIB_DEPENDS=	SDL_image.10:${PORTSDIR}/graphics/sdl_image \
		SDL_mixer.2:${PORTSDIR}/audio/sdl_mixer

SDL_CONFIG?=	${LOCALBASE}/bin/sdl11-config

USE_GMAKE=	yes
MAKE_ENV=	SDL_CONFIG="${SDL_CONFIG}"

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/madbomber ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/share/madbomber
	@cd ${WRKSRC}/data; tar cf - . | \
		(cd ${PREFIX}/share/madbomber; ${TAR} --unlink -xf - )

.include <bsd.port.mk>
