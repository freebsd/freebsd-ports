# Created by: Gary Palmer <gpalmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cdb
PORTVERSION=	0.75
CATEGORIES=	databases
MASTER_SITES=	http://cr.yp.to/cdb/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fast lookup database library & utilities

ALL_TARGET=	it

CFLAGS_amd64=	-fPIC

do-configure:
	@${MV} ${WRKSRC}/conf-home ${WRKSRC}/conf-home.orig
	${ECHO_CMD} ${PREFIX} > ${WRKSRC}/conf-home
	@${MV} ${WRKSRC}/conf-cc ${WRKSRC}/conf-cc.orig
	${ECHO_CMD} ${CC} ${CFLAGS} > ${WRKSRC}/conf-cc
	@${MV} ${WRKSRC}/conf-ld ${WRKSRC}/conf-ld.orig
	${ECHO_CMD} ${CC} -s > ${WRKSRC}/conf-ld

do-install:
.for file in cdbdump cdbget cdbmake cdbstats cdbtest
	${INSTALL_PROGRAM} ${WRKSRC}/${file} ${STAGEDIR}${PREFIX}/bin
.endfor
.for file in cdbmake-12 cdbmake-sv
	${INSTALL_SCRIPT} ${WRKSRC}/${file} ${STAGEDIR}${PREFIX}/bin
.endfor

.include <bsd.port.mk>
