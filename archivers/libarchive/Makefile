# New ports collection makefile for:	libarchive
# Date created:		23 March 2004
# Whom:			Greg Lewis <glewis@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	libarchive
PORTVERSION=	3.0.4
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	archivers
MASTER_SITES=	http://cloud.github.com/downloads/${PORTNAME}/${PORTNAME}/

MAINTAINER=	glewis@FreeBSD.org
COMMENT=	Library to create and read several streaming archive formats

OPTIONS_DEFINE=	LIBXML2 NETTLE
OPTIONS_DEFAULT=	LIBXML2

LIBXML2_DESC=	Support writing xar via libxml2
NETTLE_DESC=	Use Nettle instead of OpenSSL

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_GNOME=	gnomehack
PATCH_STRIP=	-p1

CONFIGURE_ARGS+=	--without-expat

PLIST_FILES=	bin/bsdcpio \
		bin/bsdtar \
		include/archive.h \
		include/archive_entry.h \
		lib/libarchive.a \
		lib/libarchive.la \
		lib/libarchive.so \
		lib/libarchive.so.12 \
		libdata/pkgconfig/libarchive.pc

MANCOMPRESSED=	no
MAN1=		bsdcpio.1 \
		bsdtar.1
MAN3=		archive_entry.3 \
		archive_entry_acl.3 \
		archive_entry_linkify.3 \
		archive_entry_paths.3 \
		archive_entry_perms.3 \
		archive_entry_stat.3 \
		archive_entry_time.3 \
		archive_read.3 \
		archive_read_disk.3 \
		archive_read_set_options.3 \
		archive_util.3 \
		archive_write.3 \
		archive_write_disk.3 \
		archive_write_set_options.3 \
		libarchive.3 \
		libarchive_internals.3
MAN5=		cpio.5 \
		libarchive-formats.5 \
		mtree.5 \
		tar.5

CFLAGS+=	"-I${LOCALBASE}/include"
CPPFLAGS+=	"-I${LOCALBASE}/include"
LDFLAGS+=	"-L${LOCALBASE}/lib"

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLIBXML2}
USE_GNOME+=	libxml2
CONFIGURE_ARGS+=	--with-xml2
.else
CFLAGS+=	-DHAVE_BSDXML_H=1
LDFLAGS+=	-lbsdxml
CONFIGURE_ARGS+=	--without-xml2
.endif

.if ${PORT_OPTIONS:MNETTLE}
LIB_DEPENDS+=	nettle.4:${PORTSDIR}/security/nettle
CONFIGURE_ARGS+=	--without-openssl --with-nettle
.else
USE_OPENSSL=	yes
CONFIGURE_ARGS+=	--with-openssl --without-nettle
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800505 || (${OSVERSION} >= 900000 && ${OSVERSION} < 900012)
LIB_DEPENDS+=	lzma.5:${PORTSDIR}/archivers/xz
.endif

check:
	(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} check)

.include <bsd.port.post.mk>
