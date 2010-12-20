# New ports collection makefile for:	pecl-phk
# Date created:			21 Jan 2007
# Whom:				Ditesh Shashikant Gathani <ditesh@gathani.org>
#
# $FreeBSD$
#

PORTNAME=	phk
PORTVERSION=	1.4.0
CATEGORIES=	archivers pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PHK is a PHP-oriented package/archive system

LICENSE=	PHP301

USE_PHP=	yes
USE_PHP_BUILD=	yes
USE_PHPEXT=	yes
IGNORE_WITH_PHP=4

CONFIGURE_ARGS=	--enable-phk

.include <bsd.port.mk>
