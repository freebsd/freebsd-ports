PORTNAME=	swoole
DISTVERSION=	6.1.0
PORTREVISION=	1
CATEGORIES=	devel net

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	Asynchronous, concurrent, and distributed networking framework
WWW=		https://pecl.php.net/package/swoole

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=	i386 powerpc
NOT_FOR_ARCHS_REASON=	upstream drop 32 bits support

USES=		compiler:c11 localbase:ldflags php:build,pecl pkgconfig ssl
IGNORE_WITH_PHP=	85

CONFIGURE_ARGS+=	--enable-mysqlnd --enable-openssl

OPTIONS_DEFINE=		BROTLI CARES CURL ODBC PGSQL SOCKETS SQLITE ZSTD
CARES_LIB_DEPENDS=	libcares.so:dns/c-ares
CARES_CONFIGURE_ON=	--enable-cares
SOCKETS_USE=		PHP=sockets:build
SOCKETS_DESC=		Use native php sockets extension
SOCKETS_CONFIGURE_ON=	--enable-sockets
CURL_LIB_DEPENDS=	libcurl.so:ftp/curl
CURL_CONFIGURE_ON=	--enable-swoole-curl
CURL_USE=		PHP=curl
PGSQL_CONFIGURE_ON=	--enable-swoole-pgsql
PGSQL_USES=		pgsql
PGSQL_USE=		PHP=pdo:build
BROTLI_CONFIGURE_ON=	--enable-brotli
BROTLI_CONFIGURE_OFF=	--disable-brotli
BROTLI_LIB_DEPENDS=	libbrotlicommon.so:archivers/brotli
ZSTD_CONFIGURE_ON=	--enable-zstd
ZSTD_CONFIGURE_OFF=	--disable-zstd
ZSTD_LIB_DEPENDS=	libzstd.so:archivers/zstd
ODBC_CONFIGURE_ON=	--with-swoole-odbc=unixODBC
ODBC_CONFIGURE_OFF=	--without-swoole-odbc
ODBC_USE=		PHP=odbc:build
SQLITE_CONFIGURE_ON=	--enable-swoole-sqlite
SQLITE_CONFIGURE_OFF=	--disable-swoole-sqlite
SQLITE_USE=		PHP=sqlite3

.include <bsd.port.mk>
