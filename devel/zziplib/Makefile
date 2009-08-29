# New ports collection makefile for:   zziplib
# Date created:        3 January 2001
# Whom:                George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	zziplib
PORTVERSION=	0.13.58
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}13/${PORTVERSION}

MAINTAINER=	ale@FreeBSD.org
COMMENT=	A library to provide transparent read access to zipped files

USE_BZIP2=	yes
USE_GNOME=	gnomehack pkgconfig
GNU_CONFIGURE=	yes
USE_PYTHON_BUILD=	yes
USE_LDCONFIG=	yes

PORTSCOUT=	limit:^0\.

MAN3=		__zzip_fetch_disk_trailer.3 __zzip_parse_root_directory.3 __zzip_try_open.3 \
		zzip_close.3 zzip_closedir.3 zzip_compr_str.3 zzip_dir_alloc.3 \
		zzip_dir_alloc_ext_io.3 zzip_dir_close.3 zzip_dir_fdopen.3 \
		zzip_dir_fdopen_ext_io.3 zzip_dir_free.3 zzip_dir_open.3 \
		zzip_dir_open_ext_io.3 zzip_dir_read.3 zzip_dir_real.3 zzip_dir_stat.3 \
		zzip_dirfd.3 zzip_dirhandle.3 zzip_disk_buffer.3 zzip_disk_close.3 zzip_disk_entry_fopen.3 \
		zzip_disk_entry_strdup_comment.3 zzip_disk_entry_strdup_name.3 \
		zzip_disk_entry_to_data.3 zzip_disk_entry_to_file_header.3 \
		zzip_disk_fclose.3 zzip_disk_feof.3 zzip_disk_findfile.3 \
		zzip_disk_findfirst.3 zzip_disk_findmatch.3 zzip_disk_findnext.3 \
		zzip_disk_fopen.3 zzip_disk_fread.3 zzip_disk_init.3 zzip_disk_mmap.3 \
		zzip_disk_munmap.3 zzip_disk_new.3 zzip_disk_open.3 \
		zzip_entry_data_offset.3 zzip_entry_fclose.3 zzip_entry_feof.3 \
		zzip_entry_ffile.3 zzip_entry_findfile.3 zzip_entry_findfirst.3 \
		zzip_entry_findmatch.3 zzip_entry_findnext.3 zzip_entry_fopen.3 \
		zzip_entry_fread.3 zzip_entry_fread_file_header.3 zzip_entry_free.3 \
		zzip_entry_strdup_name.3 zzip_errno.3 zzip_error.3 zzip_fclose.3 \
		zzip_file_close.3 zzip_file_open.3 zzip_file_read.3 zzip_file_real.3 \
		zzip_file_stat.3 zzip_fopen.3 zzip_fread.3 zzip_freopen.3 zzip_fstat.3 \
		zzip_get_default_io.3 zzip_inflate_init.3 zzip_init_io.3 zzip_open.3 \
		zzip_open_ext_io.3 zzip_open_shared_io.3 zzip_opendir.3 \
		zzip_opendir_ext_io.3 zzip_read.3 zzip_readdir.3 zzip_realdir.3 \
		zzip_realfd.3 zzip_rewind.3 zzip_rewinddir.3 zzip_seek.3 zzip_seekdir.3 \
		zzip_seterror.3 zzip_strerror.3 zzip_strerror_of.3 zzip_tell.3 \
		zzip_telldir.3

.include <bsd.port.mk>
