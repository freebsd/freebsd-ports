# Ports collection makefile for:  pear-VFS
# Date created:			  04 April 2004
# Whom:				  Thierry Thomas (<thierry@FreeBSD.org>)
#
# $FreeBSD$
#

PORTNAME=	VFS
PORTVERSION=	0.0.4
CATEGORIES=	devel pear

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PEAR Virtual File System API

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS}

FILES=		VFS.php
VFS_FILES=	Browser.php GC.php ListItem.php Object.php	\
		file.php ftp.php musql.php sql.php sql_file.php

pre-everything::
.for cat_file in ${VFS_FILES}
FILES+=		VFS/${cat_file}
.endfor

post-extract:
	@${MKDIR} ${WRKSRC}/VFS
.for cat_file in ${VFS_FILES}
	@${MV} ${WRKSRC}/${cat_file} ${WRKSRC}/VFS
.endfor
	@${MV} ${WRKDIR}/VFS.php ${WRKSRC}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
