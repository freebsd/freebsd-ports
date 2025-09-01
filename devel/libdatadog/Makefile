PORTNAME=	libdatadog
PORTVERSION=	16.0.3
DISTVERSIONPREFIX=	v
PORTREVISION=	4
CATEGORIES=	devel

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Datadog Rust library
WWW=		https://github.com/DataDog/libdatadog

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	error: could not compile `datadog-sidecar` (lib) due to 2 previous errors

BUILD_DEPENDS=	bindgen:devel/rust-bindgen-cli \
		protoc:devel/protobuf

USES=		cargo llvm

CARGO_FEATURES=	cbindgen,crashtracker-ffi,cbindgen,datadog-profiling-ffi/ddtelemetry-ffi
MAKE_ENV=	LIBCLANG_PATH=${LLVM_PREFIX}/lib

NATIVE_STATIC_LIBS=	-lpthread -lrt -lexecinfo -lutil -lc -lm

USE_GITHUB=	yes
GH_ACCOUNT=	DataDog

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' ${WRKSRC}/library-config/src/lib.rs
.for file in datadog_profiling datadog_profiling-static datadog_profiling_with_rpath
	@${SED} -e 's|@Datadog_VERSION@|${PORTVERSION}|; s|@Datadog_LIBRARIES@|${NATIVE_STATIC_LIBS}|' ${WRKSRC}/profiling-ffi/${file}.pc.in > ${WRKSRC}/${file}.pc
.endfor
.for file in DatadogConfig DataPipelineConfig
	@${SED} -e 's|@Datadog_LIBRARIES@|${NATIVE_STATIC_LIBS}|' ${WRKSRC}/cmake/${file}.cmake.in > ${WRKSRC}/${file}.cmake
.endfor
# Fix sys-info-0.9.1 on 32-bit architectures, see also https://github.com/FillZpp/sys-info-rs/issues/80
	@${REINPLACE_CMD} -e '/get_cpu/ s|unsigned long|uint64_t|; /get_proc_total/ s|unsigned long|uint64_t|' ${WRKSRC}/cargo-crates/sys-info-0.9.1/c/*.[ch]

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
