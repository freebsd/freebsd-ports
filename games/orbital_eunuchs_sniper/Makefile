# New ports collection makefile for:	Orbital Eunuchs Sniper
# Date created:			21 Jan 2004
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=	orbital_eunuchs_sniper
PORTVERSION=	1.30
PORTREVISION=	7
CATEGORIES=	games
MASTER_SITES=	http://offload2.icculus.org:9090/oes/ \
		http://offload1.icculus.org:9090/oes/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An overhead shooting game

USE_SDL=	sdl image mixer
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-games-dir=${PREFIX}/share

PORTDOCS=	AUTHORS ChangeLog README TODO readme.txt

CPPFLAGS+=	`${SDL_CONFIG} --cflags`
LDFLAGS+=	`${SDL_CONFIG} --libs`

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
