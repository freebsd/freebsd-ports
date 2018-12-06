# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	test_helpers
PORTVERSION=	1.1.0
PORTREVISION=	2
CATEGORIES=	devel pear
MASTER_SITES=	http://pear.phpunit.de/get/
PKGNAMEPREFIX=	pecl-

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	Extension to ease testing of PHP code

DEPRECATED=	Works only with EOL php 5.6
EXPIRATION_DATE=	2018-12-30

LICENSE=	BSD3CLAUSE

CONFIGURE_ARGS=	--enable-test-helpers
USES=		php:zend tar:tgz
SUB_FILES=	pkg-message
IGNORE_WITH_PHP=	71 72 73
# This needs to be loaded *after* devel/pecl-xdebug
PHP_MOD_PRIO=	30

.include <bsd.port.mk>
