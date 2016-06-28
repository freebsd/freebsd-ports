# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	test_helpers
PORTVERSION=	1.1.0
PORTREVISION=	1
CATEGORIES=	devel pear
MASTER_SITES=	http://pear.phpunit.de/get/
PKGNAMEPREFIX=	pecl-

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	Extension to ease testing of PHP code

LICENSE=	BSD3CLAUSE

CONFIGURE_ARGS=	--enable-test-helpers
USES=		php:ext tar:tgz
SUB_FILES=	pkg-message
IGNORE_WITH_PHP=	70

.include <bsd.port.mk>
