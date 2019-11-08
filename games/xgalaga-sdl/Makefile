# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xgalaga-sdl
PORTVERSION=	2.1.1.0
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/ \
		SF/nemysisfreebsdp/${CATEGORIES}/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}-sdl${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}-sdl${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Classic single screen vertical shoot em up SDL

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}-sdl

USES=		localbase:ldflags sdl tar:bzip2
USE_SDL=	sdl gfx image mixer ttf
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--datadir=${DATADIR}

PORTDOCS=	CREDITS README
OPTIONS_DEFINE=	DOCS

DESKTOP_ENTRIES="XGalaga SDL" "" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" ""

post-patch:
	@${REINPLACE_CMD} -e 's|CREDITS||' \
		-e 's|fonts/copyright||' \
		${WRKSRC}/Makefile.in

post-install:
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
