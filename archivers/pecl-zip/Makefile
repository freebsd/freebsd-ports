# New ports collection makefile for:	pecl-zip
# Date created:			9 Jul 2004
# Whom:				Alex Dupre <ale@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	zip
PORTVERSION=	1.9.0
CATEGORIES=	archivers pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	ale@FreeBSD.org
COMMENT=	A PECL extension to create and read zip files (PHP 4 only)

LICENSE=	PHP301

USE_PHP=	pcre
USE_PHP_BUILD=	yes
USE_PHPEXT=	yes
DEFAULT_PHP_VER=4
IGNORE_WITH_PHP=5 52

CONFIGURE_ARGS=	--enable-zip --with-zlib-dir=/usr

.include <bsd.port.mk>
