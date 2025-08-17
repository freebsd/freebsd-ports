PORTNAME=	arrow
DISTVERSION=	20.0.0
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	APACHE/${PORTNAME}/${PORTNAME}-${DISTVERSION} \
		https://github.com/apache/orc/archive/rel/:orc
DISTNAME=	apache-${PORTNAME}-${DISTVERSION}
DISTFILES=	apache-${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} release-1.6.6${EXTRACT_SUFX}:orc
EXTRACT_ONLY=	apache-${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Columnar in-memory analytics layer for big data
WWW=		https://arrow.apache.org \
		https://github.com/apache/arrow

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/../LICENSE.txt

LIB_DEPENDS=	libboost_system.so:devel/boost-libs

USES=		cmake compiler:c++17-lang localbase pkgconfig python:build,test
USE_LDCONFIG=	yes

USE_GITHUB=	nodefault
GH_ACCOUNT=	apache
#GH_TUPLE=	apache:arrow-testing:d2a1371:arrow_testing/testing \
		apache:parquet-testing:c7cf137:parquet_testing/cpp/submodules/parquet-testing

WRKSRC_SUBDIR=	cpp

PLIST_SUB+=	LIBVERSION=2000

CMAKE_ARGS=	-DCMAKE_CXX_STANDARD=17 -DARROW_SIMD_LEVEL=NONE -DARROW_RUNTIME_SIMD_LEVEL=NONE \
		-DPython3_EXECUTABLE=${PYTHON_CMD}
CMAKE_OFF=	ARROW_BUILD_STATIC ARROW_WITH_BACKTRACE ARROW_BUILD_TESTS ARROW_BUILD_BENCHMARKS

BINARY_ALIAS=	python=${PYTHON_CMD} # only for tests

OPTIONS_GROUP=			COMPRESSION COMPONENTS # components are listed in cpp/cmake_modules/DefineOptions.cmake
OPTIONS_GROUP_COMPRESSION=	BROTLI BZ2 LZ4 SNAPPY ZLIB ZSTD
OPTIONS_GROUP_COMPONENTS=	ACERO COMPUTE CSV DATASET FILESYSTEM FLIGHT GANDIVA HDFS IPC JSON MIMALLOC PARQUET ORC S3 SKYHOOK SUBSTRAIT BUILD_UTILITIES TENSORFLOW TESTING
OPTIONS_SUB=			yes

## DESCs

COMPRESSION_DESC=		Compression support:
COMPONENTS_DESC=		Build components:

## Compression options

BROTLI_CMAKE_BOOL=		ARROW_WITH_BROTLI
BROTLI_LIB_DEPENDS=		libbrotlicommon.so:archivers/brotli

BZ2_DESC=			bz2 compression support
BZ2_CMAKE_BOOL=			ARROW_WITH_BZ2

LZ4_CMAKE_BOOL=			ARROW_WITH_LZ4
LZ4_LIB_DEPENDS=		liblz4.so:archivers/liblz4

SNAPPY_CMAKE_BOOL=		ARROW_WITH_SNAPPY
SNAPPY_LIB_DEPENDS=		libsnappy.so:archivers/snappy

ZLIB_CMAKE_BOOL=		ARROW_WITH_ZLIB

ZSTD_DESC=			zstd compression support
ZSTD_CMAKE_BOOL=		ARROW_WITH_ZSTD
ZSTD_LIB_DEPENDS=		libzstd.so:archivers/zstd

## Component options

ACERO_DESC=			Arrow Acero Engine Module
ACERO_CMAKE_BOOL=		ARROW_ACERO
ACERO_IMPLIES=			COMPUTE IPC

COMPUTE_DESC=			Arrow Compute Modules
COMPUTE_CMAKE_BOOL=		ARROW_COMPUTE
COMPUTE_CMAKE_ON=		-DARROW_WITH_UTF8PROC=ON
COMPUTE_LIB_DEPENDS=		libre2.so:devel/re2 \
				libutf8proc.so:textproc/utf8proc

CSV_DESC=			Arrow CSV Parser Module
CSV_CMAKE_BOOL=			ARROW_CSV

DATASET_DESC=			Arrow Dataset Modules
DATASET_CMAKE_BOOL=		ARROW_DATASET
DATASET_IMPLIES=		ACERO FILESYSTEM

FILESYSTEM_DESC=		Arrow Filesystem Layer
FILESYSTEM_CMAKE_BOOL=		ARROW_FILESYSTEM

FLIGHT_DESC=			Arrow Flight RPC System
FLIGHT_USES=			ssl
FLIGHT_CMAKE_BOOL=		ARROW_FLIGHT
FLIGHT_LIB_DEPENDS=		libgflags.so:devel/gflags \
				libprotobuf.so:devel/protobuf \
				libabsl_base.so:devel/abseil \
				libcares.so:dns/c-ares \
				libgrpc.so:devel/grpc \
				libre2.so:devel/re2
FLIGHT_IMPLIES=			IPC COMPUTE # see https://github.com/apache/arrow/issues/40766

GANDIVA_DESC=			Gandiva libraries
GANDIVA_USES=			llvm:17,lib ssl
GANDIVA_CMAKE_BOOL=		ARROW_GANDIVA
GANDIVA_CMAKE_ON=		-DARROW_WITH_UTF8PROC=ON
GANDIVA_LIB_DEPENDS=		libgrpc.so:devel/grpc \
				libprotobuf.so:devel/protobuf \
				libre2.so:devel/re2 \
				libutf8proc.so:textproc/utf8proc

HDFS_DESC=			Arrow HDFS bridge
HDFS_CMAKE_BOOL=		ARROW_HDFS

IPC_DESC=			Arrow IPC extensions
IPC_CMAKE_BOOL=			ARROW_IPC

JSON_DESC=			JSON support
JSON_CMAKE_BOOL=		ARROW_JSON
JSON_BUILD_DEPENDS=		${LOCALBASE}/include/rapidjson/rapidjson.h:devel/rapidjson

MIMALLOC_DESC=			Arrow mimalloc-based allocato
MIMALLOC_CMAKE_BOOL=		ARROW_MIMALLOC
MIMALLOC_LIB_DEPENDS=		libmimalloc.so:devel/mimalloc
MIMALLOC_BROKEN=		Pending paths fix in bug#255537

PARQUET_DESC=			Parquet libraries
PARQUET_CMAKE_BOOL=		ARROW_PARQUET PARQUET_REQUIRE_ENCRYPTION
PARQUET_USES=			ssl
PARQUET_LIB_DEPENDS=		libthrift.so:devel/thrift-cpp
PARQUET_IMPLIES=		IPC

ORC_DESC=			Arrow ORC adapter
ORC_CMAKE_BOOL=			ARROW_ORC
ORC_LIB_DEPENDS=		libprotobuf.so:devel/protobuf
ORC_CONFIGURE_ENV=		ARROW_ORC_URL=file://${DISTDIR}/${DIST_SUBDIR}/release-1.6.6${EXTRACT_SUFX}
ORC_IMPLIES=			LZ4 SNAPPY ZLIB ZSTD # cpp/CMakeLists.txt
ORC_BROKEN=			fatal error: 'orc/OrcFile.hh' file not found: https://issues.apache.org/jira/browse/ARROW-12624

BUILD_UTILITIES_DESC=		build Arrow commandline utilities
BUILD_UTILITIES_CMAKE_BOOL=	ARROW_BUILD_UTILITIES

#PYTHON_DESC=			Build python extension support
#PYTHON_CMAKE_BOOL=		ARROW_PYTHON
#PYTHON_USES=			python
#PYTHON_BUILD_DEPENDS=		${PYNUMPY} # see https://issues.apache.org/jira/browse/ARROW-16820
#PYTHON_CMAKE_ON=		-DPython3_EXECUTABLE=${PYTHON_CMD}
#PYTHON_RUN_DEPENDS=		${PYNUMPY}
#PYTHON_IMPLIES=			COMPUTE CSV DATASET FILESYSTEM HDFS JSON
#PYTHON_VARS=			PLIST_SUB+=PYTHON_SUFFIX=${PYTHON_SUFFIX}

S3_DESC=			S3 support
S3_CMAKE_BOOL=			ARROW_S3
S3_USES=			ssl
S3_LIB_DEPENDS=			\
				libaws-c-auth.so:security/aws-c-auth \
				libaws-c-cal.so:security/aws-c-cal \
				libaws-c-common.so:devel/aws-c-common \
				libaws-c-compression.so:devel/aws-c-compression \
				libaws-c-event-stream.so:devel/aws-c-event-stream \
				libaws-c-http.so:devel/aws-c-http \
				libaws-c-io.so:devel/aws-c-io \
				libaws-c-mqtt.so:devel/aws-c-mqtt \
				libaws-c-s3.so:devel/aws-c-s3 \
				libaws-c-sdkutils.so:devel/aws-c-sdkutils \
				libaws-checksums.so:devel/aws-checksums \
				libaws-crt-cpp.so:devel/aws-crt-cpp \
				libaws-cpp-sdk-s3.so:devel/aws-sdk-cpp \
				libs2n.so:security/s2n-tls

SKYHOOK_DESC=			Build the Skyhook libraries
SKYHOOK_CMAKE_BOOL=		ARROW_SKYHOOK
SKYHOOK_IMPLIES=		DATASET PARQUET
SKYHOOK_BROKEN=			could NOT find librados

SUBSTRAIT_DESC=			Build the Arrow Substrait Consumer Module
SUBSTRAIT_CMAKE_BOOL=		ARROW_SUBSTRAIT
SUBSTRAIT_IMPLIES=		DATASET IPC PARQUET
SUBSTRAIT_BROKEN=		needs investigation

TENSORFLOW_DESC=		TensorFlow support
TENSORFLOW_CMAKE_BOOL=		ARROW_TENSORFLOW
TENSORFLOW_BROKEN=		needs testing

TESTING_DESC=			Arrow testing libraries
TESTING_CMAKE_BOOL=		ARROW_TESTING
TESTING_LIB_DEPENDS=		libgtest.so:devel/googletest

# form OPTIONS_DEFAULT
.for opt in ${OPTIONS_GROUP_COMPONENTS} ${OPTIONS_GROUP_COMPRESSION}
.  if "${${opt}_BROKEN}" == ""
OPTIONS_DEFAULT+=	${opt}
.  endif
.endfor

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCOMPUTE} || ${PORT_OPTIONS:MFLIGHT} || ${PORT_OPTIONS:MGANDIVA}
PLIST_FILES+=	lib/cmake/Arrow/Findre2Alt.cmake
.endif

