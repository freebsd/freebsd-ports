# New ports collection makefile for:   poweradmin
# Date created:        19 January 2005
# Whom:                geo
#
# $FreeBSD$
#

PORTNAME=		poweradmin
PORTVERSION=	1.2.7
CATEGORIES=		dns www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=		poweradmin

MAINTAINER=		grivat@sicfa.net
COMMENT=		A set of PHP-scripts to manage PowerDNS over the web

RUN_DEPENDS=	${LOCALBASE}/share/pear/DB.php:${PORTSDIR}/databases/pear-DB

USE_PHP=	mysql
WANT_PHP_WEB=	yes
WANT_PHP_PEAR=	yes
NO_BUILD=	yes
SUB_FILES=	pkg-message
SUB_LIST=	INSTALLDIR=${INSTALLDIR}

WEBOWN?=	www
WEBGRP?=	www
WWWDIR=		${PREFIX}/www
INSTALLDIR=	${WWWDIR}/poweradmin

do-install:
	${MKDIR} ${INSTALLDIR}
	cd ${WRKSRC}; ${FIND} . \
		| ${CPIO} -pdm -R ${WEBOWN}:${WEBGRP} ${INSTALLDIR}
		${MV} ${INSTALLDIR}/inc/config-block.inc.php  ${INSTALLDIR}/inc/config.inc.php.sample

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
