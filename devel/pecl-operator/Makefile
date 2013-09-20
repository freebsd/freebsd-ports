# Created by: Alexander Zhuravlev <zaa@zaa.pp.ru>
# $FreeBSD$

PORTNAME=	operator
PORTVERSION=	0.3
CATEGORIES=	devel pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DISTNAME=	operator-${PORTVERSION}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PHP extension that provides operator overloading for PHP objects

LICENSE=	PHP30

USE_PHP=	yes
USE_PHPEXT=	yes
DEFAULT_PHP_VER?=	53
PHP_MODNAME=	${PORTNAME}

NO_STAGE=	yes
post-extract::
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
