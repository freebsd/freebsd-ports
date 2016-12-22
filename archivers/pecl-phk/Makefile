# Created by: Ditesh Shashikant Gathani <ditesh@gathani.org>
# $FreeBSD$

PORTNAME=	phk
PORTVERSION=	3.0.1
PORTREVISION=	1
CATEGORIES=	archivers pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DIST_SUBDIR=	PECL

MAINTAINER=	joneum@bsdproject.de
COMMENT=	PHK is a PHP-oriented package/archive system

LICENSE=	PHP301

USES=		php:ext tar:tgz
USE_PHP=	hash:build
IGNORE_WITH_PHP=	70

CONFIGURE_ARGS=	--enable-phk

.include <bsd.port.mk>
