# Created by: Mark Pulford <mark@kyne.com.au>
# $FreeBSD$

PORTNAME=	pipenightdreams
PORTVERSION=	0.10.0
PORTREVISION=	13
CATEGORIES=	games
MASTER_SITES=	http://www.libsdl.org/projects/pipenightdreams/packages/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Puzzle game similar to PipeMania

LICENSE=	GPLv2 # or later
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake
USE_SDL=	image sdl
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include

PORTDOCS=	AUTHORS ChangeLog NEWS README
OPTIONS_DEFINE=	DOCS

DESKTOP_ENTRIES="PipeNightDreams" "" ${PORTNAME} \
		"${PORTNAME}" "Game;LogicGame;" ""

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} 's|"SDL/SDL|"SDL|g ; s|<SDL/SDL|<SDL|g; \
		s|SDL_LIBSS|SDL_LIBS|g; s|datadir/games|datadir|;' \
		${WRKSRC}/configure
	${FIND} ${WRKSRC} -name Makefile.in | \
		${XARGS} ${REINPLACE_CMD} 's|/games/|/|g; \
			s/^pipenightdreams_LDADD.+//g;'
	${REINPLACE_CMD} "s|/usr/share/games|${LOCALBASE}/share|g" \
		${WRKSRC}/src/main.cpp

post-install:
	${LN} -sf ${DATADIR}/images/default/splash.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
