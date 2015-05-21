# Created by: Janky Jay <ek@purplehat.org>
# $FreeBSD$

PORTNAME=	frontaccounting
DISTVERSION=	2.3.24
CATEGORIES=	finance www
MASTER_SITES=	SF/${PORTNAME}/FrontAccounting-2.3/${PORTVERSION}

MAINTAINER=	ek@purplehat.org
COMMENT=	Simple, powerful system for the entire ERP chain

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/doc/license.txt

USES=		cpe
USE_PHP+=	mysql mysqli openssl session hash ctype zlib

WRKSRC=		${WRKDIR}/${PORTNAME}

NO_BUILD=	yes
SUB_FILES=	pkg-deinstall pkg-message
PORTDOCSARGS=

OPTIONS_DEFINE=	APACHE LIGHTTPD MYSQL_SERVER NLS DOCS
OPTIONS_DEFAULT=	APACHE MYSQL_SERVER

MYSQL_SERVER_DESC=	MySQL server support
LIGHTTPD_RUN_DEPENDS=	lighttpd:${PORTSDIR}/www/lighttpd
MYSQL_SERVER_USE=	MYSQL=server
APACHE_USE=		APACHE_RUN=22+
NLS_USES=		gettext

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MAPACHE}
WANT_PHP_WEB=yes
.endif

.if !${PORT_OPTIONS:MDOCS}
PORTDOCSARGS=	'-not -path "./doc*"'
.endif

.if !${PORT_OPTIONS:MMYSQL_SERVER}
USE_MYSQL=	client
.endif

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . \
		${STAGEDIR}${WWWDIR} ${PORTDOCSARGS})

.include <bsd.port.mk>
