# Ports collection makefile for:  pear-Console_Getopt
# Date created:			  23 October 2002
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	Console_Getopt
PORTVERSION=	1.0
CATEGORIES=	devel www
MASTER_SITES=	http://pear.php.net/get/
PKGNAMEPREFIX=	pear-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PEAR

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${PEARDIR}.DIST_PHP:${PORTSDIR}/devel/pear-install
RUN_DEPENDS=	${PEARDIR}.DIST_PHP:${PORTSDIR}/devel/pear-install \
		${LOCALBASE}/bin/php:${PORTSDIR}/lang/php4

NO_BUILD=	yes

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/bin/php-config)
PHP_BASE!=	${LOCALBASE}/bin/php-config --prefix
.endif
LPHP_LIB=	lib/php
PEARDIR=	${PHP_BASE}/${LPHP_LIB}
PLIST_SUB=	PEARDIR=${LPHP_LIB}

do-install:
	@${MV} ${PEARDIR}/Console/Getopt.php ${PEARDIR}/Console/Getopt.php.dist
	@${CP} -Rp ${WRKSRC}/Console/Getopt.php ${PEARDIR}/Console
	@${CHOWN} -R root:wheel ${PEARDIR}/Console/Getopt.php

.include <bsd.port.post.mk>