.if ${PORT_OPTIONS:MIPC} && ${PORT_OPTIONS:MBUILD_UTILITIES}
PLIST_FILES+=	bin/arrow-file-to-stream \
		bin/arrow-stream-to-file
.endif
.if ${PORT_OPTIONS:MGANDIVA} || ${PORT_OPTIONS:MCOMPUTE}
PLIST_FILES+=	lib/cmake/Arrow/Findutf8proc.cmake
.endif
.if ${PORT_OPTIONS:MGANDIVA} || ${PORT_OPTIONS:MZSTD}
PLIST_FILES+=	lib/cmake/Gandiva/FindzstdAlt.cmake
.endif

.if ${PORT_OPTIONS:MPYTHON} == "PYTHON" && ${PORT_OPTIONS:MFLIGHT} == "FLIGHT"
    PLIST_SUB+=	PYTHONFLIGHT=""
.else
    PLIST_SUB+=	PYTHONFLIGHT="@comment "
.endif

.if ${PORT_OPTIONS:MTESTING} && ${PORT_OPTIONS:MFLIGHT} == "FLIGHT"
    PLIST_SUB+=	TESTINGFLIGHT=""
.else
    PLIST_SUB+=	TESTINGFLIGHT="@comment "
.endif

post-install:
	# based on the user's report on 2024-04-12, the R extension expects only "ON" and "OFF" values in lib/cmake/Arrow/ArrowOptions.cmake
	# other values confuse the R extension build, so we adjust these values to "ON" and "OFF" as a workaround
	${REINPLACE_CMD} -i '' \
		-e 's|"true"|"ON"|; s|"false"|"OFF"|' \
		${STAGEDIR}${PREFIX}/lib/cmake/Arrow/ArrowOptions.cmake

do-test:
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DARROW_BUILD_TESTS:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

# tests as of : 89% tests passed, 10 tests failed out of 90, see https://github.com/apache/arrow/issues/45604

.include <bsd.port.mk>
