# New ports collection makefile for:	pecl-rar
# Date created:			2006/09/07
# Whom:				chinsan <chinsan.tw@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	rar
PORTVERSION=	2.0.0
CATEGORIES=	archivers pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	A PECL extension to create and read rar files

LICENSE=	PHP301

USE_PHP=	spl
USE_PHPEXT=	yes
USE_PHP_BUILD=	yes
IGNORE_WITH_PHP=4

CONFIGURE_ARGS=	--enable-rar

.include <bsd.port.mk>
