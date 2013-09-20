# Created by: Pierre-Emmanuel Andre <pea@raveland.org>
# $FreeBSD$

PORTNAME=	pgfouine
PORTVERSION=	1.2
CATEGORIES=	databases
MASTER_SITES=	http://pgfoundry.org/frs/download.php/2575/ \
		http://pgfouine.projects.postgresql.org/releases/

MAINTAINER=	pea@raveland.org
COMMENT=	PostgreSQL log analyzer

NO_BUILD =	Yes
USE_PHP=	gd pcre

NO_STAGE=	yes
pre-configure:
	${REINPLACE_CMD} -e 's,/usr/bin/php,${LOCALBASE}/bin/php,g;' \
		-e 's,!!PREFIX!!,${PREFIX},g' \
		${WRKSRC}/pgfouine.php ${WRKSRC}/pgfouine_vacuum.php
	${FIND} -d ${WRKSRC} -type d -name 'CVS' -exec ${RM} -rf {} \;

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pgfouine.php ${PREFIX}/bin/pgfouine
	${INSTALL_SCRIPT} ${WRKSRC}/pgfouine_vacuum.php ${PREFIX}/bin/pgfouine_vacuum
	${MKDIR} ${DATADIR}/include
	${INSTALL_DATA} ${WRKSRC}/version.php ${DATADIR}
	@cd ${WRKSRC}/include && ${COPYTREE_SHARE} \* ${DATADIR}/include/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/AUTHORS	${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog 	${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/THANKS 	${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/rpm-specific/sources/pgfouine-tutorial.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
