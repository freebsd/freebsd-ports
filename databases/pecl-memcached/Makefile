# New ports collection makefile for:	pecl-memcached
# Date created:		2009-01-31
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	memcached
PORTVERSION=	1.0.0
CATEGORIES=	databases
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	gslin@gslin.org
COMMENT=	PHP extension for interfacing with memcached via libmemcached library

BUILD_DEPENDS=	${LOCALBASE}/bin/pear:${PORTSDIR}/devel/pear
LIB_DEPENDS=	memcached:${PORTSDIR}/databases/libmemcached
RUN_DEPENDS=	${LOCALBASE}/bin/pear:${PORTSDIR}/devel/pear

PHP_MODNAME=	memcached
USE_PHP=	json session
USE_PHPEXT=	yes
USE_PHPIZE=	yes
USE_PHP_BUILD=	yes
CONFIGURE_ARGS+=--with-libmemcached-dir=${LOCALBASE}

post-install:
	@${CAT} ${WRKSRC}/EXPERIMENTAL

.include <bsd.port.mk>
