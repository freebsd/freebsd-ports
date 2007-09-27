# New ports collection makefile for:	memcachedb
# Date created:		2007-09-22
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	memcachedb
PORTVERSION=	0.0.2
CATEGORIES=	databases
MASTER_SITES=	http://memcachedb.googlecode.com/files/

MAINTAINER=	gslin@gslin.org
COMMENT=	Distributed storage system designed for persistent

LIB_DEPENDS=	event:${PORTSDIR}/devel/libevent

USE_BDB=	42+
USE_RC_SUBR=	${PORTNAME}
USE_DOS2UNIX=	YES

post-patch:
	${REINPLACE_CMD} \
		-e "s,%%BDB_LIB_NAME%%,${BDB_LIB_NAME}," \
		-e "s,%%BDB_LIB_DIR%%,${BDB_LIB_DIR}," \
		-e "s,%%BDB_INCLUDE_DIR%%,${BDB_INCLUDE_DIR}," \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/memcachedb ${PREFIX}/sbin
	${MKDIR} /var/db/memcachedb || ${TRUE}
	${CHOWN} nobody:nobody /var/db/memcachedb

.include <bsd.port.mk>
