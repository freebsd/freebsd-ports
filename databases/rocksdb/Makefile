# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rocksdb
PORTVERSION=	3.6.2
CATEGORIES=	databases

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Persistent key-value store for fast storage environments

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libgflags.so:${PORTSDIR}/devel/gflags \
		libsnappy.so:${PORTSDIR}/archivers/snappy

ALL_TARGET=	shared_lib all
CFLAGS+=	-I${LOCALBASE}/include
CPPFLAGS+=	-DOS_FREEBSD
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	yes
USES=		compiler:c++11-lang gmake

GH_ACCOUNT=	facebook
GH_COMMIT=	b11a617
GH_PROJECT=	${PORTNAME}
GH_TAGNAME=	${PORTNAME}-${PORTVERSION}
USE_GITHUB=	yes

PROGRAMS=	blob_store_bench db_bench db_repl_stress db_sanity_test \
		db_stress ldb log_and_apply_bench signal_test sst_dump \
		table_reader_bench

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|-pthread|; s| -fno-builtin-memcmp||; s| -ltcmalloc||' ${WRKSRC}/build_tools/build_detect_platform

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/rocksdb/ ${STAGEDIR}${DATADIR}/
	cd ${WRKSRC}/ && ${INSTALL_PROGRAM} ${PROGRAMS} ${STAGEDIR}${PREFIX}/bin/
	cd ${WRKSRC}/include/rocksdb/ && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/include/rocksdb/
	${INSTALL_LIB} ${WRKSRC}/librocksdb.a ${STAGEDIR}${PREFIX}/lib/
	${INSTALL_LIB} ${WRKSRC}/librocksdb.so ${STAGEDIR}${PREFIX}/lib/librocksdb.so.0
	${LN} -fs librocksdb.so.0 ${STAGEDIR}${PREFIX}/lib/librocksdb.so
	${INSTALL_DATA} ${WRKSRC}/build_config.mk ${STAGEDIR}${DATADIR}/

regression-test test: build
	cd ${WRKSRC}/ && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} check

.include <bsd.port.mk>
