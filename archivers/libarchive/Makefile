# $FreeBSD$

PORTNAME=	libarchive
PORTVERSION=	3.1.2
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	archivers
MASTER_SITES=	http://libarchive.org/downloads/

MAINTAINER=	glewis@FreeBSD.org
COMMENT=	Library to create and read several streaming archive formats

OPTIONS_DEFINE=	LIBXML2 LZO NETTLE
OPTIONS_DEFAULT=LIBXML2 LZO

LIBXML2_DESC=	Support writing xar via libxml2
LZO_DESC=	Support lzo compression via liblzo2
NETTLE_DESC=	Use Nettle instead of OpenSSL

USES=		libtool pathfix
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
PATCH_STRIP=	-p1

CONFIGURE_ARGS+=	--without-expat

PLIST_FILES=	bin/bsdcpio \
		bin/bsdtar \
		include/archive.h \
		include/archive_entry.h \
		lib/libarchive.a \
		lib/libarchive.so \
		lib/libarchive.so.13 \
		lib/libarchive.so.13.1.2 \
		libdata/pkgconfig/libarchive.pc \
		man/man1/bsdcpio.1.gz \
		man/man1/bsdtar.1.gz \
		man/man3/archive_entry.3.gz \
		man/man3/archive_entry_acl.3.gz \
		man/man3/archive_entry_linkify.3.gz \
		man/man3/archive_entry_paths.3.gz \
		man/man3/archive_entry_perms.3.gz \
		man/man3/archive_entry_stat.3.gz \
		man/man3/archive_entry_time.3.gz \
		man/man3/archive_read.3.gz \
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
		man/man3/libarchive.3.gz \
		man/man3/libarchive_changes.3.gz \
		man/man3/libarchive_internals.3.gz \
		man/man5/cpio.5.gz \
		man/man5/libarchive-formats.5.gz \
		man/man5/mtree.5.gz \
		man/man5/tar.5.gz

CFLAGS+=	"-I${LOCALBASE}/include"
CPPFLAGS+=	"-I${LOCALBASE}/include"
LDFLAGS+=	"-L${LOCALBASE}/lib"

LIBXML2_USE=		GNOME=libxml2
LIBXML2_CONFIGURE_WITH=	xml2
LIBXML2_CFLAGS=		-DHAVE_BSDXML_H=1
LIBXML2_LDFLAGS=	-lbsdxml

LZO_LIB_DEPENDS=	liblzo2.so:${PORTSDIR}/archivers/lzo2
LZO_CONFIGURE_WITH=	lzo2

NETTLE_LIB_DEPENDS=	libnettle.so:${PORTSDIR}/security/nettle
NETTLE_CONFIGURE_WITH=	nettle
NETTLE_CONFIGURE_ON=	--without-openssl
NETTLE_USE_OFF=		OPENSSL=yes
NETTLE_CONFIGURE_OFF=	--with-openssl

check:
	(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} check)

.include <bsd.port.mk>
