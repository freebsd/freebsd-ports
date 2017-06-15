# Created by: Ilya Bakulin <webmaster@kibab.com>
# $FreeBSD$

PORTNAME=	libevent
PORTVERSION=	0.1.0
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DIST_SUBDIR=	PECL

MAINTAINER=	webmaster@kibab.com
COMMENT=	Libevent extension for PHP

LICENSE=	PHP301

LIB_DEPENDS=	libevent.so:devel/libevent

USES=	php:ext tar:tgz

IGNORE_WITH_PHP=	70 71

.include <bsd.port.mk>
