# New ports collection makefile for:	megaglest-data
# Date created:				2010-11-12
# Whom:					Sven Moeller <smoeller@nichthelfer.de>
#
# $FreeBSD$
#

PORTNAME=	megaglest
PORTVERSION=	3.4.0
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/current_release/
PKGNAMESUFFIX=	-data
DISTNAME=	${PORTNAME}-fixed${PKGNAMESUFFIX:S/-/_/}-${PORTVERSION}
EXTRACT_SUFX=	.7z

MAINTAINER=	smoeller@nichthelfer.de
COMMENT=	MegaGlest data files

EXTRACT_DEPENDS=7z:${PORTSDIR}/archivers/p7zip

USE_DOS2UNIX=	*.log *.ini *.html *.txt *.lng
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}_game

PLIST=		${WRKDIR}/pkg-plist

do-extract:
	@${MKDIR} ${WRKSRC}
	@cd ${WRKSRC} && \
		${LOCALBASE}/bin/7z x ${DISTDIR}/${DISTFILES} >/dev/null

pre-install:
	@${ECHO_CMD} "%%DATADIR%%/megaglest.ico" >> ${PLIST}

.for DIR in data maps scenarios techs tilesets tutorials
	@cd ${WRKSRC} && \
		${FIND} ${DIR} -type f | ${SORT} | ${SED} -e 's|^|%%DATADIR%%/|' >> ${PLIST} && \
			${FIND} ${DIR} -type d | ${SORT} -r | ${SED} -e 's|^|@dirrmtry %%DATADIR%%/|' >> ${PLIST}
.endfor
	@${ECHO_CMD} "@dirrmtry %%DATADIR%%" >> ${PLIST}

.if !defined(NOPORTDOCS)
	@cd ${WRKSRC}/docs && \
		${FIND} * -type f | ${SORT} | ${SED} -e 's|^|%%PORTDOCS%%%%DOCSDIR%%/|' >> ${PLIST} && \
			${FIND} * -type d | ${SORT} -r | ${SED} -e 's|^|%%PORTDOCS%%@dirrmtry %%DOCSDIR%%/|' >> ${PLIST}
	@${ECHO_CMD} "%%PORTDOCS%%@dirrmtry %%DOCSDIR%%" >> ${PLIST}
.endif

do-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/glest_factions
.for f in AUTHORS CHANGELOG LICENSE README data_license.txt data_license_readme.txt
	${INSTALL_DATA} ${WRKSRC}/docs/${f} ${DOCSDIR}
.endfor
	(cd ${WRKSRC}/docs/glest_factions && ${COPYTREE_SHARE} "*" ${DOCSDIR}/glest_factions)
.endif
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/megaglest.ico ${DATADIR}

.for DIR in data maps scenarios techs tilesets tutorials
	${MKDIR} ${DATADIR}/${DIR}
	(cd ${WRKSRC}/${DIR} && ${COPYTREE_SHARE} "*" ${DATADIR}/${DIR})
.endfor

.include <bsd.port.mk>
