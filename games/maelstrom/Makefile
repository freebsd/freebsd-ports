# New ports collection makefile for:	Maelstrom
# Date created:				13 May 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	maelstrom
PORTVERSION=	3.0.5
CATEGORIES=	games
MASTER_SITES=	http://www.devolution.com/~slouken/projects/Maelstrom/src/
DISTNAME=	Maelstrom-${PORTVERSION}

MAINTAINER=	sobomax@FreeBSD.org

LIB_DEPENDS=	SDL_net.0:${PORTSDIR}/net/sdl_net

SDL_CONFIG?=	${LOCALBASE}/bin/sdl11-config

USE_X_PREFIX=	yes
USE_XPM=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	SDL_CONFIG="${SDL_CONFIG}"

.if !defined(NOPORTDOCS)
INSTALL_TARGET=	install install_gamedocs
.endif

post-install:
	${CHOWN} root:games ${PREFIX}/bin/Maelstrom
	${CHMOD} 2755 ${PREFIX}/bin/Maelstrom
	${CHMOD} 664 ${PREFIX}/share/Maelstrom/Maelstrom-Scores
	${CHOWN} root:games ${PREFIX}/share/Maelstrom/Maelstrom-Scores

.include <bsd.port.mk>
