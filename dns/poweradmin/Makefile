# New ports collection makefile for:   poweradmin
# Date created:        19 January 2005                                       
# Whom:                geo
#
# $FreeBSD$
#

PORTNAME=	poweradmin
PORTVERSION=	2.1.2
CATEGORIES=	dns www
MASTER_SITES=	https://www.poweradmin.org/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	eg@fbsd.lt
COMMENT=	A set of PHP-scripts to manage PowerDNS over the web

USE_PHP=	gettext
WANT_PHP_WEB=	yes
NO_BUILD=	yes
PEARDIR=	${PREFIX}/share/pear

OPTIONS=	POSTGRESQL "Use PostgreSQL database instead of MySQL" off

SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

.if defined(WITH_POSTGRESQL)
USE_PHP+=	pgsql
RUN_DEPENDS+=	${PEARDIR}/MDB2/Driver/pgsql.php:${PORTSDIR}/databases/pear-MDB2_Driver_pgsql
.else
USE_PHP+=	mysql
RUN_DEPENDS+=	${PEARDIR}/MDB2/Driver/mysql.php:${PORTSDIR}/databases/pear-MDB2_Driver_mysql
.endif

post-extract:
	@cd ${WRKSRC} && ${RM} -rf "install"

do-install:
	@${CP} -r ${WRKSRC} ${PREFIX}/www/${PORTNAME}
	${CP} ${WWWDIR}/inc/config-me.inc.php  ${WWWDIR}/inc/config.inc.php

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
