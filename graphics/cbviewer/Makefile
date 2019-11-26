# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cbviewer
PORTVERSION=	0.8
PORTREVISION=	3
CATEGORIES=	graphics java
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/CBViewer%200.8/ \
		SF/nemysisfreebsdp/graphics/:icons
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Comic book viewer for comic book archives in cbz, cbr, zip, rar

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	unrar:archivers/unrar

USES=		dos2unix zip
DOS2UNIX_GLOB=	CREDITS
USE_JAVA=	yes
NO_BUILD=	yes

DATADIR=	${JAVASHAREDIR}/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME} \
		share/java/cbviewer/CBViewer.jar \
		share/pixmaps/${PORTNAME}.png

PORTDOCS=	CREDITS

SUB_FILES=	${PORTNAME}

DESKTOP_ENTRIES="CBViewer" "Comic book viewer" "${PORTNAME}" \
		"${PORTNAME}" "Graphics;Viewer;Java;" ""

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.jar ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
