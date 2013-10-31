# Created by: wen
# $FreeBSD$

PORTNAME=	mongo
PORTVERSION=	1.4.4
CATEGORIES=	databases pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PECL classes for Mongo Database Driver

LICENSE=	AL2

USE_PHP=	spl
USE_PHP_BUILD=	yes
USE_PHPIZE=	yes
USE_PHPEXT=	yes
CONFIGURE_ARGS=	--enable-mongo
SUB_FILES=	pkg-message

.include <bsd.port.mk>
