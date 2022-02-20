# Created by: Gasol Wu <gasol.wu@gmail.com>

PORTNAME=	eio
DISTVERSION=	2.0.4
CATEGORIES=	devel

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	Provides interface to the libeio library

LICENSE=	PHP301

# Remove these when upgraded to 3.0.0 which supports php8
DEPRECATED=	Requires php 7.4 which is set to expire on 2022-11-29
EXPIRATION_DATE=2022-11-28

USES=		php:pecl
IGNORE_WITH_PHP=	80 81

CONFIGURE_ARGS=	--enable-eio

.include <bsd.port.mk>
