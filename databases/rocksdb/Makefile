# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rocksdb
PORTVERSION=	4.13
DISTVERSIONPREFIX=	v
CATEGORIES=	databases

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Persistent key-value store for fast storage environments

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgflags.so:devel/gflags \
		libsnappy.so:archivers/snappy

BROKEN_DragonFly=	does not build on DragonFly BSD using GCC with -Werror
BROKEN_aarch64=	does not build: the clang compiler does not support -march=native
BROKEN_armv6=	does not build: the clang compiler does not support -march=native
BROKEN_powerpc64=	does not build
BROKEN_sparc64=	cannot build: uses unknown compiler flags

OPTIONS_DEFINE=	DEBUG LZ4 ZSTD
OPTIONS_DEFAULT=LZ4

ALL_TARGET=	shared_lib static_lib all
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	make_config.mk
CONFIGURE_ENV=	ROCKSDB_ROOT=${WRKSRC}
CONFIGURE_SCRIPT=	build_tools/build_detect_platform
CPPFLAGS+=	-DOS_FREEBSD
MAKE_ENV=	CXX=${CXX} INSTALL_PATH=${STAGEDIR}${PREFIX}
USE_CXXSTD=	c++11
USE_LDCONFIG=	yes
USES=		compiler:c++11-lib gmake localbase:ldflags

PORTDATA=	make_config.mk

GH_ACCOUNT=	facebook
USE_GITHUB=	yes

BENCHMARKS=	cache_bench column_aware_encoding_exp db_bench memtablerep_bench persistent_cache_bench table_reader_bench
TOOLS=		db_repl_stress db_sanity_test db_stress ldb rocksdb_dump rocksdb_undump sst_dump write_stress

DEBUG_MAKE_ENV=		DEBUG_LEVEL=2
DEBUG_MAKE_ENV_OFF=	DEBUG_LEVEL=0
LZ4_LIB_DEPENDS=	liblz4.so:archivers/liblz4
ZSTD_LIB_DEPENDS=	libzstd.so:archivers/zstd

.include <bsd.port.pre.mk>

.if ${OSVERSION} <= 1000000
CFLAGS+=	-D_GLIBCXX_USE_C99
.endif

.if ${COMPILER_TYPE} == clang && ${COMPILER_VERSION} >= 36
CXXFLAGS+=	-Wno-inconsistent-missing-override
.endif

post-patch:
	@${REINPLACE_CMD} -e '/^all: / s| $$(TESTS)||; /^dummy :=/d' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's| -fno-builtin-memcmp||; s| -ltcmalloc||' ${WRKSRC}/build_tools/build_detect_platform
	@${REINPLACE_CMD} -e 's|#include "gtest/gtest.h"|#include "gtest.h"|' ${WRKSRC}/third-party/gtest-1.7.0/fused-src/gtest/gtest-all.cc
.if defined(WITHOUT_PROFILE)
	@${REINPLACE_CMD} -e '/pg = / s| -pg||' ${WRKSRC}/Makefile
.endif
# Disable SSE4.2 on i386 architecture to fix i386 builds on FreeBSD package building cluster
.if ${ARCH} == i386
	@${REINPLACE_CMD} -e 's|#ifdef __SSE4_2__|&DISABLED__|' ${WRKSRC}/util/crc32c.cc
.endif

post-patch-LZ4-off:
	@${REINPLACE_CMD} -e '/lz4/Id' ${WRKSRC}/build_tools/build_detect_platform

post-patch-ZSTD-off:
	@${REINPLACE_CMD} -e '/zstd/Id' ${WRKSRC}/build_tools/build_detect_platform

post-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/
	cd ${WRKSRC}/ && ${INSTALL_PROGRAM} ${BENCHMARKS} ${TOOLS} ${STAGEDIR}${PREFIX}/bin/
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/librocksdb.so
	${INSTALL_DATA} ${WRKSRC}/librocksdb_tools.a ${STAGEDIR}${PREFIX}/lib/
	${INSTALL_DATA} ${WRKSRC}/make_config.mk ${STAGEDIR}${DATADIR}/

regression-test test: build
	cd ${WRKSRC}/ && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} check

.include <bsd.port.post.mk>
