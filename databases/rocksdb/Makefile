PORTNAME=	rocksdb
PORTVERSION=	10.5.1
DISTVERSIONPREFIX=	v
CATEGORIES=	databases

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Persistent key-value store for fast storage environments
WWW=		https://rocksdb.org/ \
		https://github.com/facebook/rocksdb

LICENSE=	APACHE20 GPLv2
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE.Apache
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING

BROKEN_DragonFly=	does not build on DragonFly BSD using GCC with -Werror
BROKEN_armv6=	does not build: db/c.cc:2281:44: implicit conversion loses integer precision: 'uint64_t' (aka 'unsigned long long') to 'size_t' (aka 'unsigned int')
BROKEN_armv7=	does not build: /nxb-bin/usr/bin/ld: undefined reference to symbol `__gnu_Unwind_Find_exidx@@FBSD_1.4' (try adding -lc) #'`

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libgflags.so:devel/gflags \
		libsnappy.so:archivers/snappy

USES=		compiler:c++17-lang gmake localbase:ldflags perl5
USE_PERL5=	build

ALL_TARGET=	shared_lib static_lib all
CFLAGS+=	-DOS_FREEBSD
CONFIGURE_ARGS=	make_config.mk
CONFIGURE_ENV=	PORTABLE=0 ROCKSDB_ROOT=${WRKSRC}
CONFIGURE_SCRIPT=	build_tools/build_detect_platform
HAS_CONFIGURE=	yes
MAKE_ENV=	CXX=${CXX} INSTALL_PATH=${STAGEDIR}${PREFIX} USE_RTTI=1 V=1
USE_CXXSTD=	c++17
USE_LDCONFIG=	yes
TEST_TARGET=	check

PLIST_SUB=	PORTVERSION=${PORTVERSION} SHLIB_VER=${PORTVERSION:R}
PORTDATA=	make_config.mk

GH_ACCOUNT=	facebook
USE_GITHUB=	yes

CONFLICTS_INSTALL=	rocksdb-lite

BENCHMARKS=	cache_bench db_bench memtablerep_bench persistent_cache_bench range_del_aggregator_bench table_reader_bench
TOOLS=		blob_dump db_repl_stress db_sanity_test db_stress ldb rocksdb_dump rocksdb_undump sst_dump trace_analyzer write_stress

OPTIONS_DEFINE=	DEBUG LZ4 ZSTD
OPTIONS_DEFAULT=LZ4 ZSTD

DEBUG_MAKE_ENV=		DEBUG_LEVEL=2
DEBUG_MAKE_ENV_OFF=	DEBUG_LEVEL=0
LZ4_LIB_DEPENDS=	liblz4.so:archivers/liblz4
LZ4_MAKE_ENV_OFF=	ROCKSDB_DISABLE_LZ4=yes
ZSTD_LIB_DEPENDS=	libzstd.so:archivers/zstd
ZSTD_MAKE_ENV_OFF=	ROCKSDB_DISABLE_ZSTD=yes

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == clang
CXXFLAGS+=	-Wno-sync-alignment -Wno-unused-but-set-variable -Wno-unused-parameter -Wno-unused-variable
.endif

post-patch:
.if (${ARCH} == amd64 || ${ARCH} == i386) && !empty(CFLAGS:M-march=*)
	@${REINPLACE_CMD} -e 's| -march=native| ${CFLAGS:M-march=*}|' ${WRKSRC}/build_tools/build_detect_platform
.else
	@${REINPLACE_CMD} -e 's| -march=native||' ${WRKSRC}/build_tools/build_detect_platform
.endif

post-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/
	cd ${WRKSRC}/ && ${INSTALL_PROGRAM} ${BENCHMARKS} ${TOOLS} ${STAGEDIR}${PREFIX}/bin/
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/librocksdb.so
	${INSTALL_LIB} ${WRKSRC}/librocksdb_test.so ${WRKSRC}/librocksdb_tools.so ${STAGEDIR}${PREFIX}/lib/
	${INSTALL_DATA} ${WRKSRC}/make_config.mk ${STAGEDIR}${DATADIR}/

.include <bsd.port.post.mk>
