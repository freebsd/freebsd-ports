# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	highmoon
PORTVERSION=	1.2.4
PORTREVISION=	9
CATEGORIES=	games
MASTER_SITES=	http://highmoon.gerdsmeier.net/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Duel in the universe

WRKSRC=		${WRKDIR}/HighMoon

USE_SDL=	image sdl
USES=		gmake
MAKE_ARGS=	CXX="${CXX}" CXXFLAGS="${CXXFLAGS}" LIBS="${LDFLAGS}"

CXXFLAGS+=	`${SDL_CONFIG} --cflags`
LDFLAGS+=	`${SDL_CONFIG} --libs` -lSDL_image

OPTIONS_DEFINE=	DOCS

post-patch:
	@${FIND} ${WRKSRC}/src -type f | ${XARGS} ${REINPLACE_CMD} -e \
		's|SDL/SDL|SDL|g ; \
		 s|^#define __ENV|//#define __ENV|g ; \
		 s|"gfx/|"${DATADIR}/gfx/|g ; \
		 s|"snd/|"${DATADIR}/snd/|g ; \
		 s|-round(|-rint(|g'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ufo ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${DATADIR}/gfx
	${INSTALL_DATA} ${WRKSRC}/gfx/* ${STAGEDIR}${DATADIR}/gfx
	@${MKDIR} ${STAGEDIR}${DATADIR}/snd
	${INSTALL_DATA} ${WRKSRC}/snd/* ${STAGEDIR}${DATADIR}/snd
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
