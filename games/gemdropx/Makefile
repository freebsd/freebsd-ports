# New ports collection makefile for:	gemdropx
# Date created:				9 March 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	gemdropx
PORTVERSION=	0.9
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.nbswebfx.com/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An interesting one-player puzzle game for X

USE_SDL=	mixer
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
