PORTNAME=	libarchive
DISTVERSION=	3.5.2
PORTEPOCH=	1
CATEGORIES=	archivers
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/v${DISTVERSION}/ \
		https://libarchive.org/downloads/

MAINTAINER=	glewis@FreeBSD.org
COMMENT=	Library to create and read several streaming archive formats

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libexpat.so:textproc/expat2

OPTIONS_DEFINE=	LZ4 LZO ZSTD
OPTIONS_DEFAULT=LZ4 ZSTD OPENSSL

OPTIONS_RADIO=	CRYPTO
OPTIONS_RADIO_CRYPTO=	OPENSSL MBEDTLS NETTLE

CRYPTO_DESC=	Crypto and hashing support
NETTLE_DESC=	Crypto support via Nettle

USES=		cpe iconv libtool localbase:ldflags pathfix tar:xz
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

INSTALL_TARGET=	install-strip
TEST_TARGET=	check

CONFIGURE_ARGS=	--disable-static --without-xml2

PLIST_FILES=	bin/bsdcat \
		bin/bsdcpio \
		bin/bsdtar \
		include/archive.h \
		include/archive_entry.h \
		lib/libarchive.so \
		lib/libarchive.so.13 \
		lib/libarchive.so.1${PORTVERSION} \
		libdata/pkgconfig/libarchive.pc \
		man/man1/bsdcat.1.gz \
		man/man1/bsdcpio.1.gz \
		man/man1/bsdtar.1.gz \
		man/man3/archive_entry.3.gz \
		man/man3/archive_entry_acl.3.gz \
		man/man3/archive_entry_linkify.3.gz \
		man/man3/archive_entry_misc.3.gz \
		man/man3/archive_entry_paths.3.gz \
		man/man3/archive_entry_perms.3.gz \
		man/man3/archive_entry_stat.3.gz \
		man/man3/archive_entry_time.3.gz \
		man/man3/archive_read.3.gz \
		man/man3/archive_read_add_passphrase.3.gz \
		man/man3/archive_read_data.3.gz \
		man/man3/archive_read_disk.3.gz \
		man/man3/archive_read_extract.3.gz \
		man/man3/archive_read_filter.3.gz \
		man/man3/archive_read_format.3.gz \
		man/man3/archive_read_free.3.gz \
		man/man3/archive_read_header.3.gz \
		man/man3/archive_read_new.3.gz \
		man/man3/archive_read_open.3.gz \
		man/man3/archive_read_set_options.3.gz \
		man/man3/archive_util.3.gz \
		man/man3/archive_write.3.gz \
		man/man3/archive_write_blocksize.3.gz \
		man/man3/archive_write_data.3.gz \
		man/man3/archive_write_disk.3.gz \
		man/man3/archive_write_filter.3.gz \
		man/man3/archive_write_finish_entry.3.gz \
		man/man3/archive_write_format.3.gz \
		man/man3/archive_write_free.3.gz \
		man/man3/archive_write_header.3.gz \
		man/man3/archive_write_new.3.gz \
		man/man3/archive_write_open.3.gz \
		man/man3/archive_write_set_options.3.gz \
		man/man3/archive_write_set_passphrase.3.gz \
		man/man3/libarchive.3.gz \
		man/man3/libarchive_changes.3.gz \
		man/man3/libarchive_internals.3.gz \
		man/man5/cpio.5.gz \
		man/man5/libarchive-formats.5.gz \
		man/man5/mtree.5.gz \
		man/man5/tar.5.gz

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

MBEDTLS_LIB_DEPENDS=	libmbedtls.so:security/mbedtls
MBEDTLS_CONFIGURE_WITH=	mbedtls

.include <bsd.port.pre.mk>

.if empty(ICONV_LIB)
CONFIGURE_ENV+=	ac_cv_header_localcharset_h=no \
		ac_cv_func_locale_charset=no \
		ac_cv_lib_charset_locale_charset=no
.endif

.include <bsd.port.post.mk>
