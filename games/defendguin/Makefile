# New ports collection makefile for:	defendguin
# Date created:				8 February 2001
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	defendguin
PORTVERSION=	0.0.9
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.sonic.net/pub/users/nbs/unix/x/defendguin/

MAINTAINER=	sobomax@FreeBSD.org

LIB_DEPENDS=	SDL_mixer.2:${PORTSDIR}/audio/sdl_mixer

SDL_CONFIG?=	${LOCALBASE}/bin/sdl11-config

USE_GMAKE=	yes
MAKE_ENV=	SDL_CONFIG="${SDL_CONFIG}" \
		MKDIR="${MKDIR}" \
		TAR="${TAR}"

MAN6=		defendguin.6

.include <bsd.port.mk>
