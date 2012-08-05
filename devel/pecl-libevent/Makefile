# New ports collection makefile for:	pecl-libevent
# Date created:			14 November 2010
# Whom:				Ilya Bakulin <webmaster@kibab.com>
#
# $FreeBSD$
#

PORTNAME=	libevent
PORTVERSION=	0.0.5
CATEGORIES=	devel
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	webmaster@kibab.com
COMMENT=	Libevent extension for PHP

LICENSE=	PHP301

LIB_DEPENDS=	event:${PORTSDIR}/devel/libevent

USE_PHP=	yes
USE_PHP_BUILD=	yes
USE_PHPIZE=	yes
USE_PHPEXT=	yes
PHP_MODNAME=	libevent
IGNORE_WITH_PHP=4

.include <bsd.port.mk>
