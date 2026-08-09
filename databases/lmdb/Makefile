PORTNAME=	lmdb
PORTVERSION=	1.0.1
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

USE_GITHUB=	yes
GH_ACCOUNT=	openldap
GH_PROJECT=	openldap
USE_LDCONFIG=	yes

MAKE_ARGS+=	CC="${CC}"
MAKE_ARGS+=	INSTALL_DATA="${INSTALL_DATA}" \
		INSTALL_LIB="${INSTALL_LIB}" \
		INSTALL_MAN="${INSTALL_MAN}" \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		prefix="${PREFIX}"

CONFLICTS_INSTALL=	lmdb0 # include/lmdb.h bin/mdb_stat

SUB_FILES+=	lmdb.pc
SUB_LIST+=	PORTVERSION=${PORTVERSION}

WRKSRC_SUBDIR=	libraries/liblmdb

post-install:
	${INSTALL_DATA} ${WRKDIR}/lmdb.pc ${STAGEDIR}${PREFIX}/libdata/pkgconfig

do-test:
	${MKDIR} ${WRKSRC}/testdb
	cd ${WRKSRC} && ./mtest*

.include <bsd.port.mk>
