# Ports collection makefile for:  pear-install
# Date created:			  21 October 2002
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	pear-install
PORTVERSION=	${PHP_VERSION}
CATEGORIES=	devel www
MASTER_SITES=	# empty
DISTFILES=	# none
EXTRACT_ONLY=	# empty

MAINTAINER=	thierry@pompo.net

BUILD_DEPENDS=	${LOCALBASE}/bin/php-config:${PORTSDIR}/www/mod_php4
RUN_DEPENDS=	${LOCALBASE}/libexec/apache/libphp4.so:${PORTSDIR}/www/mod_php4

NO_BUILD=	yes

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/bin/php-config)
PHP_VERSION!=	${LOCALBASE}/bin/php-config --version
PHP_BASE!=	${LOCALBASE}/bin/php-config --prefix
.else
PHP_VERSION=	4.2.3
.endif
LPHP_LIB=	lib/php

PEARDIR=	${PHP_BASE}/${LPHP_LIB}

do-install:
	@${ECHO_MSG} "===>  Backuping the original PEAR from mod_php4 into ${PEARDIR}.DIST_PHP ..."
	@${MKDIR} ${PEARDIR}.DIST_PHP
	@${CP} -Rp ${PEARDIR}/* ${PEARDIR}.DIST_PHP

.include <bsd.port.post.mk>
