# Created by: Xin Li <delphij@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lmdb
PORTVERSION=	0.9.18
DISTVERSIONPREFIX=	${PORTNAME:tu}_
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
MAKE_ENV+=	prefix="${PREFIX}" INSTALL_PROGRAM="${INSTALL_PROGRAM}"
MAKE_ENV+=	INSTALL_LIB="${INSTALL_LIB}" INSTALL_DATA="${INSTALL_DATA}" INSTALL_MAN="${INSTALL_MAN}"

USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	${PORTNAME:tu}

post-install:
	${LN} -sf liblmdb.so.0 ${STAGEDIR}${PREFIX}/lib/liblmdb.so

.include <bsd.port.mk>
