# New ports collection makefile for:	zatacka
# Date created:		26 Mar 2006
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	zatacka
PORTVERSION=	0.1.6
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION}_src

MAINTAINER=	amdmi3@amdmi3.ru
COMMENT=	Nibbles-like multiplayer game

USE_SDL=	sdl ttf image
USE_GMAKE=	yes

WRKSRC=		${WRKDIR}/zatacka
MAKE_ARGS=	CXX=${CXX}

PORTDOCS=	README

post-patch:
	@${REINPLACE_CMD} -e 's|sdl-config|${SDL_CONFIG}|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|font.ttf|${DATADIR}/font.ttf|' ${WRKSRC}/fx.h
	@${REINPLACE_CMD} -e 's|barrier.jpg|${DATADIR}/barrier.jpg|' \
		${WRKSRC}/fx.cpp
	@${REINPLACE_CMD} -e 's|main_screen.jpg|${DATADIR}/main_screen.jpg|' \
		${WRKSRC}/fx.cpp
	@${REINPLACE_CMD} -e 's|maps/|${DATADIR}/maps/|' ${WRKSRC}/fx.cpp
	@${REINPLACE_CMD} -e '/opendir/ s|maps|${DATADIR}/maps|' ${WRKSRC}/fx.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/main_screen.jpg ${WRKSRC}/barrier.jpg \
		${WRKSRC}/font.ttf ${DATADIR}
	${MKDIR} ${DATADIR}/maps
	${INSTALL_DATA} ${WRKSRC}/maps/*.jpg ${DATADIR}/maps

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
