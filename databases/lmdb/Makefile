# Created by: Xin Li <delphij@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lmdb
PORTVERSION=	0.9.7
CATEGORIES=	databases
MASTER_SITES=	https://gitorious.org/${GO_ACCOUNT}/${GO_PROJECT}/archive-tarball/${GO_TAGNAME}?dummy=

MAINTAINER=	delphij@FreeBSD.org
COMMENT=	OpenLDAP Lightning Memory-Mapped Database

# XXX FreeBSD does not implement O_DSYNC and fdatasync at this time.
CFLAGS+=	-DMDB_DSYNC=O_SYNC -Dfdatasync=fsync
WRKSRC=		${WRKDIR}/mdb-mdb/libraries/liblmdb
MAKE_ENV+=	CC="${CC}"
MAKE_ENV+=	XCFLAGS="${CFLAGS} ${PTHREAD_LIBS}" prefix="${PREFIX}" INSTALL_PROGRAM="${INSTALL_PROGRAM}"
MAKE_ENV+=	INSTALL_LIB="${INSTALL_LIB}" INSTALL_DATA="${INSTALL_DATA}" INSTALL_MAN="${INSTALL_MAN}"

GO_ACCOUNT=	mdb
GO_PROJECT=	mdb
GO_TAGNAME=	${PORTNAME:U}_${PORTVERSION}
FETCH_ARGS?=	-o - > ${DISTDIR}/${DISTFILES}

MAN1=		mdb_stat.1 mdb_copy.1
PLIST_FILES=	lib/liblmdb.a lib/liblmdb.so
PLIST_FILES+=	bin/mdb_stat bin/mdb_copy
PLIST_FILES+=	include/lmdb.h

.include <bsd.port.mk>
