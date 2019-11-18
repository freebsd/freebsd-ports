# Created by: Janky Jay <ek@purplehat.org>
# $FreeBSD$

PORTNAME=	frontaccounting
DISTVERSION=	2.3.25
CATEGORIES=	finance www
MASTER_SITES=	SF/${PORTNAME}/FrontAccounting-2.3/${PORTVERSION}

MAINTAINER=	ek@purplehat.org
COMMENT=	Simple, powerful system for the entire ERP chain

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/doc/license.txt

USES=		cpe
USE_PHP+=	mysqli openssl session hash ctype zlib

WRKSRC=		${WRKDIR}/${PORTNAME}

NO_BUILD=	yes
SUB_FILES=	pkg-deinstall pkg-message
PORTDOCSARGS=

OPTIONS_DEFINE=	APACHE LIGHTTPD NGINX MYSQL_SERVER NLS DOCS
OPTIONS_DEFAULT=	APACHE MYSQL_SERVER

MYSQL_SERVER_DESC=	MySQL server support
NGINX_DESC=		NGINX web server

APACHE_USES=		apache:run,2.2+ php:web
LIGHTTPD_RUN_DEPENDS=	lighttpd:www/lighttpd
LIGHTTPD_USES=		php:web
NGINX_RUN_DEPENDS=	nginx:www/nginx
NGINX_USES=		php:web
MYSQL_SERVER_USES=	mysql:server
NLS_USES=		gettext

.include <bsd.port.options.mk>

.if !${PORT_OPTIONS:MAPACHE} && !${PORT_OPTIONS:MLIGHTTPD} && !{PORT_OPTIONS:MNGINX}
USES+=		php
.endif

.if !${PORT_OPTIONS:MDOCS}
PORTDOCSARGS=	'-not -path "./doc*"'
.endif

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . \
		${STAGEDIR}${WWWDIR} ${PORTDOCSARGS})

.include <bsd.port.mk>
