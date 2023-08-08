PORTNAME=		frontaccounting24
PORTVERSION=		2.4.11
DISTVERSIONSUFFIX=	${PORTVERSION}
CATEGORIES=		finance www
MASTER_SITES=		SF/${DIST_SUBDIR}/FrontAccounting%202.4/${PORTVERSION}
DISTNAME=		frontaccounting-${PORTVERSION}
DIST_SUBDIR=		frontaccounting

MAINTAINER=		james@elstone.net
COMMENT=		Simple, powerful system for the entire ERP chain
WWW=			https://www.frontaccounting.com/

LICENSE=		GPLv3+
LICENSE_FILE=		${WRKSRC}/doc/license.txt

USES=			cpe
USE_PHP+=		mysqli session ctype zlib

WRKSRC=			${WRKDIR}/${DIST_SUBDIR}
NO_BUILD=		yes
SUB_FILES=		pkg-deinstall pkg-message
PORTDOCSARGS=
DEFAULT_VERSIONS+=	php=8.0

OPTIONS_DEFINE=		APACHE LIGHTTPD NGINX NLS DOCS
OPTIONS_DEFAULT=	APACHE MYSQL_SERVER

OPTIONS_RADIO=		RG1
OPTIONS_RADIO_RG1=	MARIADB_CLIENT MYSQL_CLIENT MYSQL_SERVER PERCONA_CLIENT
RG1_DESC=		Database Connectivity

MARIADB_CLIENT_DESC=	MariaDB client connector support
PERCONA_CLIENT_DESC=	Percona client connector support
MYSQL_CLIENT_DESC=	MySQL client connector support
MYSQL_SERVER_DESC=	MySQL server support
NGINX_DESC=		NGINX web server

APACHE_USES=		apache:run php:web
LIGHTTPD_RUN_DEPENDS=	lighttpd:www/lighttpd
LIGHTTPD_USES=		php:web
NGINX_RUN_DEPENDS=	nginx:www/nginx
NGINX_USES=		php:web
MYSQL_SERVER_USES=	mysql:server
MYSQL_CLIENT_USES=	mysql:client
MARIADB_CLIENT_USES=	mysql:106m
PERCONA_CLIENT_USES=	mysql:57p
NLS_USES=		gettext

.include <bsd.port.options.mk>

.if !${PORT_OPTIONS:MAPACHE} && !${PORT_OPTIONS:MLIGHTTPD} && !{PORT_OPTIONS:MNGINX}
USES+=			php:cgi php:cli
.endif

.if ${PORT_OPTIONS:MMYSQL_SERVER} || ${PORT_OPTIONS:MMARIADB_CLIENT} || ${PORT_OPTIONS:MPERCONA_CLIENT}
USE_PHP+=		mysqli
.endif

.if !${PORT_OPTIONS:MDOCS}
PORTDOCSARGS=		'-not -path "./doc*"'
.endif

do-install:
			@${MKDIR} ${STAGEDIR}${WWWDIR}
			(cd ${WRKSRC} && ${COPYTREE_SHARE} . \
				${STAGEDIR}${WWWDIR} ${PORTDOCSARGS})

.include <bsd.port.mk>
