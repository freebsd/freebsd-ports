# Ports collection makefile for:	fget
# Date created:				27 January 2002
# Whom:					Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	fget
PORTVERSION=	1.3.3
CATEGORIES=	ftp www
MASTER_SITES=	ftp://ftp.feep.net/pub/software/fget/

MAINTAINER=	demon@FreeBSD.org
COMMENT=	A commandline tool for mirroring remote files via FTP

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

MAN1=	fget.1
MAN3=	ftp_chdir.3 ftp_close.3 ftp_connect.3 ftp_fd.3 ftp_getcwd.3 ftp_glob.3 \
	ftp_lseek.3 ftp_mkdir.3 ftp_open.3 ftp_opendir.3 ftp_read.3 \
	ftp_readlink.3 ftp_realpath.3 ftp_remove.3 ftp_rename.3 ftp_rmdir.3 \
	ftp_set_options.3 ftp_site.3 ftp_stat.3 ftp_systype.3 ftp_type.3 \
	ftp_unlink.3 ftp_url_parse.3 ftp_whoami.3 ftp_write.3 libfget.3
MLINKS=	ftp_connect.3 ftp_login.3 ftp_connect.3 ftp_quit.3 \
	ftp_fd.3 ftp_data_fd.3 ftp_glob.3 ftp_globfree.3 \
	ftp_opendir.3 ftp_readdir.3 ftp_opendir.3 ftp_rewinddir.3 \
	ftp_opendir.3 ftp_telldir.3 ftp_opendir.3 ftp_seekdir.3 \
	ftp_opendir.3 ftp_closedir.3 ftp_set_options.3 ftp_get_options.3 \
	ftp_site.3 ftp_site_open.3 ftp_stat.3 ftp_lstat.3 \
	ftp_systype.3 ftp_status.3 ftp_whoami.3 ftp_get_host.3

.include <bsd.port.mk>
