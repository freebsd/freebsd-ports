PORTNAME=	libarchive
DISTVERSION=	3.8.1
PORTEPOCH=	1
CATEGORIES=	archivers
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/v${DISTVERSION}/ \
		https://libarchive.org/downloads/

MAINTAINER=	glewis@FreeBSD.org
COMMENT=	Library to create and read several streaming archive formats
WWW=		https://libarchive.org/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libexpat.so:textproc/expat2

USES=		cpe iconv libtool localbase:ldflags pkgconfig tar:xz
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip
TEST_TARGET=	check

CONFIGURE_ARGS=	--disable-static --without-xml2

OPTIONS_DEFINE=	LZ4 LZO ZSTD
OPTIONS_DEFAULT=LZ4 ZSTD OPENSSL

OPTIONS_RADIO=	CRYPTO
OPTIONS_RADIO_CRYPTO=	OPENSSL MBEDTLS NETTLE

CRYPTO_DESC=	Crypto and hashing support
NETTLE_DESC=	Crypto support via Nettle

LZO_LIB_DEPENDS=	liblzo2.so:archivers/lzo2
LZO_CONFIGURE_WITH=	lzo2

LZ4_LIB_DEPENDS=	liblz4.so:archivers/liblz4
LZ4_CONFIGURE_WITH=	lz4

ZSTD_LIB_DEPENDS=	libzstd.so:archivers/zstd
ZSTD_CONFIGURE_WITH=	zstd

NETTLE_LIB_DEPENDS=	libnettle.so:security/nettle
NETTLE_CONFIGURE_WITH=	nettle

OPENSSL_USES=		ssl
OPENSSL_CONFIGURE_WITH=	openssl
OPENSSL_CONFIGURE_OFF=	--without-openssl

MBEDTLS_LIB_DEPENDS=	libmbedtls.so:security/mbedtls2
MBEDTLS_CONFIGURE_WITH=	mbedtls

.include <bsd.port.pre.mk>

.if empty(ICONV_LIB)
CONFIGURE_ENV+=	ac_cv_header_localcharset_h=no \
		ac_cv_func_locale_charset=no \
		ac_cv_lib_charset_locale_charset=no
.endif

.include <bsd.port.post.mk>
