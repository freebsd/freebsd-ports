# $FreeBSD$

PORTNAME=	abuse_sdl
PORTVERSION=	0.8
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	GENTOO/distfiles \
		http://abuse.zoy.org/raw-attachment/wiki/download/
DISTNAME=	abuse-${DISTVERSION}

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	SDL port of the Abuse game engine

LICENSE=	GPLv2

USES=		pathfix
USE_GL=		gl
USE_SDL=	mixer sdl
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-assetdir=${DATADIR} --enable-release

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PORTDOCS=	AUTHORS ChangeLog NEWS README TODO

DESKTOP_ENTRIES="Abuse-SDL" "${COMMENT}" "abuse" \
		"abuse" "Game;StrategyGame;" false

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/abuse.png ${STAGEDIR}${PREFIX}/share/pixmaps/

	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
