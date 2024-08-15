PORTNAME=	freecol
PORTVERSION=	1.2.0
CATEGORIES=	games java
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Open source version of Colonization
WWW=		https://freecol.org/

LICENSE=	GPLv2

USES=		cpe zip

OPTIONS_DEFINE=	DOCS

NO_BUILD=	yes
NO_ARCH=	yes
SUB_FILES=	freecol
USE_JAVA=	11+

PLIST_FILES=	bin/freecol \
		${DESKTOPDIR:S,^${PREFIX}/,,}/freecol.desktop
PORTDATA=	*
PORTDOCS=	*

post-extract:
	@${MV} ${WRKDIR}/freecol ${WRKSRC}

post-patch:
	@${REINPLACE_CMD} "s|Icon=|Icon=${DATADIR}/|" ${WRKSRC}/freecol.desktop

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/freecol ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/freecol.desktop ${STAGEDIR}${DESKTOPDIR}/
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/FreeCol.jar ${STAGEDIR}${DATADIR}/
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} data ${STAGEDIR}${DATADIR}/)
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} jars ${STAGEDIR}${DATADIR}/)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/FreeCol.pdf ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
