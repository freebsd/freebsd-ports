# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	jsonc
PORTVERSION=	1.3.7
CATEGORIES=	devel
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DIST_SUBDIR=	PECL

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	PECL extension for JSON manipulation

LICENSE=	PHP301

LIB_DEPENDS=	libjson-c.so:devel/json-c

USES=		pkgconfig tar:tgz
CONFIGURE_ARGS=	--with-jsonc --with-libjson
MAKE_ARGS=	EXTRA_CFLAGS=-DCOMPILE_DL_JSON=1
USE_PHP=	yes
USE_PHPEXT=	yes
IGNORE_WITH_PHP=70
CONFLICTS_INSTALL=	php54-json-5* php55-json-5* php5-json-5*

.include <bsd.port.mk>
