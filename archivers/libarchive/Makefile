# New ports collection makefile for:	libarchive
# Date created:		23 March 2004
# Whom:			Greg Lewis <glewis@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	libarchive
PORTVERSION=	2004.04.08
CATEGORIES=	archivers devel
MASTER_SITES=	http://people.freebsd.org/~kientzle/libarchive/src/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/./-/g}
EXTRACT_SUFX=	.tgz

MAINTAINER=	glewis@FreeBSD.org
COMMENT=	Library to create and read several streaming archive formats

WRKSRC=		${WRKDIR}/${PORTNAME}
MAKE_FLAGS+=	INCLUDEDIR=${PREFIX}/include \
		LIBDIR=${PREFIX}/lib \
		MANDIR=${PREFIX}/man/man

PLIST_FILES=	include/archive.h \
		include/archive_entry.h \
		lib/libarchive.a
.if !defined(NOPROFILE)
PLIST_FILES+=	lib/libarchive_p.a
.endif

MANCOMPRESSED=	yes
MAN3=		archive.3 \
		archive_compression.3 \
		archive_compression_name.3 \
		archive_entry.3 \
		archive_entry_clear.3 \
		archive_entry_clone.3 \
		archive_entry_copy_stat.3 \
		archive_entry_dup.3 \
		archive_entry_free.3 \
		archive_entry_gname.3 \
		archive_entry_hardlink.3 \
		archive_entry_new.3 \
		archive_entry_pathname.3 \
		archive_entry_set_devmajor.3 \
		archive_entry_set_devminor.3 \
		archive_entry_set_gid.3 \
		archive_entry_set_gname.3 \
		archive_entry_set_hardlink.3 \
		archive_entry_set_mode.3 \
		archive_entry_set_pathname.3 \
		archive_entry_set_symlink.3 \
		archive_entry_set_tartype.3 \
		archive_entry_set_uid.3 \
		archive_entry_set_uname.3 \
		archive_entry_size.3 \
		archive_entry_stat.3 \
		archive_entry_symlink.3 \
		archive_entry_tartype.3 \
		archive_entry_uname.3 \
		archive_errno.3 \
		archive_error_string.3 \
		archive_format.3 \
		archive_format_name.3 \
		archive_read.3 \
		archive_read_data.3 \
		archive_read_data_into_buffer.3 \
		archive_read_data_into_file.3 \
		archive_read_data_skip.3 \
		archive_read_extract.3 \
		archive_read_finish.3 \
		archive_read_new.3 \
		archive_read_next_header.3 \
		archive_read_open.3 \
		archive_read_open_fd.3 \
		archive_read_open_file.3 \
		archive_read_set_bytes_per_block.3 \
		archive_read_support_compression_all.3 \
		archive_read_support_compression_bzip2.3 \
		archive_read_support_compression_gzip.3 \
		archive_read_support_compression_none.3 \
		archive_read_support_format_all.3 \
		archive_read_support_format_cpio.3 \
		archive_read_support_format_gnutar.3 \
		archive_read_support_format_tar.3 \
		archive_util.3 \
		archive_write.3 \
		archive_write_data.3 \
		archive_write_finish.3 \
		archive_write_header.3 \
		archive_write_new.3 \
		archive_write_open.3 \
		archive_write_open_fd.3 \
		archive_write_open_file.3 \
		archive_write_prepare.3 \
		archive_write_set_bytes_in_last_block.3 \
		archive_write_set_bytes_per_block.3 \
		archive_write_set_callbacks.3 \
		archive_write_set_compression_bzip2.3 \
		archive_write_set_compression_gzip.3 \
		archive_write_set_format_pax.3 \
		archive_write_set_format_ustar.3 \
		libarchive.3
MAN5=		tar.5

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502103
IGNORE=         is in the base system
.endif

.include <bsd.port.post.mk>
