# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xgalaga-sdl
PORTVERSION=	2.1.1.0
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/ \
		SF/nemysisfreebsdp/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}-sdl${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}-sdl${EXTRACT_SUFX}

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Classic single screen vertical shoot em up SDL

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}-sdl

USE_BZIP2=	yes
USE_SDL=	sdl gfx image mixer ttf
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--datadir=${DATADIR}

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PORTDOCS=	CREDITS README

DESKTOP_ENTRIES="XGalaga SDL" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" false

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|CREDITS||' \
		-e 's|fonts/copyright||' \
		${WRKSRC}/Makefile.in

post-install:
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
