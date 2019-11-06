# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tomatoes
PORTVERSION=	1.55
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF
DISTFILES=	${PORTNAME}-linux-src-${PORTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}-linux-${DATAVERSION}${EXTRACT_SUFX}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Tomato-smashing, Q-Bert style

BROKEN=		unfetchable

LICENSE=	ZLIB

DATAVERSION=	1.5
DATA_WRKSRC=	${WRKDIR}/tomatoes-${DATAVERSION}

USES=		gl gmake sdl tar:bzip2
USE_SDL=	mixer image
USE_GL=		gl glu
MAKEFILE=	makefile
MAKE_ARGS=	CC="${CXX}" \
		MPKDIR="${DATADIR}/" \
		MUSICDIR="${DATADIR}/music/" \
		HISCOREDIR="${DATADIR}/" \
		CONFIGDIR="${DATADIR}/" \
		CFLAGS="${CXXFLAGS} ${SDL_CFLAGS}" \
		LDFLAGS="${SDL_LDFLAGS}"

SDL_CFLAGS=	`${SDL_CONFIG} --cflags` -I${LOCALBASE}/include
SDL_LDFLAGS=	`${SDL_CONFIG} --libs` -lSDL_image -lSDL_mixer \
		-L${LOCALBASE}/lib -lGL -lGLU

PLIST_FILES=	bin/${PORTNAME} \
		share/pixmaps/${PORTNAME}.png
PORTDATA=	*
PORTDOCS=	*

DESKTOP_ENTRIES="Tomatoes" \
		"" \
		"${PORTNAME}" \
		"${PORTNAME}" \
		"Game;ArcadeGame;" \
		false

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/icon.png ${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png
	@${MKDIR} ${STAGEDIR}${DATADIR}/music
	${INSTALL_DATA} ${DATA_WRKSRC}/config.cfg ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${DATA_WRKSRC}/tomatoes.mpk ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${DATA_WRKSRC}/music/IHaveNoTomatoes.it ${STAGEDIR}${DATADIR}/music

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DATA_WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
