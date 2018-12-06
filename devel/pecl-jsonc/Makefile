# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	jsonc
PORTVERSION=	1.3.10
CATEGORIES=	devel

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	PECL extension for JSON manipulation

DEPRECATED=	Works only with EOL php 5.6
EXPIRATION_DATE=	2018-12-30

LICENSE=	PHP301

USES=		php:pecl pkgconfig
CONFIGURE_ARGS=	--with-jsonc
MAKE_ARGS=	EXTRA_CFLAGS=-DCOMPILE_DL_JSON=1
IGNORE_WITH_PHP=71 72 73
CONFLICTS_INSTALL=	php54-json-5* php55-json-5* php5-json-5*

.include <bsd.port.mk>
