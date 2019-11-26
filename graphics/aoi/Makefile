# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	aoi
PORTVERSION=	3.0
PORTREVISION=	4
CATEGORIES=	graphics java
MASTER_SITES=	SF/${PORTNAME}/ArtOfIllusion/${PORTVERSION} \
		SF/${PORTNAME}/ArtOfIllusion-manual/${PORTVERSION}:docs
DISTFILES=	${PORTNAME}${PORTVERSION:S/.//g}${EXTRACT_SUFX}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open source Java written 3D modelling and rendering studio

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libjogl.so:graphics/jogl

USES=		zip
DOS2UNIX_FILES=	../AoI_Manual/*.html # USES=dos2unix is optional
USE_JAVA=	yes
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/ArtOfIllusion${PORTVERSION:S/.//g}
DATADIR=	${JAVASHAREDIR}/${PORTNAME}

PORTDOCS=	*

SUB_FILES=	${PORTNAME} pkg-deinstall pkg-message

DESKTOP_ENTRIES="Art of Illusion" "3D modelling and rendering studio" \
		"${PORTNAME}" "${PORTNAME}" "Graphics;3DGraphics;" ""

OPTIONS_DEFINE= DOCS

DOCS_DISTFILES=	manual${PORTVERSION}${EXTRACT_SUFX}:docs
DOCS_USES=	dos2unix

post-extract-DOCS-on:
	@(cd ${WRKDIR} && ${MV} "AoI Manual" AoI_Manual)

post-patch:
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

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} HISTORY README ${STAGEDIR}${DOCSDIR}
	cd ${WRKDIR} && ${COPYTREE_SHARE} "AoI_Manual" ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
