# New ports collection makefile for:	icebreaker
# Date created:				19 October 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	icebreaker
PORTVERSION=	1.2.1
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://www.mattdm.org/icebreaker/1.2.x/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A game similar to Jezzball or Barrack


USE_SDL=	mixer sdl
USE_GMAKE=	yes
MAKE_ENV=	prefix="${PREFIX}" \
		highscoredir="${PREFIX}/share/icebreaker/scores" \
		mandir="${PREFIX}/man" \
		CHMOD="${CHMOD}" \
		CHOWN="${CHOWN}" \
		MKDIR="${MKDIR}"

MAN6=		${PORTNAME}.6

.include <bsd.port.mk>
