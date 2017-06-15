# Created by: Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
# $FreeBSD$

PORTNAME=	data
PORTVERSION=	3.2.1
CATEGORIES=	games
MASTER_SITES=	SF/glest/glest%20${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	glest-
DISTNAME=	glest_${PORTNAME}_${PORTVERSION}
DIST_SUBDIR=	glest

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Glest data files

USES=		dos2unix zip
DOS2UNIX_GLOB=	*.log *.ini *.html *.txt *.lng
NO_BUILD=	yes

PLIST=		${WRKDIR}/pkg-plist
WRKSRC=		${WRKDIR}/glest_game

DATADIR=	${PREFIX}/share/${PKGNAMEPREFIX:S/-//}
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX:S/-//}
GLESTDATADIRE=	data maps scenarios techs tilesets tutorials

PORTDATA=	*
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-extract:
	@${MV} ${WRKSRC}/docs/license.txt ${WRKSRC}/docs/license-data.txt
	@${RMDIR} ${WRKSRC}/screens

do-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/license-data.txt ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/readme.txt ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${DATADIR}
.for FILE in glest.ico servers.ini
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${STAGEDIR}${DATADIR}
.endfor

.for DIRE in ${GLESTDATADIRE}
	@cd ${WRKSRC} && \
		${FIND} ${DIRE} -type d -exec ${MKDIR} "${STAGEDIR}${DATADIR}/{}" \; && \
			${FIND} ${DIRE} -type f -exec ${INSTALL_DATA} {} "${STAGEDIR}${DATADIR}/{}" \;
.endfor

.include <bsd.port.mk>
