# New ports collection makefile for:	megaglest-data
# Date created:				2010-11-12
# Whom:					Sven Moeller <smoeller@nichthelfer.de>
#
# $FreeBSD$
#

PORTNAME=	megaglest
PORTVERSION=	3.5.2
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/current_release/
PKGNAMESUFFIX=	-data
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}.3

MAINTAINER=	smoeller@nichthelfer.de
COMMENT=	MegaGlest data files

USE_XZ=		yes
USE_DOS2UNIX=	*.log *.ini *.html *.txt *.lng
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PLIST=		${WRKDIR}/pkg-plist

pre-install:
	${RM} -f ${PLIST}
.for DIR in data maps scenarios techs tilesets tutorials
	@cd ${WRKSRC} && \
		${FIND} ${DIR} -type d -empty | ${SORT} -r | ${SED} -e 's|^|@exec ${MKDIR} %D/%%DATADIR%%/|' -e 's|$$| > /dev/null 2>\&1|' >> ${PLIST} && \
		${FIND} ${DIR} -type f | ${SORT} | ${SED} -e 's|^|%%DATADIR%%/|' >> ${PLIST} && \
		${FIND} ${DIR} -type d | ${SORT} -r | ${SED} -e 's|^|@dirrm %%DATADIR%%/|' >> ${PLIST}
.endfor
	@${ECHO_CMD} "share/applications/megaglest.desktop" >> ${PLIST}
	@${ECHO_CMD} "share/icons/megaglest.png" >> ${PLIST}
	@${ECHO_CMD} "@dirrm %%DATADIR%%" >> ${PLIST}

.if !defined(NOPORTDOCS)
	@cd ${WRKSRC}/docs && \
		${FIND} * -type f | ${SORT} | ${SED} -e 's|^|%%PORTDOCS%%%%DOCSDIR%%/|' >> ${PLIST} && \
			${FIND} * -type d | ${SORT} -r | ${SED} -e 's|^|%%PORTDOCS%%@dirrm %%DOCSDIR%%/|' >> ${PLIST}
	@${ECHO_CMD} "%%PORTDOCS%%@dirrm %%DOCSDIR%%" >> ${PLIST}
.endif

do-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/glest_factions
.for f in AUTHORS.data.txt README.data-license.txt cc-by-sa-3.0-unported.txt COPYRIGHT.data.txt
	${INSTALL_DATA} ${WRKSRC}/docs/${f} ${DOCSDIR}
.endfor
	(cd ${WRKSRC}/docs/glest_factions && ${COPYTREE_SHARE} "*" ${DOCSDIR}/glest_factions)
.endif
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/megaglest.desktop ${PREFIX}/share/applications/
	${INSTALL_DATA} ${WRKSRC}/megaglest.png ${PREFIX}/share/icons/

.for DIR in data maps scenarios techs tilesets tutorials
	${MKDIR} ${DATADIR}/${DIR}
	(cd ${WRKSRC}/${DIR} && ${COPYTREE_SHARE} "*" ${DATADIR}/${DIR})
.endfor

.include <bsd.port.mk>
