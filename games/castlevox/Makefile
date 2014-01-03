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

USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}PC
PORTDOCS=	README_Vox.txt
DATADIR=	${JAVASHAREDIR}/${PORTNAME}

SUB_FILES=	${PORTNAME}

DESKTOP_ENTRIES="Castle Vox" "${COMMENT}" \
		"${PREFIX}/share/pixmaps/${PORTNAME}.png" \
		"${PORTNAME}" "Game;StrategyGame;" false

NO_STAGE=	yes
.include <bsd.port.options.mk>

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "Support docs *.jar" ${DATADIR})
	${INSTALL_DATA} ${WRKSRC}/VoxIcon.png ${PREFIX}/share/pixmaps/${PORTNAME}.png

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
