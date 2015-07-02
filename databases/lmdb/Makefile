# Created by: Xin Li <delphij@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lmdb
PORTVERSION=	0.9.15
CATEGORIES=	databases

MAINTAINER=	delphij@FreeBSD.org
COMMENT=	OpenLDAP Lightning Memory-Mapped Database

LICENSE=	OPENLDAP
LICENSE_NAME=	OpenLDAP Public License
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

# XXX FreeBSD does not implement O_DSYNC and fdatasync at this time.
CFLAGS+=	-DMDB_DSYNC=O_SYNC -Dfdatasync=fsync
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTNAME:tu}_${PORTVERSION}/libraries/liblmdb
MAKE_ENV+=	CC="${CC}"
MAKE_ENV+=	XCFLAGS="${CFLAGS} -pthread" prefix="${PREFIX}" INSTALL_PROGRAM="${INSTALL_PROGRAM}"
MAKE_ENV+=	INSTALL_LIB="${INSTALL_LIB}" INSTALL_DATA="${INSTALL_DATA}" INSTALL_MAN="${INSTALL_MAN}"

USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	${PORTNAME:tu}
GH_TAGNAME=	${PORTNAME:tu}_${PORTVERSION}

MDB_APPS=	copy dump load stat

do-install:
	${INSTALL_DATA} ${WRKSRC}/liblmdb.a ${STAGEDIR}${PREFIX}/lib/
	${INSTALL_LIB} ${WRKSRC}/liblmdb.so ${STAGEDIR}${PREFIX}/lib/liblmdb.so.0
	${LN} -sf liblmdb.so.0 ${STAGEDIR}${PREFIX}/lib/liblmdb.so
.for f in ${MDB_APPS}
	${INSTALL_PROGRAM} ${WRKSRC}/mdb_${f} ${STAGEDIR}${PREFIX}/bin
.endfor
	${INSTALL_DATA} ${WRKSRC}/lmdb.h ${STAGEDIR}${PREFIX}/include
.for f in ${MDB_APPS}
	${INSTALL_MAN} ${WRKSRC}/mdb_${f}.1 ${STAGEDIR}${PREFIX}/man/man1
.endfor

.include <bsd.port.mk>
