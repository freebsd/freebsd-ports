# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	highmoon
PORTVERSION=	1.2.4
PORTREVISION=	12
CATEGORIES=	games
MASTER_SITES=	http://highmoon.gerdsmeier.net/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Duel in the universe

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

WRKSRC=		${WRKDIR}/HighMoon

USES=		gmake
USE_SDL=	image sdl
MAKE_ARGS=	CXX="${CXX}" CXXFLAGS="${CXXFLAGS}" LIBS="${LIBS}"

CXXFLAGS+=	`${SDL_CONFIG} --cflags`
LIBS+=		`${SDL_CONFIG} --libs` -lSDL_image

PORTDOCS=	AUTHORS NEWS README
OPTIONS_DEFINE=	DOCS

SUB_FILES=	pkg-message

DESKTOP_ENTRIES="HighMoon" "" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" ""

post-patch:
	@${FIND} ${WRKSRC}/src -type f | ${XARGS} ${REINPLACE_CMD} -e \
		's|SDL/SDL|SDL|; \
		 s|^#define __ENV|//#define __ENV|; \
		 s|"gfx/|(char\*)"${DATADIR}/gfx/|; \
		 s|"snd/|(char\*)"${DATADIR}/snd/|; \
		 s|-round(|-rint(|'
	${REINPLACE_CMD} -e \
		's|planet_filename = ""|planet_filename = (char\*)""|; \
		 s|u_filename = ""|u_filename = (char\*)""|; \
		 s|c_filename = ""|c_filename = (char\*)""|' \
		${WRKSRC}/src/galaxy.cpp
	${REINPLACE_CMD} -e 's|"HighMoon -|(char\*)"HighMoon -|; \
		s|"Highmoon -|(char\*)"HighMoon -|' \
		${WRKSRC}/src/language.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ufo ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "gfx snd" ${STAGEDIR}${DATADIR})
	${INSTALL_DATA} ${WRKSRC}/icon.png ${STAGEDIR}${DATADIR}
	${LN} -sf ${DATADIR}/icon.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
