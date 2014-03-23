# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rescue
PORTVERSION=	1.0.0.3
CATEGORIES=	games java
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME:S/r/R/}%21%20Max/${PORTVERSION}/
DISTNAME=	${PORTNAME:S/r/R/}_${PORTVERSION}
DIST_SUBDIR=	java

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Action adventure in space

LICENSE=	GPLv3

USES=		dos2unix zip:infozip
DOS2UNIX_GLOB=	*.txt *.htm *.css *.ini *.xml
USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME:S/r/R/}

PORTDOCS=	ChangeLog.txt
DATADIR=	${JAVASHAREDIR}/${PORTNAME}

SUB_FILES=	${PORTNAME}

DESKTOP_ENTRIES="Rescue! Max" "" "${PORTNAME}" \
		"${PORTNAME}" "Game;StrategyGame;" ""

post-extract:
	@(cd ${WRKSRC} && ${UNZIP_CMD} -j Rescue.jar rescue/gui/logo.png)

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
.for d in help lib missions *.jar
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${d} ${STAGEDIR}${DATADIR})
.endfor
	${INSTALL_DATA} ${WRKSRC}/logo.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
