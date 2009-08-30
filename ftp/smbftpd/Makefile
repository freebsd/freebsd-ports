# New ports collection makefile for:	smbftpd
# Date created:		2006-01-22
# Whom:			Jui-Nan Lin <jnlin@csie.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	smbftpd
PORTVERSION=	2.2
CATEGORIES=	ftp
MASTER_SITES=	SF/${PORTNAME}/SmbFTPD/${PORTVERSION}	\
		http://www.twbsd.org/download/download.php?file=smbftpd/


MAINTAINER=	jnlin@csie.nctu.edu.tw
COMMENT=	FTP daemon using Samba-like share management mechanism

OPTIONS=	MYSQL "Users database is a MySQL database" off \
		PGSQL "Users database is a PostgreSQL database" off \
		SSL "Enable SSL/TLS support" off \
		ICONV "Enable codepage to unicode conversion for UTF-8 FTP" off

HAS_CONFIGURE=	yes
MAKE_ENV=	OSTYPE=FreeBSD
CONFIGURE_ARGS=	"--prefix=${PREFIX}"

USE_PERL5=	yes
USE_RC_SUBR=	smbftpd.sh

.include <bsd.port.pre.mk>

.if defined(WITH_MYSQL)
USE_MYSQL=	yes
CONFIGURE_ARGS+=	"--with-mysql"
.endif

.if defined(WITH_PGSQL)
USE_PGSQL=	yes
CONFIGURE_ARGS+=	"--with-pgsql"
.endif

.if defined(WITH_ICONV)
USE_ICONV=	yes
CONFIGURE_ARGS+=	"--with-iconv"
.endif

.if defined(WITH_SSL)
CONFIGURE_ARGS+=	"--with-ssl"
.endif

.include <bsd.port.post.mk>
