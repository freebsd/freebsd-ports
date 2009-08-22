# New ports collection makefile for:	glest-data
# Date created:				2006-04-10
# Whom:					Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTNAME=	data
PORTVERSION=	3.2.1
CATEGORIES=	games
MASTER_SITES=	SF/glest/glest%20${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	glest-
DISTNAME=	glest_${PORTNAME}_${PORTVERSION}
DIST_SUBDIR=	glest

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Glest data files

USE_ZIP=	yes
USE_DOS2UNIX=	*.log *.ini *.html *.txt *.lng
NO_BUILD=	yes

PLIST=		${WRKDIR}/pkg-plist
WRKSRC=		${WRKDIR}/glest_game

DATADIR=	share/${PKGNAMEPREFIX:S/-//}
DOCSDIR=	share/doc/${PKGNAMEPREFIX:S/-//}
GLESTDATADIRE=	data maps scenarios techs tilesets tutorials

post-extract:
	@${MV} ${WRKSRC}/docs/license.txt ${WRKSRC}/docs/license-data.txt
	@${RMDIR} ${WRKSRC}/screens

pre-install:
	@${RM} -f ${PLIST}

.	for FILE in glest.ico servers.ini
		@${ECHO_CMD} "%%DATADIR%%/${FILE}" >> ${PLIST}
.	endfor

.	for DIRE in ${GLESTDATADIRE}
		@cd ${WRKSRC} && \
			${FIND} ${DIRE} -type f | ${SORT} | ${SED} -e 's|^|%%DATADIR%%/|' >> ${PLIST} && \
				${FIND} ${DIRE} -type d | ${SORT} -r | ${SED} -e 's|^|@dirrm %%DATADIR%%/|' >> ${PLIST}
.	endfor
	@${ECHO_CMD} "@dirrmtry %%DATADIR%%" >> ${PLIST}

.	if !defined(NOPORTDOCS)
		@cd ${WRKSRC}/docs && \
			${FIND} * -type f | ${SORT} | ${SED} -e 's|^|%%PORTDOCS%%%%DOCSDIR%%/|' >> ${PLIST} && \
				${FIND} * -type d | ${SORT} -r | ${SED} -e 's|^|%%PORTDOCS%%@dirrm %%DOCSDIR%%/|' >> ${PLIST}
	@${ECHO_CMD} "%%PORTDOCS%%@dirrmtry %%DOCSDIR%%" >> ${PLIST}
.	endif

do-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/license-data.txt ${PREFIX}/${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/readme.txt ${PREFIX}/${DOCSDIR}
.endif
	@${MKDIR} ${PREFIX}/${DATADIR}
.for FILE in glest.ico servers.ini
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${PREFIX}/${DATADIR}
.endfor

.for DIRE in ${GLESTDATADIRE}
	@cd ${WRKSRC} && \
		${FIND} ${DIRE} -type d -exec ${MKDIR} "${PREFIX}/${DATADIR}/{}" \; && \
			${FIND} ${DIRE} -type f -exec ${INSTALL_DATA} "{}" "${PREFIX}/${DATADIR}/{}" \;
.endfor

.include <bsd.port.mk>
