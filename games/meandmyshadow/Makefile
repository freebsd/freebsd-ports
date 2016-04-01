# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	meandmyshadow
PORTVERSION=	0.4.1
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Me and My Shadow puzzle/platform game

LICENSE=	GPLv3

LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		cmake libarchive
USE_SDL=	sdl ttf image mixer image gfx

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PLIST_FILES=	bin/${PORTNAME} \
		share/pixmaps/${PORTNAME}.png
PORTDOCS=	*
PORTDATA=	*

DESKTOP_ENTRIES="Me and My Shadow" \
		"Puzzle/platform game" \
		"${PREFIX}/share/pixmaps/meandmyshadow.png" \
		"meandmyshadow" \
		"Game;LogicGame;" \
		false

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/cmake/Modules/FindSDL_gfx.cmake

post-install:
	${INSTALL_DATA} ${WRKSRC}/icons/64x64/meandmyshadow.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in AUTHORS ChangeLog docs/*
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.mk>
