# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	xvier
PORTVERSION=	1.0
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	SUNSITE/games/strategy \
		SF/nemysisfreebsdp/${CATEGORIES}/:icons
DISTFILES=	${PORTNAME}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
EXTRACT_ONLY=	${PORTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Throw stones into free columns

USES=		imake tar:Z xorg
USE_XORG=	x11 xext
USE_CSTD=	gnu89

PORTDOCS=	README
OPTIONS_DEFINE=	DOCS

PLIST_FILES=	bin/${PORTNAME} \
		libexec/${PORTNAME}_prog \
		man/man6/xvier.6.gz \
		share/pixmaps/xvier.png

DESKTOP_ENTRIES="Xvier" "" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" ""

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME}_prog \
		${STAGEDIR}${PREFIX}/libexec/
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.man \
		${STAGEDIR}${MAN6PREFIX}/man/man6/${PORTNAME}.6

	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
