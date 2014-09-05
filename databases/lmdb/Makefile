# Created by: Xin Li <delphij@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lmdb
PORTVERSION=	0.9.13
CATEGORIES=	databases
MASTER_SITES=	LOCAL/delphij
# https://gitorious.org/${GO_ACCOUNT}/${GO_PROJECT}/archive/${GO_TAGNAME}.tar.gz?dummy= \

MAINTAINER=	delphij@FreeBSD.org
COMMENT=	OpenLDAP Lightning Memory-Mapped Database

# XXX FreeBSD does not implement O_DSYNC and fdatasync at this time.
CFLAGS+=	-DMDB_DSYNC=O_SYNC -Dfdatasync=fsync
WRKSRC=		${WRKDIR}/mdb-mdb/libraries/liblmdb
MAKE_ENV+=	CC="${CC}"
MAKE_ENV+=	XCFLAGS="${CFLAGS} ${PTHREAD_LIBS}" prefix="${PREFIX}" INSTALL_PROGRAM="${INSTALL_PROGRAM}"
MAKE_ENV+=	INSTALL_LIB="${INSTALL_LIB}" INSTALL_DATA="${INSTALL_DATA}" INSTALL_MAN="${INSTALL_MAN}"

USE_LDCONFIG=	yes

GO_ACCOUNT=	mdb
GO_PROJECT=	mdb
GO_TAGNAME=	${PORTNAME:tu}_${PORTVERSION}
FETCH_ARGS?=	-o ${DISTDIR}/${DISTFILES}

do-install:
	${INSTALL_LIB} ${WRKSRC}/liblmdb.a ${STAGEDIR}${PREFIX}/lib/
	${INSTALL_LIB} ${WRKSRC}/liblmdb.so ${STAGEDIR}${PREFIX}/lib/liblmdb.so.0
	${LN} -sf liblmdb.so.0 ${STAGEDIR}${PREFIX}/lib/liblmdb.so
.for f in mdb_stat mdb_copy
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/bin
.endfor
	${INSTALL_DATA} ${WRKSRC}/lmdb.h ${STAGEDIR}${PREFIX}/include
.for f in mdb_stat.1 mdb_copy.1
	${INSTALL_MAN} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/man/man1
.endfor

.include <bsd.port.mk>
