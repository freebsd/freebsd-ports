PORTNAME=		frontaccounting
DISTVERSION=		2.4.20
CATEGORIES=		finance www
MASTER_SITES=		SF/${DIST_SUBDIR}/FrontAccounting%202.4/${DISTVERSION}
DIST_SUBDIR=		frontaccounting

MAINTAINER=		james@elstone.net
COMMENT=		Simple, powerful system for the entire ERP chain
WWW=			https://www.frontaccounting.com/

LICENSE=		GPLv3+
LICENSE_FILE=		${WRKSRC}/doc/license.txt

USES=			cpe
USE_PHP=		ctype iconv mysqli session zlib

NO_BUILD=		yes
SUB_FILES=		pkg-deinstall pkg-message

WRKSRC=			${WRKDIR}/${DIST_SUBDIR}

OPTIONS_DEFINE=		APACHE LIGHTTPD NGINX NLS DOCS
OPTIONS_DEFAULT=	APACHE REMOTE_DB
OPTIONS_SINGLE=		RG1
OPTIONS_SINGLE_RG1=	REMOTE_DB MARIADB_CLIENT MYSQL_CLIENT MYSQL_SERVER

MARIADB_CLIENT_DESC=	Install MariaDB 10.11 client
MYSQL_CLIENT_DESC=	Install MySQL client
MYSQL_SERVER_DESC=	Install MySQL server
NGINX_DESC=		NGINX web server
REMOTE_DB_DESC=		Use remote database (PHP mysqli only)
RG1_DESC=		Database connectivity

APACHE_USES=		apache:run php:web
DOCS_VARS_OFF=		PORTDOCSARGS='-not -path "./doc*"'
LIGHTTPD_RUN_DEPENDS=	lighttpd:www/lighttpd
LIGHTTPD_USES=		php:web
MARIADB_CLIENT_USES=	mysql:1011m,client
MYSQL_CLIENT_USES=	mysql:client
MYSQL_SERVER_USES=	mysql:server
NGINX_RUN_DEPENDS=	nginx:www/nginx
NGINX_USES=		php:web
NLS_USES=		gettext

.include <bsd.port.options.mk>

.if !${PORT_OPTIONS:MAPACHE} && !${PORT_OPTIONS:MLIGHTTPD} && !${PORT_OPTIONS:MNGINX}
USES+=			php:cgi,cli
.endif

do-install:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . \
		${STAGEDIR}${WWWDIR} ${PORTDOCSARGS})
	@${MKDIR} ${STAGEDIR}${WWWDIR}/company/examples/reporting
	${INSTALL_DATA} ${FILESDIR}/email_template.php \
		${STAGEDIR}${WWWDIR}/company/examples/reporting/email_template.php

.include <bsd.port.mk>
