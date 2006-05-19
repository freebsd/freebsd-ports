# Ports collection makefile for:  pecl-PDO
# Date created:			  2005-09-10
# Whom:				  Alexander Zhuravlev <zaa@zaa.pp.ru>
#
# $FreeBSD$
#

PORTNAME=	PDO
DISTVERSION=	1.0.3
CATEGORIES=	databases www
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	zaa@zaa.pp.ru
COMMENT=	PHP Data Objects Interface

USE_PHP=	zlib
USE_PHPEXT=	yes
DEFAULT_PHP_VER=5
PHP_MODNAME=	pdo

.include <bsd.port.pre.mk>

.if ${PHP_VER} == 4
IGNORE=		requires PHP version 5.0.3 or higher
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
