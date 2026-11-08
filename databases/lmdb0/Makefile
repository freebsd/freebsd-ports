PORTNAME=	lmdb
PORTVERSION=	0.9.36
PORTREVISION=	1
DISTVERSIONPREFIX=	${PORTNAME:tu}_
PKGNAMESUFFIX=	0
CATEGORIES=	databases

MAINTAINER=	delphij@FreeBSD.org
COMMENT=	OpenLDAP Lightning Memory-Mapped Database (legacy)
WWW=		https://symas.com/lmdb/

LICENSE=	OPENLDAP
LICENSE_NAME=	OpenLDAP Public License
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

PORTSCOUT=	limit:^0\.

WRKSRC_SUBDIR=		libraries/liblmdb
MAKE_ARGS+=	CC="${CC}"
MAKE_ARGS+=	prefix="${PREFIX}" INSTALL_PROGRAM="${INSTALL_PROGRAM}"
MAKE_ARGS+=	INSTALL_LIB="${INSTALL_LIB}" INSTALL_DATA="${INSTALL_DATA}" INSTALL_MAN="${INSTALL_MAN}"

USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	openldap
GH_PROJECT=	openldap

SUB_FILES+=	lmdb0.pc lmdb.pc
SUB_LIST+=	PORTVERSION=${PORTVERSION}

post-install:
	${MV} ${STAGEDIR}${PREFIX}/bin/mdb_copy ${STAGEDIR}${PREFIX}/bin/mdb_copy0
	${MV} ${STAGEDIR}${PREFIX}/bin/mdb_dump ${STAGEDIR}${PREFIX}/bin/mdb_dump0
	${MV} ${STAGEDIR}${PREFIX}/bin/mdb_load ${STAGEDIR}${PREFIX}/bin/mdb_load0
	${MV} ${STAGEDIR}${PREFIX}/bin/mdb_stat ${STAGEDIR}${PREFIX}/bin/mdb_stat0
	${MV} ${STAGEDIR}${PREFIX}/share/man/man1/mdb_copy.1 ${STAGEDIR}${PREFIX}/share/man/man1/mdb_copy0.1
	${MV} ${STAGEDIR}${PREFIX}/share/man/man1/mdb_dump.1 ${STAGEDIR}${PREFIX}/share/man/man1/mdb_dump0.1
	${MV} ${STAGEDIR}${PREFIX}/share/man/man1/mdb_load.1 ${STAGEDIR}${PREFIX}/share/man/man1/mdb_load0.1
	${MV} ${STAGEDIR}${PREFIX}/share/man/man1/mdb_stat.1 ${STAGEDIR}${PREFIX}/share/man/man1/mdb_stat0.1
	${MV} ${STAGEDIR}${PREFIX}/lib/liblmdb.a ${STAGEDIR}${PREFIX}/lib/liblmdb0.a
	${LN} -sf liblmdb.so.0 ${STAGEDIR}${PREFIX}/lib/liblmdb0.so
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/lmdb0
	${MV} ${STAGEDIR}${PREFIX}/include/lmdb.h ${STAGEDIR}${PREFIX}/include/lmdb0/lmdb.h
	${INSTALL_DATA} ${WRKDIR}/lmdb0.pc ${STAGEDIR}${PREFIX}/libdata/pkgconfig/lmdb0.pc
	# Compatibility prefix for build systems that look up lmdb.h and
	# -llmdb relative to a single directory.
	@${MKDIR} ${STAGEDIR}${PREFIX}/lmdb0/include
	@${MKDIR} ${STAGEDIR}${PREFIX}/lmdb0/lib
	@${MKDIR} ${STAGEDIR}${PREFIX}/lmdb0/libdata/pkgconfig
	${LN} -sf ../../include/lmdb0/lmdb.h ${STAGEDIR}${PREFIX}/lmdb0/include/lmdb.h
	${LN} -sf ../../lib/liblmdb.so.0 ${STAGEDIR}${PREFIX}/lmdb0/lib/liblmdb.so
	${LN} -sf ../../lib/liblmdb0.a ${STAGEDIR}${PREFIX}/lmdb0/lib/liblmdb.a
	${INSTALL_DATA} ${WRKDIR}/lmdb.pc ${STAGEDIR}${PREFIX}/lmdb0/libdata/pkgconfig/lmdb.pc

do-test:
	${MKDIR} ${WRKSRC}/testdb
	cd ${WRKSRC} && ./mtest*

.include <bsd.port.mk>
