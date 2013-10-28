# Created by: Xin Li <delphij@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lmdb
PORTVERSION=	0.9.9
CATEGORIES=	databases
MASTER_SITES=	https://gitorious.org/${GO_ACCOUNT}/${GO_PROJECT}/archive/${GO_TAGNAME}.tar.gz?dummy= \
		LOCAL/delphij

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
GO_TAGNAME=	${PORTNAME:U}_${PORTVERSION}
FETCH_ARGS?=	-o ${DISTDIR}/${DISTFILES}

NO_STAGE=	yes
do-install:
	${INSTALL_LIB} ${WRKSRC}/liblmdb.a ${PREFIX}/lib/
	${INSTALL_LIB} ${WRKSRC}/liblmdb.so ${PREFIX}/lib/liblmdb.so.0
	${LN} -sf liblmdb.so.0 ${PREFIX}/lib/liblmdb.so
.for f in mdb_stat mdb_copy
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${PREFIX}/bin
.endfor
	${INSTALL_DATA} ${WRKSRC}/lmdb.h ${PREFIX}/include
.for f in mdb_stat.1 mdb_copy.1
	${INSTALL_MAN} ${WRKSRC}/${f} ${PREFIX}/man/man1
.endfor

MAN1=		mdb_stat.1 mdb_copy.1
PLIST_FILES=	lib/liblmdb.a lib/liblmdb.so lib/liblmdb.so.0
PLIST_FILES+=	bin/mdb_stat bin/mdb_copy
PLIST_FILES+=	include/lmdb.h

.include <bsd.port.mk>
