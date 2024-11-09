PORTNAME=	rescue
DISTVERSION=	1.0.5
CATEGORIES=	games java
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME:S/r/R/}%21%20Max/${PORTVERSION}/
DISTNAME=	${PORTNAME:S/r/R/}_${PORTVERSION}
DIST_SUBDIR=	java

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Action adventure in Space
WWW=		https://rescue.sourceforge.net/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/gpl.txt

USES=		dos2unix zip:infozip
DOS2UNIX_GLOB=	*.css *.htm *.ini *.txt *.xml
USE_JAVA=	yes

DATADIR=	${JAVASHAREDIR}/${PORTNAME}
DESKTOP_ENTRIES=	"Rescue! Max" \
			"" \
			"${PORTNAME}" \
			"${PORTNAME}" \
			"Game;StrategyGame;" \
			""
NO_BUILD=	yes
SUB_FILES=	${PORTNAME}

WRKSRC=		${WRKDIR}/${PORTNAME:S/r/R/}

PORTDOCS=	ChangeLog.txt
OPTIONS_DEFINE=	DOCS

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
