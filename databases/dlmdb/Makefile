PORTNAME=	dlmdb
PORTVERSION=	1.0.0.20260303
CATEGORIES=	databases

MAINTAINER=	markus.graf@markusgraf.net
COMMENT=	Datalevin fork of OpenLDAP Lightning Memory-Mapped Database
WWW=		https://github.com/datalevin/dlmdb

LICENSE=	OPENLDAP
LICENSE_NAME=	OpenLDAP Public License
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

WRKSRC_SUBDIR=	libraries/liblmdb
MAKE_ARGS+=	CC="${CC}"
MAKE_ARGS+=	prefix="${PREFIX}" INSTALL_PROGRAM="${INSTALL_PROGRAM}"
MAKE_ARGS+=	INSTALL_LIB="${INSTALL_LIB}" INSTALL_DATA="${INSTALL_DATA}" INSTALL_MAN="${INSTALL_MAN}"

USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	datalevin
GH_PROJECT=	dlmdb
GH_TAGNAME=     9a4fbb4

SUB_FILES+=	dlmdb.pc
SUB_LIST+=	PORTVERSION=${PORTVERSION}

post-install:
	${LN} -sf libdlmdb.so.0 ${STAGEDIR}${PREFIX}/lib/libdlmdb.so
	${INSTALL_DATA} ${WRKDIR}/dlmdb.pc ${STAGEDIR}${PREFIX}/libdata/pkgconfig

do-test:
	${MKDIR} ${WRKSRC}/testdb
	cd ${WRKSRC} && LD_LIBRARY_PATH=$$(pwd) ./mtest*

.include <bsd.port.mk>
