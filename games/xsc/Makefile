# Created by: Mark Pulford <mark@kyne.com.au>
# $FreeBSD$

PORTNAME=	xsc
PORTVERSION=	1.6
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.panix.com/~mbh/xsc/ \
		SF/nemysisfreebsdp/${CATEGORIES}/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Vector graphics space shoot'em up game

LICENSE=	GPLv2

USE_XORG=	x11
GNU_CONFIGURE=	yes

PORTDOCS=	AUTHORS ChangeLog  README
OPTIONS_DEFINE=	DOCS

PLIST_FILES=	bin/${PORTNAME} share/pixmaps/${PORTNAME}.png

DESKTOP_ENTRIES="Xsc" "" "${PORTNAME}" "${PORTNAME}" "Game;ArcadeGame;" ""

post-install:
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
