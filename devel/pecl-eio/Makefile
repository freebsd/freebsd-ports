PORTNAME=	eio
DISTVERSION=	3.0.0RC4
CATEGORIES=	devel

PATCH_SITES=	https://github.com/rosmanov/pecl-eio/commit/
PATCHFILES=	dd8ef9359ea01bcd84b7b13d7ef1ef3b047a099a.patch:-p1

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	Provides interface to the libeio library
WWW=		https://pecl.php.net/package/eio

LICENSE=	PHP301

USES=		php:pecl

CONFIGURE_ARGS=	--enable-eio

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD
CFLAGS+=	-Wno-error=int-conversion
.endif

.include <bsd.port.post.mk>
