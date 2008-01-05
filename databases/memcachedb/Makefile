# New ports collection makefile for:	memcachedb
# Date created:		2007-09-22
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	memcachedb
PORTVERSION=	0.1.0
CATEGORIES=	databases
MASTER_SITES=	http://memcachedb.googlecode.com/files/

MAINTAINER=	gslin@gslin.org
COMMENT=	Distributed storage system designed for persistent

LIB_DEPENDS=	event-1.3e:${PORTSDIR}/devel/libevent

USE_BDB=	46+
USE_DOS2UNIX=	YES
USE_RC_SUBR=	${PORTNAME}

.include <bsd.port.pre.mk>

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

.include <bsd.port.post.mk>
