# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	jsonc
PORTVERSION=	1.3.10
CATEGORIES=	devel

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	PECL extension for JSON manipulation

LICENSE=	PHP301

USES=		php:pecl pkgconfig
CONFIGURE_ARGS=	--with-jsonc
MAKE_ARGS=	EXTRA_CFLAGS=-DCOMPILE_DL_JSON=1
IGNORE_WITH_PHP=70 71 72
CONFLICTS_INSTALL=	php54-json-5* php55-json-5* php5-json-5*

.include <bsd.port.mk>
