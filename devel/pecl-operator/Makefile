# New ports collection makefile for:	pecl-operator
# Date created:			2006-01-31
# Whom:				Alexander Zhuravlev <zaa@zaa.pp.ru>
#
# $FreeBSD$
#

PORTNAME=	operator
PORTVERSION=	0.3
CATEGORIES=	devel pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DISTNAME=	operator-${PORTVERSION}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	zaa@zaa.pp.ru
COMMENT=	PHP extension that provides operator overloading for PHP objects

USE_PHP=	yes
USE_PHPEXT=	yes
DEFAULT_PHP_VER=	5
BROKEN_WITH_PHP=	4
PHP_MODNAME=	${PORTNAME}

post-extract::
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
