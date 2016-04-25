# Created by: Ditesh Shashikant Gathani <ditesh@gathani.org>
# $FreeBSD$

PORTNAME=	phk
PORTVERSION=	3.0.1
CATEGORIES=	archivers pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DIST_SUBDIR=	PECL

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PHK is a PHP-oriented package/archive system

LICENSE=	PHP301

BROKEN_powerpc64=	Does not build

USES=		tar:tgz
USE_PHP=	hash
USE_PHP_BUILD=	yes
USE_PHPEXT=	yes
IGNORE_WITH_PHP=	70

CONFIGURE_ARGS=	--enable-phk

.include <bsd.port.mk>
