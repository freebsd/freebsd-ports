PORTNAME=	libdatadog
PORTVERSION=	12.0.0
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Datadog Rust library
WWW=		https://github.com/DataDog/libdatadog

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo llvm

CARGO_FEATURES=	cbindgen,crashtracker-ffi,cbindgen,datadog-profiling-ffi/ddtelemetry-ffi
MAKE_ENV=	LIBCLANG_PATH=${LLVM_PREFIX}/lib

USE_GITHUB=	yes
GH_ACCOUNT=	DataDog

NATIVE_STATIC_LIBS=	-lpthread -lrt -lexecinfo -lutil -lc -lm

post-patch:
.for file in datadog_profiling datadog_profiling-static datadog_profiling_with_rpath
	@${SED} -e 's|@Datadog_VERSION@|${PORTVERSION}|; s|@Datadog_LIBRARIES@|${NATIVE_STATIC_LIBS}|' ${WRKSRC}/profiling-ffi/${file}.pc.in > ${WRKSRC}/${file}.pc
.endfor
.for file in DatadogConfig DataPipelineConfig
	@${SED} -e 's|@Datadog_LIBRARIES@|${NATIVE_STATIC_LIBS}|' ${WRKSRC}/cmake/${file}.cmake.in > ${WRKSRC}/${file}.cmake
.endfor
# Fix sys-info-0.9.1 on 32-bit architectures, see also https://github.com/FillZpp/sys-info-rs/issues/80
	@${SED} -i '' -e '/get_cpu/ s|unsigned long|uint64_t|; /get_proc_total/ s|unsigned long|uint64_t|' ${WRKSRC}/cargo-crates/sys-info-0.9.1/c/*.[ch]

post-build:
	@${CARGO_TARGET_DIR}/release/dedup_headers \
		${CARGO_TARGET_DIR}/include/datadog/common.h \
		${CARGO_TARGET_DIR}/include/datadog/crashtracker.h \
		${CARGO_TARGET_DIR}/include/datadog/profiling.h \
		${CARGO_TARGET_DIR}/include/datadog/telemetry.h \
		${CARGO_TARGET_DIR}/include/datadog/data-pipeline.h
	@${CC} -I ${CARGO_TARGET_DIR}/include/ -L ${CARGO_TARGET_DIR}/release/ -ldatadog_profiling_ffi \
		${WRKSRC}/crashtracker/libdatadog-crashtracking-receiver.c -o ${WRKSRC}/libdatadog-crashtracking-receiver
	@${MV} ${CARGO_TARGET_DIR}/release/libtest_spawn_from_lib.so ${CARGO_TARGET_DIR}/release/libtest_spawn_from_lib.so.skip

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/datadog/
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/cmake/libdatadog/
	${MKDIR} ${STAGEDIR}${PREFIX}/libdata/pkgconfig/
	${INSTALL_PROGRAM} ${WRKSRC}/libdatadog-crashtracking-receiver ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${CARGO_TARGET_DIR}/include/datadog/*.h ${STAGEDIR}${PREFIX}/include/datadog/
	${INSTALL_DATA} ${WRKSRC}/*.cmake ${STAGEDIR}${PREFIX}/lib/cmake/libdatadog/
	${INSTALL_DATA} ${CARGO_TARGET_DIR}/release/*.a ${STAGEDIR}${PREFIX}/lib/
	${INSTALL_LIB} ${CARGO_TARGET_DIR}/release/*.so ${STAGEDIR}${PREFIX}/lib/
	${INSTALL_DATA} ${WRKSRC}/datadog_profiling*.pc ${STAGEDIR}${PREFIX}/libdata/pkgconfig/

.include <bsd.port.mk>
