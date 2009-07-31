# New ports collection makefile for:	Orbital Eunuchs Sniper
# Date created:			21 Jan 2004
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=	orbital_eunuchs_sniper
PORTVERSION=	1.30
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://filesingularity.timedoctor.org/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An overhead shooting game

USE_SDL=	sdl image mixer
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="`${SDL_CONFIG} --cflags`" \
		LDFLAGS="`${SDL_CONFIG} --libs`"
CONFIGURE_ARGS=	--with-games-dir=${PREFIX}/share \
		--program-transform-name=

PORTDOCS=	AUTHORS ChangeLog README TODO readme.txt

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
.for FILE in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
