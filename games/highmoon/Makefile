# New ports collection makefile for:	HighMoon
# Date created:				20 Jan 2005
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	highmoon
PORTVERSION=	1.2.4
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	http://highmoon.gerdsmeier.net/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Duel in the universe

WRKSRC=		${WRKDIR}/HighMoon

USE_SDL=	image sdl
USE_GMAKE=	yes
MAKE_ARGS=	CXX="${CXX}" CXXFLAGS="${CXXFLAGS}" LIBS="${LDFLAGS}"

CXXFLAGS+=	`${SDL_CONFIG} --cflags`
LDFLAGS=	`${SDL_CONFIG} --libs` -lSDL_image

post-patch:
	@${FIND} ${WRKSRC}/src -type f | ${XARGS} ${REINPLACE_CMD} -e \
		's|SDL/SDL|SDL|g ; \
		 s|^#define __ENV|//#define __ENV|g ; \
		 s|"gfx/|"${DATADIR}/gfx/|g ; \
		 s|"snd/|"${DATADIR}/snd/|g ; \
		 s|-round(|-rint(|g'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ufo ${PREFIX}/bin/${PORTNAME}
	@${MKDIR} ${DATADIR}/gfx
	${INSTALL_DATA} ${WRKSRC}/gfx/* ${DATADIR}/gfx
	@${MKDIR} ${DATADIR}/snd
	${INSTALL_DATA} ${WRKSRC}/snd/* ${DATADIR}/snd
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
