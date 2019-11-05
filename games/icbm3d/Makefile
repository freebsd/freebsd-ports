# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	icbm3d
PORTVERSION=	0.4
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.tuxpaint.org/unix/x/icbm3d/  \
		SF/nemysisfreebsdp/games/${PORTNAME}/:icons
DISTFILES=	${PORTNAME}.${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
EXTRACT_ONLY=	${PORTNAME}.${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Inter-Continental Ballistic Missiles, 3D

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		xorg
USE_XORG=	x11
MAKEFILE=	makefile
ALL_TARGET=	${PORTNAME}

PLIST_FILES=	bin/${PORTNAME} \
		share/pixmaps/${PORTNAME}.png

PORTDOCS=	README.txt
OPTIONS_DEFINE=	DOCS

DESKTOP_ENTRIES="ICBM3D" "" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" ""

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
