# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PORTNAME=	freecol
PORTVERSION=	0.10.7
PORTREVISION=	1
CATEGORIES=	games java
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Open source version of Colonization

LICENSE=	GPLv2

OPTIONS_DEFINE=	DOCS

USES=		zip
NO_BUILD=	yes
SUB_FILES=	freecol
USE_JAVA=	yes
JAVA_VERSION=	1.6+

PLIST_FILES=	bin/freecol
PORTDATA=	*
PORTDOCS=	*

DESKTOP_ENTRIES="FreeCol" "${COMMENT}" "${DATADIR}/freecol.xpm" "freecol" "Game;StrategyGame;" true

post-extract:
	@${MV} ${WRKDIR}/freecol ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/freecol ${STAGEDIR}${PREFIX}/bin/
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/FreeCol.jar ${STAGEDIR}${DATADIR}/
	@${INSTALL_DATA} ${WRKSRC}/freecol.xpm ${STAGEDIR}${DATADIR}/
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} data ${STAGEDIR}${DATADIR}/)
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} jars ${STAGEDIR}${DATADIR}/)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/FreeCol.pdf ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
