# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PORTNAME=	freecol
PORTVERSION=	0.10.7
PORTREVISION=	1
CATEGORIES=	games java
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ale@FreeBSD.org
COMMENT=	An open source version of Colonization

LICENSE=	GPLv2

USES=		zip
NO_BUILD=	yes
SUB_FILES=	freecol
USE_JAVA=	yes
JAVA_VERSION=	1.6+

.if defined(NOPORTDATA)
IGNORE=		needs data file to run, unset NOPORTDATA
.endif

PLIST_FILES=	bin/freecol
PORTDATA=	*
PORTDOCS=	*

DESKTOP_ENTRIES="FreeCol" "${COMMENT}" "${DATADIR}/freecol.xpm" "freecol" "Game;StrategyGame;" "false"

NO_STAGE=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-extract:
	@${MV} ${WRKDIR}/freecol ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/freecol ${PREFIX}/bin/
	@${MKDIR} ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/FreeCol.jar ${DATADIR}/
	@${INSTALL_DATA} ${WRKSRC}/freecol.xpm ${DATADIR}/
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} data ${DATADIR}/)
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} jars ${DATADIR}/)
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/FreeCol.pdf ${DOCSDIR}/
.endif

.include <bsd.port.mk>
