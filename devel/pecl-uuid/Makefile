# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	uuid
PORTVERSION=	1.0.4
CATEGORIES=	devel pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DIST_SUBDIR=	PECL

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	UUID extension in PHP

LICENSE=	LGPL3

LIB_DEPENDS=	libuuid.so:misc/e2fsprogs-libuuid

USES=		tar:tgz
USE_PHP=	yes
USE_PHPEXT=	yes

.include <bsd.port.mk>
