# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	black-box
PORTVERSION=	1.4.8
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://www.linux-games.com/black-box/ \
		SF/nemysisfreebsdp/${CATEGORIES}/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Shoot in and watch where the shot leaves the box

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		sdl
USE_SDL=	sdl image mixer
GNU_CONFIGURE=	yes

PORTDOCS=	AUTHORS ChangeLog NEWS README

DESKTOP_ENTRIES="Black-Box" "" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" ""

OPTIONS_DEFINE=	DOCS

post-install:
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
