# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PORTNAME=	freecol
PORTVERSION=	0.11.6
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
	@${INSTALL_DATA} ${WRKSRC}/FreeCol.jar ${STAGEDIR}${DATADIR}/
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} data ${STAGEDIR}${DATADIR}/)
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} jars ${STAGEDIR}${DATADIR}/)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/FreeCol.pdf ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
