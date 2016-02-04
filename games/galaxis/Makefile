# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	galaxis
PORTVERSION=	1.9
CATEGORIES=	games
MASTER_SITES=	http://www.catb.org/~esr/galaxis/ \
		SF/nemysisfreebsdp/games/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Clone of the nifty little Macintosh game

LICENSE=	BSD3CLAUSE

WRKSRC=		${WRKDIR}/${PORTNAME}-

USES=		gmake ncurses
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS} -DNDEBUG" \
		TERMLIB="${LDFLAGS} -lncurses"
ALL_TARGET=	${PORTNAME}

PLIST_FILES=	bin/${PORTNAME} \
		man/man6/${PORTNAME}.6.gz \
		share/applications/${PORTNAME}.desktop \
		share/pixmaps/${PORTNAME}.png

PORTDOCS=	README
OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.desktop ${STAGEDIR}${DESKTOPDIR}
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.6 ${STAGEDIR}${MAN6PREFIX}/man/man6/

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
