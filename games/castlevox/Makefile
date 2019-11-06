# Created by: Martin Otto
# $FreeBSD$

PORTNAME=	CastleVox
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	games java
MASTER_SITES=	http://sillysoft.net/download/
DISTNAME=	${PORTNAME}-linux

MAINTAINER=	gamato@users.sf.net
COMMENT=	Fast world domination game

BROKEN=		unfetchable

USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	yes
NO_ARCH=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}PC
PORTDOCS=	README_Vox.txt
DATADIR=	${JAVASHAREDIR}/${PORTNAME}

SUB_FILES=	${PORTNAME}

DESKTOP_ENTRIES="Castle Vox" "${COMMENT}" \
		"${PREFIX}/share/pixmaps/${PORTNAME}.png" \
		"${PORTNAME}" "Game;StrategyGame;" false

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "Support docs *.jar" ${STAGEDIR}${DATADIR})
	${INSTALL_DATA} ${WRKSRC}/VoxIcon.png ${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
