# ports collection makefile for:	Constant DataBase
# Date created:				18th July 1998
# Whom:					Gary Palmer <gpalmer@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	cdb
PORTVERSION=	0.75
CATEGORIES=	databases
MASTER_SITES=	http://cr.yp.to/cdb/

MAINTAINER=	ports@FreeBSD.org

ALL_TARGET=	it
INSTALL_TARGET=	setup

do-configure:
	@${MV} ${WRKSRC}/conf-home ${WRKSRC}/conf-home.orig
	${ECHO} ${PREFIX} > ${WRKSRC}/conf-home
	@${MV} ${WRKSRC}/conf-cc ${WRKSRC}/conf-cc.orig
	${ECHO} ${CC} ${CFLAGS} > ${WRKSRC}/conf-cc
	@${MV} ${WRKSRC}/conf-ld ${WRKSRC}/conf-ld.orig
	${ECHO} ${CC} -s > ${WRKSRC}/conf-ld

post-install:
	${INSTALL_DATA} ${WRKSRC}/cdb.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/cdb.a ${PREFIX}/lib/libcdb.a

.include <bsd.port.mk>
