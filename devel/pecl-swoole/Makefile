# Created by: vanilla@
# $FreeBSD$

PORTNAME=	swoole
PORTVERSION=	4.5.2
CATEGORIES=	devel net

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	Asynchronous & concurrent & distributed networking framework

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c11 localbase:ldflags php:pecl ssl
USE_PHP=	hash:build pcre

CONFIGURE_ARGS+=	--enable-mysqlnd

OPTIONS_DEFINE=	HTTP2 SOCKETS
HTTP2_LIB_DEPENDS=	libnghttp2.so:www/libnghttp2
HTTP2_CONFIGURE_ON=	--enable-http2 --enable-openssl
SOCKETS_USE=	PHP=sockets:build
SOCKETS_DESC=	Use native php sockets extension
SOCKETS_CONFIGURE_ON=	--enable-sockets

.include <bsd.port.mk>
