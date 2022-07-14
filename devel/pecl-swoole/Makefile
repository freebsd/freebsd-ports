# Created by: vanilla@

PORTNAME=	swoole
PORTVERSION=	4.8.11
CATEGORIES=	devel net

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	Asynchronous, concurrent, and distributed networking framework

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c11 localbase:ldflags php:pecl ssl
USE_PHP=	hash:build pcre
IGNORE_WITH_PHP=	82

CONFIGURE_ARGS+=	--enable-mysqlnd

OPTIONS_DEFINE=		CARES CURL HTTP2 JSON SOCKETS
CARES_LIB_DEPENDS=	libcares.so:dns/c-ares
CARES_CONFIGURE_ON=	--enable-cares
HTTP2_CONFIGURE_ON=	--enable-http2 \
			--enable-openssl
SOCKETS_USE=		PHP=sockets:build
SOCKETS_DESC=		Use native php sockets extension
SOCKETS_CONFIGURE_ON=	--enable-sockets
CURL_LIB_DEPENDS=	libcurl.so:ftp/curl
CURL_CONFIGURE_ON=	--enable-swoole-curl
CURL_USE=		PHP=curl
JSON_CONFIGURE_ON=	--enable-swoole-json
JSON_USE=		PHP=json:build

.include <bsd.port.mk>
