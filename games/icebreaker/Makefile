# New ports collection makefile for:	icebreaker
# Date created:				19 October 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	icebreaker
PORTVERSION=	1.0
CATEGORIES=	games
MASTER_SITES=	http://www.mattdm.org/icebreaker/
EXTRACT_SUFX=	.tgz

MAINTAINER=	sobomax@FreeBSD.org

LIB_DEPENDS=	SDL_mixer.2:${PORTSDIR}/audio/sdl_mixer

SDL_CONFIG?=	${LOCALBASE}/bin/sdl11-config

USE_GMAKE=	yes
MAKE_ENV=	SDL_CONFIG="${SDL_CONFIG}" \
		prefix="${PREFIX}" \
		highscoredir="${PREFIX}/share/icebreaker/scores" \
		CHMOD="${CHMOD}" \
		CHOWN="${CHOWN}" \
		MKDIR="${MKDIR}"

.include <bsd.port.mk>
