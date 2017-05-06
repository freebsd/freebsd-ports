# Created by: vanilla@
# $FreeBSD$

PORTNAME=	swoole
PORTVERSION=	1.9.10
CATEGORIES=	devel net

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	Asynchronous & concurrent & distributed networking framework

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		execinfo php:pecl ssl
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_PHP=	pcre

OPTIONS_DEFINE=	HTTP2 REDIS RING_BUFFER SOCKETS
HTTP2_LIB_DEPENDS=	libnghttp2.so:www/libnghttp2
HTTP2_CONFIGURE_ON=	--enable-http2 --enable-openssl
REDIS_LIB_DEPENDS=	libhiredis.so:databases/hiredis
REDIS_CONFIGURE_ON=	--enable-async-redis
RING_BUFFER_DESC=	Use ring buffer pool
RING_BUFFER_CONFIGURE_ON=	--enable-ringbuffer
SOCKETS_USE=		PHP=sockets:build
SOCKETS_DESC=	Use native php sockets extension
SOCKETS_CONFIGURE_ON=	--enable-sockets

.include <bsd.port.mk>
