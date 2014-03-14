# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD$

PORTNAME=	cbviewer
PORTVERSION=	0.8
PORTREVISION=	1
CATEGORIES=	graphics java
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/CBViewer%200.8/ \
		SF/nemysisfreebsdp/graphics/:icons
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Comic book viewer for comic book archives in cbz, cbr, zip, rar

LICENSE=	GPLv2

RUN_DEPENDS=	unrar:${PORTSDIR}/archivers/unrar \
		unzip:${PORTSDIR}/archivers/unzip

USES=		zip:infozip
USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	yes

DATADIR=	${JAVASHAREDIR}/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME} \
		share/java/cbviewer/CBViewer.jar \
		share/pixmaps/${PORTNAME}.png
PLIST_DIRSTRY=	share/java/cbviewer

PORTDOCS=	CREDITS

OPTIONS_DEFINE=	DOCS

SUB_FILES=	${PORTNAME}

DESKTOP_ENTRIES="CBViewer" "Comic book viewer" "${PORTNAME}" \
		"${PORTNAME}" "Graphics;Viewer;Java;" ""

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.jar ${STAGEDIR}${DATADIR}

post-install:
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
