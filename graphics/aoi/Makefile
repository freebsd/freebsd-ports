# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	aoi
PORTVERSION=	2.9.2
PORTREVISION=	1
CATEGORIES=	graphics java
MASTER_SITES=	SF/${PORTNAME}/ArtOfIllusion/${PORTVERSION}
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//g}
DIST_SUBDIR=	java

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Open source Java written 3D modelling and rendering studio

LICENSE=	GPLv2

RUN_DEPENDS=	java:${PORTSDIR}/java/javavmwrapper

USE_ZIP=	yes
EXTRACT_BEFORE_ARGS=	-a -q
USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/ArtOfIllusion${PORTVERSION:S/.//g}

PORTDOCS=	HISTORY README
DATADIR=	${JAVASHAREDIR}/${PORTNAME}

SUB_FILES=	${PORTNAME} \
		pkg-message

DESKTOP_ENTRIES="Art of Illusion" "3D modelling and rendering studio" \
		"${PREFIX}/share/pixmaps/${PORTNAME}.png" \
		"${PORTNAME}" "Graphics;3DGraphics;" false

.include <bsd.port.options.mk>

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin
.for d in Icons Plugins Scripts lib *.jar
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${d} ${DATADIR})
.endfor
	@(cd ${WRKSRC} && ${CP} -r "Textures and Materials" ${DATADIR})

post-install:
# Fix Permission that user can write in Plugins and Scripts
	@(cd ${DATADIR} && ${CHMOD} -R 774 Plugins Scripts)
	${LN} -sf ${DATADIR}/Icons/48x48.png ${PREFIX}/share/pixmaps/${PORTNAME}.png

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.mk>
