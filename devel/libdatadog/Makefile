PORTNAME=	libdatadog
PORTVERSION=	11.0.0
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Datadog Rust library
WWW=		https://github.com/DataDog/libdatadog

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo llvm

CARGO_FEATURES=	cbindgen,datadog-profiling-ffi/ddtelemetry-ffi
MAKE_ENV=	LIBCLANG_PATH=${LLVM_PREFIX}/lib

USE_GITHUB=	yes
GH_ACCOUNT=	DataDog

NATIVE_STATIC_LIBS=	-lpthread -lrt -lexecinfo -lutil -lc -lm

post-patch:
	@${SED} -e 's|@Datadog_VERSION@|${PORTVERSION}|' ${WRKSRC}/profiling-ffi/datadog_profiling.pc.in > ${WRKSRC}/datadog_profiling.pc
	@${SED} -e 's|@DDog_VERSION@|${PORTVERSION}|' ${WRKSRC}/profiling-ffi/datadog_profiling_with_rpath.pc.in > ${WRKSRC}/datadog_profiling_with_rpath.pc
	@${SED} -e 's|@DDog_VERSION@|${PORTVERSION}|; s|@Datadog_LIBRARIES@|${NATIVE_STATIC_LIBS}|' ${WRKSRC}/profiling-ffi/datadog_profiling-static.pc.in > ${WRKSRC}/datadog_profiling-static.pc
	@${SED} -e 's|@Datadog_LIBRARIES@|${NATIVE_STATIC_LIBS}|' ${WRKSRC}/cmake/DatadogConfig.cmake.in > ${WRKSRC}/DatadogConfig.cmake
	@${SED} -e 's|@Datadog_LIBRARIES@|${NATIVE_STATIC_LIBS}|' ${WRKSRC}/cmake/DataPipelineConfig.cmake.in > ${WRKSRC}/DataPipelineConfig.cmake
# Fix sys-info-0.9.1 on 32-bit architectures, see also https://github.com/FillZpp/sys-info-rs/issues/80
	@${SED} -i '' -e '/get_cpu/ s|unsigned long|uint64_t|; /get_proc_total/ s|unsigned long|uint64_t|' ${WRKSRC}/cargo-crates/sys-info-0.9.1/c/*.[ch]

post-build:
	@${CARGO_TARGET_DIR}/${CARGO_BUILD_TARGET}/release/dedup_headers \
		${CARGO_TARGET_DIR}/include/datadog/common.h \
		${CARGO_TARGET_DIR}/include/datadog/profiling.h \
		${CARGO_TARGET_DIR}/include/datadog/telemetry.h \
		${CARGO_TARGET_DIR}/include/datadog/data-pipeline.h
	@${CC} -I ${CARGO_TARGET_DIR}/include/ -L ${CARGO_TARGET_DIR}/${CARGO_BUILD_TARGET}/release/ -ldatadog_profiling_ffi \
		${WRKSRC}/crashtracker/libdatadog-crashtracking-receiver.c -o ${WRKSRC}/libdatadog-crashtracking-receiver
	@${MV} ${CARGO_TARGET_DIR}/${CARGO_BUILD_TARGET}/release/libtest_spawn_from_lib.so ${CARGO_TARGET_DIR}/${CARGO_BUILD_TARGET}/release/libtest_spawn_from_lib.so.skip

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/libdatadog-crashtracking-receiver ${STAGEDIR}${PREFIX}/bin/
	${MKDIR} ${STAGEDIR}${PREFIX}/include/datadog/
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/cmake/libdatadog/
	${MKDIR} ${STAGEDIR}${PREFIX}/libdata/pkgconfig/
	${INSTALL_DATA} ${CARGO_TARGET_DIR}/include/datadog/*.h ${STAGEDIR}${PREFIX}/include/datadog/
	${INSTALL_DATA} ${WRKSRC}/*.cmake ${STAGEDIR}${PREFIX}/lib/cmake/libdatadog/
	${INSTALL_DATA} ${CARGO_TARGET_DIR}/${CARGO_BUILD_TARGET}/release/*.a ${STAGEDIR}${PREFIX}/lib/
	${INSTALL_LIB} ${CARGO_TARGET_DIR}/${CARGO_BUILD_TARGET}/release/*.so ${STAGEDIR}${PREFIX}/lib/
	${INSTALL_DATA} ${WRKSRC}/datadog_profiling*.pc ${STAGEDIR}${PREFIX}/libdata/pkgconfig/

.include <bsd.port.mk>
