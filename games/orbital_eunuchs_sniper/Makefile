# Created by: Jean-Yves Lefort <jylefort@brutele.be>
# $FreeBSD$

PORTNAME=	orbital_eunuchs_sniper
PORTVERSION=	1.30
PORTREVISION=	8
CATEGORIES=	games
MASTER_SITES=	http://offload2.icculus.org:9090/oes/ \
		http://offload1.icculus.org:9090/oes/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Overhead shooting game

USE_SDL=	sdl image mixer
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-games-dir=${PREFIX}/share

PORTDOCS=	AUTHORS ChangeLog README TODO readme.txt

CPPFLAGS+=	`${SDL_CONFIG} --cflags`
LDFLAGS+=	`${SDL_CONFIG} --libs`

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
