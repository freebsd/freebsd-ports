# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sdlroids
PORTVERSION=	1.3.4
PORTREVISION=	9
CATEGORIES=	games
MASTER_SITES=	SF \
		SF/nemysisfreebsdp/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Enhanced shoot-the-asteroids game

LICENSE=	GPLv2

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_CSTD=	gnu89
USE_SDL=	mixer sdl

MAN6=		sdlroids.6

PORTDOCS=	ChangeLog README README.orig README.petopt README.xhyperoid TODO

DESKTOP_ENTRIES="SDLRoids" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME} -n 2" "Game;ArcadeGame;" false

.include <bsd.port.options.mk>

post-install:
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${PORTNAME}.png ${PREFIX}/share/pixmaps

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
