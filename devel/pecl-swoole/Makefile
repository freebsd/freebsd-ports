PORTNAME=	swoole
DISTVERSION=	6.2.0
PORTREVISION=	0
CATEGORIES=	devel net

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	Asynchronous, concurrent, and distributed networking framework
WWW=		https://pecl.php.net/package/swoole

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=	i386 powerpc
NOT_FOR_ARCHS_REASON=	upstream drop 32 bits support

USES=		compiler:c11 localbase:ldflags php:build,pecl pkgconfig ssl

CONFIGURE_ARGS+=	--enable-mysqlnd \
			--enable-openssl

OPTIONS_DEFINE=		BROTLI CARES CURL FIREBIRD ODBC PGSQL SOCKETS SQLITE \
			SSH2 ZSTD
BROTLI_CONFIGURE_OFF=	--disable-brotli
BROTLI_CONFIGURE_ON=	--enable-brotli
BROTLI_LIB_DEPENDS=	libbrotlicommon.so:archivers/brotli
CARES_CONFIGURE_ON=	--enable-cares
CARES_LIB_DEPENDS=	libcares.so:dns/c-ares
CURL_CONFIGURE_ON=	--enable-swoole-curl
CURL_LIB_DEPENDS=	libcurl.so:ftp/curl
CURL_USE=		PHP=curl
FIREBIRD_CONFIGURE_ON=	--with-swoole-firebird
FIREBIRD_USE=		PHP=pdo:build
FIREBIRD_USES=		firebird
ODBC_CONFIGURE_OFF=	--without-swoole-odbc
ODBC_CONFIGURE_ON=	--with-swoole-odbc=unixODBC
ODBC_USE=		PHP=odbc:build
PGSQL_CONFIGURE_ON=	--enable-swoole-pgsql
PGSQL_USE=		PHP=pdo:build
PGSQL_USES=		pgsql
SOCKETS_CONFIGURE_ON=	--enable-sockets
SOCKETS_DESC=		Use native php sockets extension
SOCKETS_USE=		PHP=sockets:build
SQLITE_CONFIGURE_OFF=	--disable-swoole-sqlite
SQLITE_CONFIGURE_ON=	--enable-swoole-sqlite
SQLITE_USE=		PHP=sqlite3
SSH2_CONFIGURE_ON=	--with-swoole-ssh2
SSH2_DESC=		Enable SSH2 support
SSH2_LIB_DEPENDS=	libssh2.so:security/libssh2
ZSTD_CONFIGURE_OFF=	--disable-zstd
ZSTD_CONFIGURE_ON=	--enable-zstd
ZSTD_LIB_DEPENDS=	libzstd.so:archivers/zstd

.include <bsd.port.mk>
