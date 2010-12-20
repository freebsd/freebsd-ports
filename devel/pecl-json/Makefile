# New ports collection makefile for:	pecl-json
# Date created:			2006-03-17
# Whom:				Alexander Zhuravlev <zaa@zaa.pp.ru>
#
# $FreeBSD$
#

PORTNAME=	json
PORTVERSION=	1.2.1
CATEGORIES=	devel pear www
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DISTNAME=	json-${PORTVERSION}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PHP extension for JSON (JavaScript Object Notation) serialization for PHP 4

LICENSE=	PHP301

USE_PHP=	yes
USE_PHPEXT=	yes
DEFAULT_PHP_VER?=4
IGNORE_WITH_PHP=5 52

.include <bsd.port.mk>
