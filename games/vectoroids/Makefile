# New ports collection makefile for:	vectoroids
# Date created:				27 June 2003
# Whom:					Kris Kennaway <kris@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	vectoroids
PORTVERSION=	1.1.0
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.sonic.net/pub/users/nbs/unix/x/vectoroids/src/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A vector-based, pretty, Asteroids clone

LIB_DEPENDS=	SDL_mixer.2:${PORTSDIR}/audio/sdl_mixer \
		SDL_image.10:${PORTSDIR}/graphics/sdl_image

USE_X_PREFIX=	yes
USE_SDL=	yes
USE_GMAKE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vectoroids ${PREFIX}/bin
	@${MKDIR} ${DATADIR}/images
	${INSTALL_DATA} ${WRKSRC}/data/images/* ${DATADIR}/images
	@${MKDIR} ${DATADIR}/music
	${INSTALL_DATA} ${WRKSRC}/data/music/* ${DATADIR}/music
	@${MKDIR} ${DATADIR}/sounds
	${INSTALL_DATA} ${WRKSRC}/data/sounds/* ${DATADIR}/sounds
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${DOCSDIR}/README
.endif

.include <bsd.port.mk>
