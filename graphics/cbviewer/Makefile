# Created by: nemysis@gmx.ch
# $FreeBSD$

PORTNAME=	cbviewer
PORTVERSION=	0.8
CATEGORIES=	graphics java
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/CBViewer%200.8/ \
		SF/nemysisfreebsdp/:icons
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Comic book viewer for comic book archives in cbz, cbr, zip, rar

LICENSE=	GPLv2

RUN_DEPENDS=	unrar:${PORTSDIR}/archivers/unrar \
		unzip:${PORTSDIR}/archivers/unzip

FETCH_ARGS?=	-Fpr

USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	yes

PLIST_FILES=	bin/${PORTNAME} \
		share/java/cbviewer/CBViewer.jar \
		share/pixmaps/${PORTNAME}.png
PLIST_DIRSTRY=	share/java/cbviewer

PORTDOCS=	CREDITS
DATADIR=	${JAVASHAREDIR}/${PORTNAME}

SUB_FILES=	${PORTNAME}

DESKTOP_ENTRIES="CBViewer" "Comic book viewer" \
		"${PREFIX}/share/pixmaps/${PORTNAME}.png" \
		"${PORTNAME}" "Graphics;Viewer;Java;" true

.include <bsd.port.options.mk>

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.jar ${DATADIR}

post-install:
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png ${PREFIX}/share/pixmaps

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
