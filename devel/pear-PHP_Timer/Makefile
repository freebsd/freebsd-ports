# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	PHP_Timer
PORTVERSION=	1.0.4
CATEGORIES=	devel pear
MASTER_SITES=	http://pear.phpunit.de/get/
PKGNAMEPREFIX=	pear-

MAINTAINER=	joneum@bsdproject.de
COMMENT=	Utility class for timing

BUILD_DEPENDS=	${PEARDIR}/.channels/pear.phpunit.de.reg:devel/pear-channel-phpunit
RUN_DEPENDS=	${PEARDIR}/.channels/pear.phpunit.de.reg:devel/pear-channel-phpunit

DEPRECATED=	This is only one PHP-File. To install read: https://github.com/sebastianbergmann/php-timer
EXPIRATION_DATE=2017-03-28

USES=	pear
PEAR_CHANNEL=	phpunit

.include <bsd.port.mk>
