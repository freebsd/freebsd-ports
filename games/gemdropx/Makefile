# New ports collection makefile for:	gemdropx
# Date created:				9 March 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	gemdropx
PORTVERSION=	0.9
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.sonic.net/pub/users/nbs/unix/x/gemdropx/

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	An interesting one-player puzzle game for X

LIB_DEPENDS=	SDL_mixer.2:${PORTSDIR}/audio/sdl_mixer

SDL_CONFIG?=	${LOCALBASE}/bin/sdl11-config

USE_GMAKE=	yes
USE_X_PREFIX=	yes
MAKE_ENV=	JOY=NO \
		SDL_CONFIG="${SDL_CONFIG}"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gemdropx ${PREFIX}/bin
	@${MKDIR} ${DATADIR}/images
	${INSTALL_DATA} ${WRKSRC}/data/images/* ${DATADIR}/images
	@${MKDIR} ${DATADIR}/sounds
	${INSTALL_DATA} ${WRKSRC}/data/sounds/* ${DATADIR}/sounds
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
