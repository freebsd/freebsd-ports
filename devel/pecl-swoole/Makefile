PORTNAME=	swoole
PORTVERSION=	5.0.3
CATEGORIES=	devel net

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	Asynchronous, concurrent, and distributed networking framework
WWW=		https://pecl.php.net/package/swoole

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c11 localbase:ldflags php:build,pecl ssl
IGNORE_WITH_PHP=	83

CONFIGURE_ARGS+=	--enable-mysqlnd

OPTIONS_DEFINE=		BROTLI CARES CURL HTTP2 JSON PGSQL SOCKETS
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
JSON_USES=		php:build
PGSQL_CONFIGURE_ON=	--enable-swoole-pgsql
PGSQL_USES=		pgsql
BROTLI_CONFIGURE_ON=	--enable-brotli
BROTLI_LIB_DEPENDS=	libbrotlicommon.so:archivers/brotli

.include <bsd.port.mk>
