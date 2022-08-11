PORTNAME=	arrow
DISTVERSION=	8.0.0
PORTREVISION=	4
CATEGORIES=	databases
MASTER_SITES=	APACHE/${PORTNAME}/${PORTNAME}-${DISTVERSION} \
		https://github.com/apache/orc/archive/rel/:orc
DISTNAME=	apache-${PORTNAME}-${DISTVERSION}
DISTFILES=	apache-${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} release-1.6.6${EXTRACT_SUFX}:orc
EXTRACT_ONLY=	apache-${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Columnar in-memory analytics layer for big data

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/../LICENSE.txt

LIB_DEPENDS=	libboost_system.so:devel/boost-libs

USES=		cmake compiler:c++11-lang localbase pkgconfig python:build
USE_LDCONFIG=	yes

WRKSRC_SUBDIR=	cpp

CMAKE_ARGS=	-DARROW_SIMD_LEVEL=NONE -DARROW_RUNTIME_SIMD_LEVEL=NONE
CMAKE_OFF=	ARROW_BUILD_STATIC ARROW_WITH_BACKTRACE ARROW_BUILD_TESTS ARROW_BUILD_BENCHMARKS

OPTIONS_GROUP=			COMPRESSION COMPONENTS # components are listed in cpp/cmake_modules/DefineOptions.cmake
OPTIONS_GROUP_COMPRESSION=	BROTLI BZ2 LZ4 SNAPPY ZLIB ZSTD
OPTIONS_GROUP_COMPONENTS=	COMPUTE CSV DATASET FILESYSTEM FLIGHT GANDIVA HDFS HIVESERVER2 IPC JSON MIMALLOC PARQUET ORC PLASMA PYTHON S3 SKYHOOK SUBSTRAIT BUILD_UTILITIES TESTING
OPTIONS_SUB=			yes

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

COMPUTE_DESC=			Arrow Compute Modules
COMPUTE_CMAKE_BOOL=		ARROW_COMPUTE
COMPUTE_LIB_DEPENDS=		libre2.so:devel/re2 \
				libutf8proc.so:textproc/utf8proc

CSV_DESC=			Arrow CSV Parser Module
CSV_CMAKE_BOOL=			ARROW_CSV

DATASET_DESC=			Arrow Dataset Modules
DATASET_CMAKE_BOOL=		ARROW_DATASET
DATASET_IMPLIES=		COMPUTE FILESYSTEM

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
FLIGHT_IMPLIES=			IPC
FLIGHT_BROKEN=			configure breaks: Could not find a package configuration file provided by "re2"

GANDIVA_DESC=			Gandiva libraries
GANDIVA_USES=			ssl
GANDIVA_CMAKE_BOOL=		ARROW_GANDIVA
GANDIVA_BUILD_DEPENDS=		${LOCALBASE}/bin/clang12:devel/llvm12 # explicitly requires llvm-12
GANDIVA_LIB_DEPENDS=		libgrpc.so:devel/grpc \
				libprotobuf.so:devel/protobuf \
				libre2.so:devel/re2 \
				libutf8proc.so:textproc/utf8proc

HDFS_DESC=			Arrow HDFS bridge
HDFS_CMAKE_BOOL=		ARROW_HDFS

HIVESERVER2_DESC=		HiveServer2 client and Arrow adapter
HIVESERVER2_USES=		python:build
HIVESERVER2_VARS=		BINARY_ALIAS=python=${PYTHON_CMD}
HIVESERVER2_BUILD_DEPENDS=	thrift:devel/thrift
HIVESERVER2_CMAKE_BOOL=		ARROW_HIVESERVER2
HIVESERVER2_BROKEN=		Pending conflict fix in thrift ports in bug#255538

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
PARQUET_IMPLIES=		COMPUTE

ORC_DESC=			Arrow ORC adapter
ORC_CMAKE_BOOL=			ARROW_ORC
ORC_LIB_DEPENDS=		libprotobuf.so:devel/protobuf
ORC_CONFIGURE_ENV=		ARROW_ORC_URL=file://${DISTDIR}/${DIST_SUBDIR}/release-1.6.6${EXTRACT_SUFX}
ORC_IMPLIES=			LZ4 SNAPPY ZLIB ZSTD # cpp/CMakeLists.txt
ORC_BROKEN=			fatal error: 'orc/OrcFile.hh' file not found: https://issues.apache.org/jira/browse/ARROW-12624

PLASMA_DESC=			Plasma object store
PLASMA_CMAKE_BOOL=		ARROW_PLASMA
PLASMA_LIB_DEPENDS=		libaws-c-auth.so:security/aws-c-auth \
				libaws-c-compression.so:devel/aws-c-compression \
				libaws-c-http.so:devel/aws-c-http \
				libaws-c-mqtt.so:devel/aws-c-mqtt \
				libaws-c-s3.so:devel/aws-c-s3 \
				libaws-c-sdkutils.so:devel/aws-c-sdkutils \
				libaws-crt-cpp.so:devel/aws-crt-cpp \
				libgflags.so:devel/gflags

BUILD_UTILITIES_DESC=		build Arrow commandline utilities
BUILD_UTILITIES_CMAKE_BOOL=	ARROW_BUILD_UTILITIES

PYTHON_DESC=			Build python extension support
PYTHON_CMAKE_BOOL=		ARROW_PYTHON
PYTHON_USES=			python:3.7+
PYTHON_BUILD_DEPENDS=		${PYNUMPY} # see https://issues.apache.org/jira/browse/ARROW-16820
PYTHON_CMAKE_ON=		-DPython3_EXECUTABLE=${PYTHON_CMD}
PYTHON_LIB_DEPENDS=		libutf8proc.so:textproc/utf8proc
PYTHON_RUN_DEPENDS=		${PYNUMPY}
PYTHON_IMPLIES=			COMPUTE CSV DATASET FILESYSTEM HDFS JSON
PYTHON_VARS=			PLIST_SUB+=PYTHON_SUFFIX=${PYTHON_SUFFIX}

S3_DESC=			S3 support
S3_CMAKE_BOOL=			ARROW_S3
S3_USES=			ssl
S3_LIB_DEPENDS=			\
				libaws-c-cal.so:security/aws-c-cal \
				libaws-c-common.so:devel/aws-c-common \
				libaws-c-event-stream.so:devel/aws-c-event-stream \
				libaws-c-io.so:devel/aws-c-io \
				libaws-checksums.so:devel/aws-checksums \
				libaws-cpp-sdk-s3.so:devel/aws-sdk-cpp \
				libs2n.so:security/s2n
S3_IMPLIES=			ZLIB

SKYHOOK_DESC=			Build the Skyhook libraries
SKYHOOK_CMAKE_BOOL=		ARROW_SKYHOOK
SKYHOOK_BROKEN=			could NOT find librados

SUBSTRAIT_DESC=			Build the Arrow Substrait Consumer Module
SUBSTRAIT_CMAKE_BOOL=		ARROW_SUBSTRAIT
SUBSTRAIT_BROKEN=		needs investigation

TESTING_DESC=			Arrow testing libraries
TESTING_CMAKE_BOOL=		ARROW_TESTING
TESTING_LIB_DEPENDS=		libgtest.so:devel/googletest

.for opt in ${OPTIONS_GROUP_COMPRESSION} ${OPTIONS_GROUP_COMPONENTS}
.  if "${${opt}_BROKEN}" == ""
OPTIONS_DEFAULT+=	${opt}
.  endif
.endfor

.include <bsd.port.pre.mk>

pre-configure-PYTHON-on:
	@${REINPLACE_CMD} -e ' \
		s|arrow_python|arrow_python${PYTHON_SUFFIX}|g; \
		s|arrow-python|arrow-python${PYTHON_SUFFIX}|g \
		' \
		${WRKSRC}/../ci/appveyor-cpp-build.bat \
		${WRKSRC}/../cpp/cmake_modules/FindArrowPython.cmake \
		${WRKSRC}/../cpp/cmake_modules/FindArrowPythonFlight.cmake \
		${WRKSRC}/../cpp/src/arrow/python/arrow-python-flight.pc.in \
		${WRKSRC}/../cpp/src/arrow/python/arrow-python.pc.in \
		${WRKSRC}/../cpp/src/arrow/python/ArrowPythonConfig.cmake.in \
		${WRKSRC}/../cpp/src/arrow/python/ArrowPythonFlightConfig.cmake.in \
		${WRKSRC}/../cpp/src/arrow/python/CMakeLists.txt \
		${WRKSRC}/../dev/release/rat_exclude_files.txt \
		${WRKSRC}/../dev/release/verify-apt.sh \
		${WRKSRC}/../dev/release/verify-yum.sh \
		${WRKSRC}/../dev/tasks/conda-recipes/arrow-cpp/meta.yaml \
		${WRKSRC}/../dev/tasks/tasks.yml \
		${WRKSRC}/../docs/source/developers/python.rst \
		${WRKSRC}/../python/cmake_modules/FindArrowPython.cmake \
		${WRKSRC}/../python/cmake_modules/FindArrowPythonFlight.cmake \
		${WRKSRC}/../python/CMakeLists.txt \
		${WRKSRC}/../python/pyarrow/__init__.py \
		${WRKSRC}/../python/pyarrow/plasma.py \
		${WRKSRC}/../python/setup.py
	@${MV} ${WRKSRC}/src/arrow/python/arrow-python.pc.in ${WRKSRC}/src/arrow/python/arrow-python${PYTHON_SUFFIX}.pc.in
	@${MV} ${WRKSRC}/src/arrow/python/arrow-python-flight.pc.in ${WRKSRC}/src/arrow/python/arrow-python${PYTHON_SUFFIX}-flight.pc.in

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCOMPUTE} || ${PORT_OPTIONS:MFLIGHT} || ${PORT_OPTIONS:MGANDIVA}
PLIST_FILES+=	lib/cmake/arrow/Findre2Alt.cmake
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

do-test: # tests fail to compile: https://issues.apache.org/jira/browse/ARROW-12625
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DARROW_BUILD_TESTS:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

.include <bsd.port.post.mk>
