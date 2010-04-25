# Ports collection makefile for:  pear-VFS
# Date created:			  04 April 2004
# Whom:				  Thierry Thomas (<thierry@FreeBSD.org>)
#
# $FreeBSD$
#

PORTNAME=	VFS
PORTVERSION=	0.3.0
CATEGORIES=	devel pear

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PEAR Virtual File System API

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear \
		${PEARDIR}/Log/null.php:${PORTSDIR}/sysutils/pear-Log
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PHP=	gettext

FILES=		VFS.php VFS/Browser.php VFS/GC.php VFS/ListItem.php \
		VFS/Object.php VFS/file.php VFS/ftp.php VFS/horde.php \
		VFS/kolab.php \
		VFS/musql.php VFS/sql.php VFS/sql_file.php VFS/smb.php \
		VFS/ssh2.php
DATA=		muvfs.sql vfs.oci8.sql vfs.pgsql.sql vfs.sql
_DATADIR=	data/VFS
SCRIPTFILES=	vfs.php

post-patch:
	@${MV} ${WRKSRC}/scripts/VFS/vfs.php ${WRKSRC}/pear-vfs.php
	@${MV} ${WRKSRC}/lib/* ${WRKSRC}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
