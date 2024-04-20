PORTNAME=	leveldb
PORTVERSION=	1.23
PORTREVISION=	1
CATEGORIES=	databases

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Fast and lightweight key/value database library by Google
WWW=		https://github.com/google/leveldb

LICENSE=	BSD3CLAUSE

TEST_DEPENDS=	benchmark>=0:devel/benchmark \
		googletest>=0:devel/googletest

USES=		cmake:testing compiler:c++11-lang localbase:ldflags

CMAKE_OFF=	LEVELDB_BUILD_TESTS
CMAKE_ON=	BUILD_SHARED_LIBS LEVELDB_BUILD_BENCHMARKS LEVELDB_INSTALL
CMAKE_TESTING_ON=	LEVELDB_BUILD_TESTS
USE_CXXSTD=	c++11
USE_LDCONFIG=	yes

PLIST_SUB=	PORTVERSION=${PORTVERSION}

GH_ACCOUNT=	google
USE_GITHUB=	yes

OPTIONS_DEFINE=	GPERFTOOLS SNAPPY
OPTIONS_DEFAULT=SNAPPY

GPERFTOOLS_LIB_DEPENDS=	libtcmalloc.so:devel/google-perftools
SNAPPY_LIB_DEPENDS=	libsnappy.so:archivers/snappy
SNAPPY_VARS=		SNAPPY=1 SNAPPY_CFLAGS=-DSNAPPY
SNAPPY_VARS_OFF=	SNAPPY=0 SNAPPY_CFLAGS=

post-install:
	${AR} cq ${STAGEDIR}${PREFIX}/lib/libleveldb.a ${BUILD_WRKSRC}/CMakeFiles/leveldb.dir/*/*.o
# backward compatibility (for databases/p5-Tie-LevelDB)
	${MKDIR} ${STAGEDIR}${DATADIR}/
	${ECHO_CMD} "PLATFORM_CFLAGS=-std=c++11 -D_REENTRANT -DOS_FREEBSD -DLEVELDB_PLATFORM_POSIX ${SNAPPY_CFLAGS}" > ${STAGEDIR}${DATADIR}/build_config.mk
	${ECHO_CMD} "PORT_CFLAGS=-std=c++11 -D_REENTRANT -DOS_FREEBSD -DLEVELDB_PLATFORM_POSIX ${SNAPPY_CFLAGS}" >> ${STAGEDIR}${DATADIR}/build_config.mk
	${ECHO_CMD} "SNAPPY=${SNAPPY}" >> ${STAGEDIR}${DATADIR}/build_config.mk

.include <bsd.port.mk>
