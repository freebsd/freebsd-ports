# New ports collection makefile for:	gemdropx
# Date created:				9 March 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	gemdropx
PORTVERSION=	0.7
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.sonic.net/pub/users/nbs/unix/x/gemdropx/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	SDL_mixer.2:${PORTSDIR}/audio/sdl_mixer

SDL_CONFIG?=	${LOCALBASE}/bin/sdl11-config

USE_GMAKE=	yes
USE_X_PREFIX=	yes
MAKE_ENV=	JOY=NO \
		SDL_CONFIG="${SDL_CONFIG}"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gemdropx ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/share/gemdropx/images
	${INSTALL_DATA} ${WRKSRC}/data/images/* ${PREFIX}/share/gemdropx/images
	@${MKDIR} ${PREFIX}/share/gemdropx/sounds
	${INSTALL_DATA} ${WRKSRC}/data/sounds/* ${PREFIX}/share/gemdropx/sounds
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/gemdropx
	${INSTALL_DATA} ${WRKSRC}/README.txt ${PREFIX}/share/doc/gemdropx
.endif

.include <bsd.port.mk>
