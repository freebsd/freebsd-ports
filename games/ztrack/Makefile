# Created by: Andrey Zakhvatov <andy@icc.surw.chel.su>
# $FreeBSD$

PORTNAME=	ztrack
PORTVERSION=	1.0
CATEGORIES=	games
MASTER_SITES=	SUNSITE/games/arcade \
		SF/nemysisfreebsdp/${CATEGORIES}/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple ncurses based pseudo-3D driving game

WRKSRC=		${WRKDIR}/${PORTNAME}

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS} -DHAVE_RANDOM"
ALL_TARGET=	ztrack
PLIST_FILES=	bin/${PORTNAME} man/man6/${PORTNAME}.6.gz \
		${DESKTOPDIR}/${PORTNAME}.desktop \
		share/pixmaps/${PORTNAME}.png

PORTDOCS=	ChangeLog README
OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.6 ${STAGEDIR}${MAN6PREFIX}/man/man6/
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/
	${INSTALL_DATA} ${FILESDIR}/${PORTNAME}.desktop ${STAGEDIR}${DESKTOPDIR}

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
