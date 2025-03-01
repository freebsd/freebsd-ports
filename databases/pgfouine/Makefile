PORTNAME=	pgfouine
PORTVERSION=	1.2
CATEGORIES=	databases
MASTER_SITES=	https://ftp.postgresql.org/pub/projects/pgFoundry/pgfouine/pgFouine/pgFouine${PORTVERSION}/

MAINTAINER=	pea@raveland.org
COMMENT=	PostgreSQL log analyzer
WWW=		http://pgfouine.projects.postgresql.org/

DEPRECATED=	Upstream project disappeared in 2010
EXPIRATION_DATE=2025-03-31

USES+=		php

NO_BUILD=	yes
USE_PHP=	gd

OPTIONS_DEFINE=	DOCS

pre-configure:
	${REINPLACE_CMD} -e 's,/usr/bin/php,${LOCALBASE}/bin/php,g;' \
		-e 's,!!PREFIX!!,${PREFIX},g' \
		${WRKSRC}/pgfouine.php ${WRKSRC}/pgfouine_vacuum.php
	${FIND} -d ${WRKSRC} -type d -name 'CVS' -exec ${RM} -r {} \;

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pgfouine.php ${STAGEDIR}${PREFIX}/bin/pgfouine
	${INSTALL_SCRIPT} ${WRKSRC}/pgfouine_vacuum.php ${STAGEDIR}${PREFIX}/bin/pgfouine_vacuum
	${MKDIR} ${STAGEDIR}${DATADIR}/include
	${INSTALL_DATA} ${WRKSRC}/version.php ${STAGEDIR}${DATADIR}
	@cd ${WRKSRC}/include && ${COPYTREE_SHARE} \* ${STAGEDIR}${DATADIR}/include/
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/AUTHORS	${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog	${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/THANKS	${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/rpm-specific/sources/pgfouine-tutorial.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
