# Created by: wen
# $FreeBSD$

PORTNAME=	mongo
PORTVERSION=	1.6.14
CATEGORIES=	databases pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DIST_SUBDIR=	PECL

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	PECL classes for Mongo Database Driver

LICENSE=	APACHE20

BUILD_DEPENDS=	re2c>=0.13.4:devel/re2c

USES=		php:ext tar:tgz
USE_PHP=	spl:build
CONFIGURE_ARGS=	--enable-mongo
SUB_FILES=	pkg-message
IGNORE_WITH_PHP=	70

.include <bsd.port.mk>
