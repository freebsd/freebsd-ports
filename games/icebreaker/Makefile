# New ports collection makefile for:	icebreaker
# Date created:				19 October 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	icebreaker
PORTVERSION=	1.2.1
CATEGORIES=	games
MASTER_SITES=	http://www.mattdm.org/icebreaker/1.2.x/
EXTRACT_SUFX=	.tgz

MAINTAINER=	sobomax@FreeBSD.org

LIB_DEPENDS=	SDL_mixer.2:${PORTSDIR}/audio/sdl_mixer

SDL_CONFIG?=	${LOCALBASE}/bin/sdl11-config

USE_GMAKE=	yes
MAKE_ENV=	SDL_CONFIG="${SDL_CONFIG}" \
		prefix="${PREFIX}" \
		highscoredir="${PREFIX}/share/icebreaker/scores" \
		mandir="${PREFIX}/man" \
		CHMOD="${CHMOD}" \
		CHOWN="${CHOWN}" \
		MKDIR="${MKDIR}"

MAN6=		${PORTNAME}.6

.include <bsd.port.mk>
