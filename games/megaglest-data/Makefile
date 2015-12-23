# Created by: Sven Moeller <smoeller@nichthelfer.de>
# $FreeBSD$

PORTNAME=	megaglest
PORTVERSION=	3.9.0
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}_${PORTVERSION}/
PKGNAMESUFFIX=	-data
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}

MAINTAINER=	rnejdl@ringofsaturn.com
COMMENT=	MegaGlest data files

BROKEN=		unfetchable
USES=		dos2unix tar:xz
DOS2UNIX_GLOB=	*.log *.ini *.html *.txt *.lng
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
PLIST=		${WRKDIR}/pkg-plist
BASEDOCS=	AUTHORS.data.txt README.data-license.txt \
		cc-by-sa-3.0-unported.txt COPYRIGHT.data.txt
PORTDOCS=	*

pre-install:
	${RM} -f ${PLIST}
.for DIR in data maps scenarios techs tilesets tutorials
	@cd ${WRKSRC} && \
		${FIND} ${DIR} -type d -empty | ${SORT} -r | ${SED} -e 's|^|@dir %%DATADIR%%/|' >> ${PLIST} && \
		${FIND} ${DIR} -type f | ${SORT} | ${SED} -e 's|^|%%DATADIR%%/|' >> ${PLIST}
.endfor
	@${ECHO_CMD} "share/applications/megaglest.desktop" >> ${PLIST}
	@${ECHO_CMD} "share/icons/megaglest.png" >> ${PLIST}

do-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/glest_factions
	${INSTALL_DATA} ${BASEDOCS:S,^,${WRKSRC}/docs/,} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/docs/glest_factions && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/glest_factions)

	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/megaglest.desktop ${STAGEDIR}${PREFIX}/share/applications/
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons
	${INSTALL_DATA} ${WRKSRC}/megaglest.png ${STAGEDIR}${PREFIX}/share/icons/

.for DIR in data maps scenarios techs tilesets tutorials
	${MKDIR} ${STAGEDIR}${DATADIR}/${DIR}
	(cd ${WRKSRC}/${DIR} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/${DIR})
.endfor

.include <bsd.port.mk>
