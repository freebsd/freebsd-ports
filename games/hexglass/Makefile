# $FreeBSD$

PORTNAME=	hexglass
PORTVERSION=	1.2.1
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tetris-like puzzle game based on a hexagonal grid

BROKEN=		Unfetchable (google code has gone away)

USE_QT4=	gui moc_build rcc_build
USES=		qmake

PLIST_FILES=	bin/${PORTNAME} \
		share/pixmaps/${PORTNAME}.xpm

DESKTOP_ENTRIES=	"HexGlass" "${COMMENT}" \
			"${PREFIX}/share/pixmaps/${PORTNAME}.xpm" \
			"${PORTNAME}" "BlocksGame;Game;" true

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/resources/logo512x512.xpm \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.xpm

.include <bsd.port.mk>
