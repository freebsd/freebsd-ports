# Created by: Gary Palmer <gpalmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cdb
PORTVERSION=	0.75
CATEGORIES=	databases
MASTER_SITES=	http://cr.yp.to/cdb/

MAINTAINER=	jlaffaye@FreeBSD.org
COMMENT=	A fast lookup database library & utilities

ALL_TARGET=	it

NO_STAGE=	yes
do-configure:
	@${MV} ${WRKSRC}/conf-home ${WRKSRC}/conf-home.orig
	${ECHO_CMD} ${PREFIX} > ${WRKSRC}/conf-home
	@${MV} ${WRKSRC}/conf-cc ${WRKSRC}/conf-cc.orig
	${ECHO_CMD} ${CC} ${CFLAGS} > ${WRKSRC}/conf-cc
	@${MV} ${WRKSRC}/conf-ld ${WRKSRC}/conf-ld.orig
	${ECHO_CMD} ${CC} -s > ${WRKSRC}/conf-ld

do-install:
.for file in cdbdump cdbget cdbmake cdbstats cdbtest
	${INSTALL_PROGRAM} ${WRKSRC}/${file} ${PREFIX}/bin
.endfor
.for file in cdbmake-12 cdbmake-sv
	${INSTALL_SCRIPT} ${WRKSRC}/${file} ${PREFIX}/bin
.endfor

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64
CFLAGS+=	-fPIC
.endif

.include <bsd.port.post.mk>
