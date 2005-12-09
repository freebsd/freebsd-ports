# Ports collection makefile for:  pear-VFS
# Date created:			  04 April 2004
# Whom:				  Thierry Thomas (<thierry@FreeBSD.org>)
#
# $FreeBSD$
#

PORTNAME=	VFS
PORTVERSION=	0.0.5
CATEGORIES=	devel pear

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PEAR Virtual File System API

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear \
		${PEARDIR}/Log.php:${PORTSDIR}/sysutils/pear-Log
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PHP=	gettext

FILES=		VFS.php VFS/Browser.php VFS/GC.php VFS/ListItem.php \
		VFS/Object.php VFS/file.php VFS/ftp.php VFS/musql.php \
		VFS/sql.php VFS/sql_file.php
DATA=		muvfs.sql vfs.oci8.sql vfs.pgsql.sql vfs.sql
SCRIPTFILES=	vfs.php

post-patch:
	@${MV} ${WRKSRC}/scripts/vfs.php ${WRKSRC}/pear-vfs.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
