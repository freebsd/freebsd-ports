# New ports collection makefile for:	libzip
# Date created:		2006-03-20
# Whom:			Alexander Zhuravlev <zaa@zaa.pp.ru>
#
# $FreeBSD$
#

PORTNAME=	libzip
PORTVERSION=	0.6.1
CATEGORIES=	archivers devel
MASTER_SITES=	http://www.nih.at/libzip/

MAINTAINER=	zaa@zaa.pp.ru
COMMENT=	A C library for reading, creating, and modifying zip archives

GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
USE_GNOME=	gnomehack pkgconfig

PLIST_FILES=	bin/zipcmp \
		bin/zipmerge \
		include/zip.h \
		lib/libzip.a \
		lib/libzip.la \
		lib/libzip.so \
		lib/libzip.so.0 \
		libdata/pkgconfig/libzip.pc

MAN1=		zipcmp.1 \
		zipmerge.1

MAN3=		libzip.3 \
		zip_add.3 \
		zip_close.3 \
		zip_delete.3 \
		zip_error_get.3 \
		zip_error_get_sys_type.3 \
		zip_error_to_str.3 \
		zip_errors.3 \
		zip_fclose.3 \
		zip_file_error_get.3 \
		zip_file_strerror.3 \
		zip_fopen.3 \
		zip_fopen_index.3 \
		zip_fread.3 \
		zip_get_name.3 \
		zip_get_num_files.3 \
		zip_name_locate.3 \
		zip_open.3 \
		zip_rename.3 \
		zip_replace.3 \
		zip_source_buffer.3 \
		zip_source_file.3 \
		zip_source_filep.3 \
		zip_source_free.3 \
		zip_source_function.3 \
		zip_source_zip.3 \
		zip_stat.3 \
		zip_stat_index.3 \
		zip_strerror.3 \
		zip_unchange.3 \
		zip_unchange_all.3

.include <bsd.port.mk>
