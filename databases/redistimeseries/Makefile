PORTNAME=	redistimeseries
DISTVERSIONPREFIX=	v
DISTVERSION=	1.12.14
CATEGORIES=	databases

MAINTAINER=	core-platform-scrum@redis.com
COMMENT=	Time-series data structure for Redis
WWW=		https://github.com/RedisTimeSeries/RedisTimeSeries

LICENSE=	RSALv2 SSPLv1
LICENSE_COMB=	dual
LICENSE_NAME_RSALv2=	Redis Source Available License v2
LICENSE_NAME_SSPLv1=	Server Side Public License v1
LICENSE_FILE_RSALv2=	${WRKSRC}/licenses/RSALv2.txt
LICENSE_FILE_SSPLv1=	${WRKSRC}/licenses/SSPLv1.txt
LICENSE_FILE=	${WRKSRC}/LICENSE.txt
LICENSE_PERMS_RSALv2=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
LICENSE_PERMS_SSPLv1=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

ONLY_FOR_ARCHS=	aarch64 amd64
ONLY_FOR_ARCHS_REASON=	requires a 64-bit ARM or x86 architecture

LIB_DEPENDS=	libcpu_features.so:devel/cpu_features \
		libevent.so:devel/libevent

USES=		cpe localbase:ldflags ssl
CPE_VENDOR=	redis
USE_GITHUB=	yes
GH_ACCOUNT=	RedisTimeSeries
GH_PROJECT=	RedisTimeSeries
GH_TUPLE=	RedisGears:LibMR:eda568d:libmr/deps/LibMR \
		RedisLabsModules:RedisModulesSDK:40d4bfa:redismodulesdk/deps/RedisModulesSDK \
		RedisLabsModules:readies:f31347b:readies/deps/readies \
		abseil:abseil-cpp:d936052:abseil/deps/fast_double_parser/benchmarks/dependencies/abseil-cpp \
		google:cpu_features:f1801f0:cpu_features/deps/cpu_features \
		google:double-conversion:f4cb238:double_conversion/deps/fast_double_parser/benchmarks/dependencies/double-conversion \
		lemire:fast_double_parser:47d76a0:fast_double_parser/deps/fast_double_parser \
		libevent:libevent:5df3037:libevent/deps/LibMR/deps/libevent \
		redis:hiredis:d5b4c69:hiredis/deps/LibMR/deps/hiredis

CFLAGS+=	-fcommon -fPIC -pthread
CPPFLAGS+=	-DREDIS_MODULE_TARGET -DREDISMODULE_SDK_RLEC \
		-I${WRKSRC}/deps/RedisModulesSDK -I${WRKSRC}/deps \
		-I${WRKSRC}/deps/LibMR/src -I${WRKSRC}/deps/LibMR/deps/hiredis \
		-I${WRKSRC}/deps/LibMR/deps/hiredis/adapters \
		-I${WRKSRC}/deps/fast_double_parser/include \
		-I${LOCALBASE}/include -I${OPENSSLINC}
CXXFLAGS+=	-fPIC -pthread -std=c++17
LDFLAGS+=	-pthread -L${OPENSSLLIB}

PLIST_FILES=	lib/redistimeseries.so

MODULE_SRCS=	src/chunk.c src/compaction.c src/compressed_chunk.c \
		src/config.c src/consts.c src/endianconv.c src/enriched_chunk.c \
		src/filter_iterator.c src/generic_chunk.c src/gorilla.c \
		src/indexer.c src/libmr_commands.c src/libmr_integration.c \
		src/module.c src/multiseries_agg_dup_sample_iterator.c \
		src/multiseries_sample_iterator.c src/parse_policies.c \
		src/query_language.c src/rdb.c src/reply.c src/resultset.c \
		src/sample_iterator.c src/series_iterator.c src/short_read.c \
		src/tsdb.c src/utils/arch_features.c src/utils/blocked_client.c \
		src/utils/heap.c

LIBMR_SRCS=	deps/LibMR/src/cluster.c deps/LibMR/src/crc16.c \
		deps/LibMR/src/event_loop.c deps/LibMR/src/mr.c \
		deps/LibMR/src/record.c deps/LibMR/src/utils/adlist.c \
		deps/LibMR/src/utils/buffer.c deps/LibMR/src/utils/dict.c \
		deps/LibMR/src/utils/siphash.c deps/LibMR/src/utils/thpool.c

