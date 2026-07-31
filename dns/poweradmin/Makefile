PORTNAME=	poweradmin
DISTVERSIONPREFIX=	v
DISTVERSION=	4.4.0
PORTREVISION=	2
CATEGORIES=	dns
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Web-based control panel for PowerDNS
WWW=		https://www.poweradmin.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

FLAVORS=	sqlite3 mysql pgsql
FLAVOR?=	${FLAVORS:[1]}
mysql_PKGNAMESUFFIX=	-mysql
pgsql_PKGNAMESUFFIX=	-pgsql
sqlite3_PKGNAMESUFFIX=	-sqlite3

USES=	php
USE_GITHUB=	yes
USE_PHP=	filter gettext intl mbstring session tokenizer xml
.if ${FLAVOR} == mysql
USES+=		mysql
USE_PHP+=	pdo_mysql
.endif
.if ${FLAVOR} == pgsql
USES+=		pgsql
USE_PHP+=	pdo_pgsql
.endif
.if ${FLAVOR} == sqlite3
USES+=		sqlite
USE_PHP+=	pdo_sqlite
.endif

NO_ARCH=	yes
NO_BUILD=	yes

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS LDAP

LDAP_USES=	ldap
LDAP_USE=	PHP=ldap

post-extract:
	@${RM} ${WRKSRC}/docker-entrypoint.sh
	@${RM} ${WRKSRC}/DOCKER-SECRETS.md
	@${RM} ${WRKSRC}/DOCKER.md
	@${RM} ${WRKSRC}/Dockerfile

post-extract-DOCS-off:
	@${RM} ${WRKSRC}/README.md

post-patch:
	@${REINPLACE_CMD} -e 's|%%WWWDIR%%|${WWWDIR}|g; s|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/caddy.conf.example
	@${REINPLACE_CMD} -e 's|%%WWWDIR%%|${WWWDIR}|g; s|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/nginx.conf.example

pre-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/caddy.conf.example ${STAGEDIR}${EXAMPLESDIR}/caddy.conf.example
	${INSTALL_DATA} ${WRKSRC}/nginx.conf.example ${STAGEDIR}${EXAMPLESDIR}/nginx.conf.example
	@${RM} ${WRKSRC}/caddy.conf.example
	@${RM} ${WRKSRC}/nginx.conf.example

pre-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}
	@${RM} ${WRKSRC}/README.md

do-install:
	@${MKDIR} ${STAGEDIR}${WWWSDIR}
	${FIND} ${WRKSRC}  -name '*.orig' -delete -o -name '*.bak'  -delete
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})

post-install:
	@${ECHO_CMD} "@owner www" >> ${TMPPLIST}
	@${ECHO_CMD} "@group www" >> ${TMPPLIST}
	${FIND} -s ${STAGEDIR}${WWWDIR} -not -type d | ${SORT} | \
		${SED} -e 's#^${STAGEDIR}${PREFIX}/##' | \
		${SED} -E -e '/sample$$/ s#^#@sample #' >> ${TMPPLIST}
	${ECHO_CMD} share/examples/${PORTNAME}/caddy.conf.example >> ${TMPPLIST}
	${ECHO_CMD} share/examples/${PORTNAME}/nginx.conf.example >> ${TMPPLIST}
	${FIND} -s ${STAGEDIR}${WWWDIR} -type d | ${SORT} | \
		${SED} -e 's#^${STAGEDIR}${PREFIX}/#@dir #' >> ${TMPPLIST}

.include <bsd.port.mk>
