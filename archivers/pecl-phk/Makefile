# Created by: Ditesh Shashikant Gathani <ditesh@gathani.org>
# $FreeBSD$

PORTNAME=	phk
PORTVERSION=	2.1.0
CATEGORIES=	archivers pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DIST_SUBDIR=	PECL

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PHK is a PHP-oriented package/archive system

LICENSE=	PHP301

USES=		tar:tgz
USE_PHP=	yes
USE_PHP_BUILD=	yes
USE_PHPEXT=	yes
IGNORE_WITH_PHP=	56

CONFIGURE_ARGS=	--enable-phk

.include <bsd.port.mk>
