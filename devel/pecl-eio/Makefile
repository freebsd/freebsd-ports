PORTNAME=	eio
DISTVERSION=	2.0.4
CATEGORIES=	devel

PATCH_SITES=	https://github.com/rosmanov/pecl-eio/commit/
PATCHFILES=	dd8ef9359ea01bcd84b7b13d7ef1ef3b047a099a.patch:-p1

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	Provides interface to the libeio library
WWW=		https://pecl.php.net/package/eio

LICENSE=	PHP301

# Remove these when upgraded to 3.0.0 which supports php8
DEPRECATED=	Requires php 7.4 which is set to expire on 2022-11-29
EXPIRATION_DATE=2022-11-28

USES=		php:pecl
IGNORE_WITH_PHP=	80 81 82

CONFIGURE_ARGS=	--enable-eio

.include <bsd.port.mk>
