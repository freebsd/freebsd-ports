# Created by: Chin-San Huang <chinsan.tw@gmail.com>
# $FreeBSD$

PORTNAME=	rar
PORTVERSION=	3.0.2
PORTREVISION=	1
CATEGORIES=	archivers pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DIST_SUBDIR=	PECL

MAINTAINER=	joneum@bsdproject.de
COMMENT=	PECL extension to create and read RAR files

LICENSE=	PHP301

USES=		php:ext tar:tgz
USE_PHP=	spl:build
IGNORE_WITH_PHP=	70


CONFIGURE_ARGS=	--enable-rar

.include <bsd.port.mk>
