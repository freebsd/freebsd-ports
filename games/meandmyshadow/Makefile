# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	meandmyshadow
PORTVERSION=	0.5a
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Me and My Shadow puzzle/platform game

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		cmake compiler:c++11-lang dos2unix libarchive lua:53 sdl
DOS2UNIX_FILES=	CMakeLists.txt src/Functions.cpp
USE_SDL=	sdl2 image2 ttf2 mixer2

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

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in AUTHORS ChangeLog docs/*
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.mk>
