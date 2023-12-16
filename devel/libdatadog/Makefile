PORTNAME=	libdatadog
PORTVERSION=	2.2.0
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Datadog Rust library
WWW=		https://github.com/DataDog/libdatadog

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	cbindgen:devel/rust-cbindgen

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	DataDog

post-patch:
	@${SED} -e 's|@Datadog_VERSION@|${PORTVERSION}|' ${WRKSRC}/profiling-ffi/datadog_profiling.pc.in > ${WRKSRC}/datadog_profiling.pc
	@${SED} -e 's|@DDog_VERSION@|${PORTVERSION}|' ${WRKSRC}/profiling-ffi/datadog_profiling_with_rpath.pc.in > ${WRKSRC}/datadog_profiling_with_rpath.pc
	# Fix sys-info-0.9.1 on 32-bit architectures, see also https://github.com/FillZpp/sys-info-rs/issues/80
	@${SED} -i '' -e '/get_cpu/ s|unsigned long|uint64_t|; /get_proc_total/ s|unsigned long|uint64_t|' ${WRKSRC}/cargo-crates/sys-info-0.9.1/c/*.[ch]

post-build:
	@cd ${WRKSRC} && cbindgen --crate ddcommon-ffi --config ddcommon-ffi/cbindgen.toml --output ${WRKSRC}/common.h
	@cd ${WRKSRC} && cbindgen --crate datadog-profiling-ffi --config profiling-ffi/cbindgen.toml --output ${WRKSRC}/profiling.h
	@${CARGO_TARGET_DIR}/${CARGO_BUILD_TARGET}/release/dedup_headers ${WRKSRC}/common.h ${WRKSRC}/profiling.h

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/datadog/
	${MKDIR} ${STAGEDIR}${PREFIX}/libdata/pkgconfig/
	${INSTALL_DATA} ${WRKSRC}/common.h ${WRKSRC}/profiling.h ${STAGEDIR}${PREFIX}/include/datadog/
	${INSTALL_DATA} ${CARGO_TARGET_DIR}/${CARGO_BUILD_TARGET}/release/libdatadog_profiling_ffi.a ${STAGEDIR}${PREFIX}/lib/
	${INSTALL_LIB} ${CARGO_TARGET_DIR}/${CARGO_BUILD_TARGET}/release/libdatadog_profiling_ffi.so ${STAGEDIR}${PREFIX}/lib/
	${INSTALL_DATA} ${WRKSRC}/datadog_profiling*.pc ${STAGEDIR}${PREFIX}/libdata/pkgconfig/

.include <bsd.port.mk>
