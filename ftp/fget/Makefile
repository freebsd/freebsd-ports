# Ports collection makefile for:	fget
# Date created:				27 January 2002
# Whom:					Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	fget
PORTVERSION=	1.2.6
CATEGORIES=	ftp www
MASTER_SITES=	ftp://ftp-dev.cso.uiuc.edu/pub/fget/

MAINTAINER=	demon@FreeBSD.org

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

MAN1=	fget.1
MAN3=	ftp_connect.3 ftp_login.3 ftp_chdir.3 ftp_quit.3 ftp_fd.3 \
	ftp_data_fd.3 ftp_get_flags.3 ftp_set_flags.3 ftp_get_cache_max_size.3 \
	ftp_set_cache_max_size.3 ftp_get_cache_expire_time.3 \
	ftp_set_cache_expire_time.3 ftp_get_host.3 ftp_get_io_timeout.3 \
	ftp_set_io_timeout.3 ftp_whoami.3 ftp_glob.3 ftp_globfree.3 ftp_open.3 \
	ftp_read.3 ftp_write.3 ftp_lseek.3 ftp_close.3 ftp_opendir.3 \
	ftp_readdir.3 ftp_rewinddir.3 ftp_telldir.3 ftp_seekdir.3 \
	ftp_closedir.3 ftp_parse_url.3 ftp_readlink.3 ftp_realpath.3 \
	ftp_rename.3 ftp_remove.3 ftp_mkdir.3 ftp_rmdir.3 ftp_getcwd.3 \
	ftp_set_sendhook.3 ftp_set_recvhook.3 ftp_site.3 ftp_systype.3 \
	ftp_status.3 ftp_stat.3 ftp_lstat.3

.include <bsd.port.mk>