HIREDIS_SRCS=	deps/LibMR/deps/hiredis/alloc.c deps/LibMR/deps/hiredis/async.c \
		deps/LibMR/deps/hiredis/dict.c \
		deps/LibMR/deps/hiredis/hiredis.c deps/LibMR/deps/hiredis/net.c \
		deps/LibMR/deps/hiredis/read.c deps/LibMR/deps/hiredis/sds.c \
		deps/LibMR/deps/hiredis/sockcompat.c \
		deps/LibMR/deps/hiredis/ssl.c

RMUTIL_SRCS=	deps/RedisModulesSDK/rmutil/alloc.c \
		deps/RedisModulesSDK/rmutil/periodic.c \
		deps/RedisModulesSDK/rmutil/strings.c \
		deps/RedisModulesSDK/rmutil/util.c \
		deps/RedisModulesSDK/rmutil/vector.c

CXX_SRCS=	deps/dragonbox/dragonbox.cpp \
		src/fast_double_parser_c/fast_double_parser_c.cpp

MODULE_OBJS=	${MODULE_SRCS:.c=.o}
LIBMR_OBJS=	${LIBMR_SRCS:.c=.o}
HIREDIS_OBJS=	${HIREDIS_SRCS:.c=.o}
RMUTIL_OBJS=	${RMUTIL_SRCS:.c=.o}
CXX_OBJS=	${CXX_SRCS:.cpp=.o}

SIMD_SRCS_amd64=	src/compactions/compaction_avx2.c \
			src/compactions/compaction_avx512f.c
SIMD_SRCS=		${SIMD_SRCS_${ARCH}}
SIMD_OBJS=		${SIMD_SRCS:.c=.o}

do-build:
	@cd ${WRKSRC} && for src in ${MODULE_SRCS}; do \
		${ECHO_MSG} "  CC $$src"; \
		${SETENVI} ${CC} ${CFLAGS} ${CPPFLAGS} -std=gnu11 \
			-include ${WRKSRC}/src/common.h \
			-c $$src -o $${src%.c}.o || exit 1; \
	done
	@cd ${WRKSRC} && for src in ${RMUTIL_SRCS}; do \
		${ECHO_MSG} "  CC $$src"; \
		${SETENVI} ${CC} ${CFLAGS} ${CPPFLAGS} -std=gnu11 \
			-c $$src -o $${src%.c}.o || exit 1; \
	done
	@cd ${WRKSRC} && for src in ${LIBMR_SRCS}; do \
		${ECHO_MSG} "  CC $$src"; \
		${SETENVI} ${CC} ${CFLAGS} ${CPPFLAGS} -std=gnu99 \
			-DREDISMODULE_EXPERIMENTAL_API -DREDISMODULE_MAIN \
			-DMODULE_NAME=timeseries \
			-include ${WRKSRC}/deps/LibMR/src/common.h \
			-c $$src -o $${src%.c}.o || exit 1; \
	done
	@cd ${WRKSRC} && for src in ${HIREDIS_SRCS}; do \
		${ECHO_MSG} "  CC $$src"; \
		${SETENVI} ${CC} ${CFLAGS} ${CPPFLAGS} -std=gnu99 \
			-fvisibility=hidden -c $$src -o $${src%.c}.o || exit 1; \
	done
	@cd ${WRKSRC} && for src in ${CXX_SRCS}; do \
		${ECHO_MSG} "  CXX $$src"; \
		${SETENVI} ${CXX} ${CXXFLAGS} ${CPPFLAGS} \
			-c $$src -o $${src%.cpp}.o || exit 1; \
	done
	@cd ${WRKSRC} && for src in ${SIMD_SRCS}; do \
		case "$$src" in \
			*avx2.c) simd_flag=-mavx2 ;; \
			*avx512f.c) simd_flag=-mavx512f ;; \
		esac; \
		${ECHO_MSG} "  CC $$src ($$simd_flag)"; \
		${SETENVI} ${CC} ${CFLAGS} ${CPPFLAGS} -std=gnu11 \
			$$simd_flag -c $$src -o $${src%.c}.o || exit 1; \
	done
	@cd ${WRKSRC} && ${SETENVI} ${CXX} -shared ${LDFLAGS} \
		-o redistimeseries.so ${MODULE_OBJS} ${LIBMR_OBJS} \
		${HIREDIS_OBJS} ${RMUTIL_OBJS} ${CXX_OBJS} ${SIMD_OBJS} \
		-levent_pthreads -levent -lcpu_features -lssl -lcrypto -lm -ldl

do-install:
	${INSTALL} -m 0755 ${WRKSRC}/redistimeseries.so \
		${STAGEDIR}${PREFIX}/lib/redistimeseries.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/redistimeseries.so

.include <bsd.port.mk>
