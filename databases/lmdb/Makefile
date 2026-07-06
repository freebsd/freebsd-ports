PORTNAME=	lmdb
PORTVERSION=	1.0.0
DISTVERSIONPREFIX=	${PORTNAME:tu}_
PORTEPOCH=	1
CATEGORIES=	databases

MAINTAINER=	delphij@FreeBSD.org
COMMENT=	OpenLDAP Lightning Memory-Mapped Database
WWW=		https://symas.com/lmdb/

LICENSE=	OPENLDAP
LICENSE_NAME=	OpenLDAP Public License
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

CONFLICTS_INSTALL=	lmdb0 # include/lmdb.h bin/mdb_stat

WRKSRC_SUBDIR=		libraries/liblmdb
MAKE_ARGS+=	CC="${CC}"
MAKE_ARGS+=	prefix="${PREFIX}" INSTALL_PROGRAM="${INSTALL_PROGRAM}"
MAKE_ARGS+=	INSTALL_LIB="${INSTALL_LIB}" INSTALL_DATA="${INSTALL_DATA}" INSTALL_MAN="${INSTALL_MAN}"

USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	openldap
GH_PROJECT=	openldap

SUB_FILES+=	lmdb.pc
SUB_LIST+=	PORTVERSION=${PORTVERSION}

post-install:
	${INSTALL_DATA} ${WRKDIR}/lmdb.pc ${STAGEDIR}${PREFIX}/libdata/pkgconfig

do-test:
	${MKDIR} ${WRKSRC}/testdb
	cd ${WRKSRC} && ./mtest*

.include <bsd.port.mk>
