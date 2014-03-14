# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	aoi
PORTVERSION=	3.0
CATEGORIES=	graphics java
MASTER_SITES=	SF/${PORTNAME}/ArtOfIllusion/${PORTVERSION} \
		SF/${PORTNAME}/ArtOfIllusion-manual/${PORTVERSION}:docs
DISTFILES=	${PORTNAME}${PORTVERSION:S/.//g}${EXTRACT_SUFX}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Open source Java written 3D modelling and rendering studio

LICENSE=	GPLv2

LIB_DEPENDS=	libjogl.so:${PORTSDIR}/graphics/jogl
RUN_DEPENDS=	java:${PORTSDIR}/java/javavmwrapper

USES=		zip:infozip
EXTRACT_BEFORE_ARGS=	-a -q
USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/ArtOfIllusion${PORTVERSION:S/.//g}
DATADIR=	${JAVASHAREDIR}/${PORTNAME}

PORTDOCS=	*

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	HISTORY README

DOCSRCDIR2=	${WRKDIR}/AoI_Manual
DOCSDIR2=	${DOCSDIR}/AoI_Manual
DOC_FILES2=	*

OPTIONS_DEFINE= DOCS

SUB_FILES=	${PORTNAME} pkg-deinstall pkg-message

DESKTOP_ENTRIES="Art of Illusion" "3D modelling and rendering studio" \
		"${PORTNAME}" "${PORTNAME}" "Graphics;3DGraphics;" ""

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
DISTFILES+=	manual${PORTVERSION}${EXTRACT_SUFX}:docs
post-extract:
	@(cd ${WRKDIR} && ${MV} "AoI Manual" AoI_Manual)
.endif

post-patch::
	@(cd ${WRKSRC} && ${RM} "Textures and Materials/Library/.DS_Store")

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
.for d in Icons Plugins Scripts lib *.jar
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${d} ${STAGEDIR}${DATADIR})
.endfor
	@(cd ${WRKSRC} && ${CP} -r "Textures and Materials" ${STAGEDIR}${DATADIR})

# Fix Permission that user can write in Plugins and Scripts
	@(cd ${STAGEDIR}${DATADIR} && ${CHMOD} -R 774 Plugins Scripts)
	${LN} -sf ${DATADIR}/Icons/48x48.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${STAGEDIR}${DOCSDIR}
	@(cd ${WRKDIR}/AoI_Manual && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR2})
.endif

.include <bsd.port.mk>
