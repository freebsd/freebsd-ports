PORTNAME=	swift
DISTVERSIONPREFIX=	swift-
DISTVERSION=	6.3.2
DISTVERSIONSUFFIX=	-RELEASE
CATEGORIES=	lang
PKGNAMESUFFIX=	6
DIST_SUBDIR=	${PORTNAME}

BOOTSTRAP_SWIFT_VERSION=	6.3.1
.if !defined(BOOTSTRAP_MODE)
MASTER_SITES=	LOCAL/tagattie/${PORTNAME}:bootstrap
DISTFILES=	${PORTNAME}${PKGNAMESUFFIX}-bootstrap-${BOOTSTRAP_SWIFT_VERSION}-${SWIFT_ARCH}-unknown-${OPSYS:tl}${EXTRACT_SUFX}:bootstrap
.else
.   if make(makesum)
DISTFILES=	${PORTNAME}${PKGNAMESUFFIX}-bootstrap-${DISTVERSION}-${SWIFT_ARCH}-unknown-${OPSYS:tl}${EXTRACT_SUFX}:bootstrap
.   endif
.endif

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Powerful, flexible, multiplatform programming language
WWW=		https://www.swift.org/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/swift/LICENSE.txt

ONLY_FOR_ARCHS=		amd64
ONLY_FOR_ARCHS_REASON=	bootstrap is available only on amd64 architecture

BUILD_DEPENDS=	rsync:net/rsync \
		bash:shells/bash
LIB_DEPENDS=	libzstd.so:archivers/zstd \
		libcurl.so:ftp/curl \
		libuuid.so:misc/libuuid

USES=		cmake:indirect gnome libedit ninja:build perl5 pkgconfig \
		python shebangfix sqlite:3 tar:xz

USE_GITHUB=	nodefault
GH_TUPLE=	\
		swiftlang:swift-cmark:${DISTVERSIONFULL}:swift_cmark/cmark \
		swiftlang:indexstore-db:${DISTVERSIONFULL}:indexstore_db/indexstore-db \
		swiftlang:swift-llbuild:${DISTVERSIONFULL}:swift_llbuild/llbuild \
		swiftlang:llvm-project:${DISTVERSIONFULL}:llvm_project/llvm-project \
		swiftlang:sourcekit-lsp:${DISTVERSIONFULL}:sourcekit_lsp/sourcekit-lsp \
		swiftlang:swift:${DISTVERSIONFULL}:swift/swift \
		apple:swift-argument-parser:1.6.1:swift_argument_parser/swift-argument-parser \
		apple:swift-asn1:1.3.2:swift_asn1/swift-asn1 \
		apple:swift-async-algorithms:1.0.1:swift_async_algorithms/swift-async-algorithms \
		apple:swift-atomics:1.2.0:swift_atomics/swift-atomics \
		swiftlang:swift-build:${DISTVERSIONFULL}:swift_build/swift-build \
		apple:swift-certificates:1.10.1:swift_certificates/swift-certificates \
		apple:swift-collections:1.1.6:swift_collections/swift-collections \
		swiftlang:swift-corelibs-blocksruntime:${DISTVERSIONFULL}:swift_corelibs_blocksruntime/swift-corelibs-blocksruntime \
		swiftlang:swift-corelibs-foundation:${DISTVERSIONFULL}:swift_corelibs_foundation/swift-corelibs-foundation \
		swiftlang:swift-corelibs-libdispatch:${DISTVERSIONFULL}:swift_corelibs_libdispatch/swift-corelibs-libdispatch \
		swiftlang:swift-corelibs-xctest:${DISTVERSIONFULL}:swift_corelibs_xctest/swift-corelibs-xctest \
		apple:swift-crypto:3.12.5:swift_crypto/swift-crypto \
		swiftlang:swift-docc:${DISTVERSIONFULL}:swift_docc/swift-docc \
		swiftlang:swift-docc-render-artifact:${DISTVERSIONFULL}:swift_docc_render_artifact/swift-docc-render-artifact \
		swiftlang:swift-docc-symbolkit:${DISTVERSIONFULL}:swift_docc_symbolkit/swift-docc-symbolkit \
		swiftlang:swift-driver:${DISTVERSIONFULL}:swift_driver/swift-driver \
		swiftlang:swift-experimental-string-processing:${DISTVERSIONFULL}:swift_experimental_string_processing/swift-experimental-string-processing \
		swiftlang:swift-format:${DISTVERSIONFULL}:swift_format/swift-format \
		swiftlang:swift-foundation:${DISTVERSIONFULL}:swift_foundation/swift-foundation \
		swiftlang:swift-foundation-icu:${DISTVERSIONFULL}:swift_foundation_icu/swift-foundation-icu \
		swiftlang:swift-installer-scripts:${DISTVERSIONFULL}:swift_installer_scripts/swift-installer-scripts \
		swiftlang:swift-integration-tests:${DISTVERSIONFULL}:swift_integration_tests/swift-integration-tests \
		swiftlang:swift-llvm-bindings:${DISTVERSIONFULL}:swift_llvm_bindings/swift-llvm-bindings \
		swiftlang:swift-lmdb:${DISTVERSIONFULL}:swift_lmdb/swift-lmdb \
		apple:swift-log:1.5.4:swift_log/swift-log \
		swiftlang:swift-markdown:${DISTVERSIONFULL}:swift_markdown/swift-markdown \
		apple:swift-nio:2.65.0:swift_nio/swift-nio \
		apple:swift-numerics:1.0.2:swift_numerics/swift-numerics \
		swiftlang:swift-sdk-generator:${DISTVERSIONFULL}:swift_sdk_generator/swift-sdk-generator \
		swiftlang:swift-stress-tester:${DISTVERSIONFULL}:swift_stress_tester/swift-stress-tester \
		swiftlang:swift-subprocess:0.2.1:swift_subprocess/swift-subprocess \
		swiftlang:swift-syntax:${DISTVERSIONFULL}:swift_syntax/swift-syntax \
		apple:swift-system:1.5.0:swift_system/swift-system \
		swiftlang:swift-testing:${DISTVERSIONFULL}:swift_testing/swift-testing \
		swiftlang:swift-toolchain-sqlite:1.0.7:swift_toolchain_sqlite/swift-toolchain-sqlite \
		swiftlang:swift-tools-protocols:0.0.9:swift_tools_protocols/swift-tools-protocols \
		swiftlang:swift-tools-support-core:${DISTVERSIONFULL}:swift_tools_support_core/swift-tools-support-core \
		swiftlang:swift-package-manager:${DISTVERSIONFULL}:swift_package_manager/swiftpm \
		WebAssembly:wasi-libc:wasi-sdk-27:wasi_libc/wasi-libc \
		swiftwasm:WasmKit:0.1.6:WasmKit/wasmkit

USE_PERL5=	build
USE_GNOME=	libxml2

SHEBANG_FILES=	swift/utils/api_checker/sdk-module-lists/infer-imports.py \
		swift/utils/api_checker/swift-api-checker.py \
		swift/utils/build-script \
		swift/utils/build-script-impl \
		swift/utils/run-test \
		swift/utils/swift-api-dump.py \
		swiftpm/Utilities/bootstrap

MAKE_ENV+=	SKIP_BUILD_SWIFTPM_INTERNALTESTSUPPORT=1

BINARY_ALIAS=	python3=${PYTHON_CMD}

WRKSRC=		${WRKDIR}/swift-${DISTVERSION}

PLIST_SUB=	SWIFT_ARCH=${SWIFT_ARCH} \
		SWIFT_TARGET_TRIPLE=${SWIFT_ARCH}-unknown-${OPSYS:tl}
PORTDOCS=	CHANGELOG.md CONTRIBUTING.md README.md

OPTIONS_DEFINE=	DOCS

SWIFT_PREFIX=	${PREFIX}/${PORTNAME}${PKGNAMESUFFIX}
SWIFT_ARCH=	${ARCH:S/amd64/x86_64/}
.for n in 0 1 2 3 4 5
OUT${n}_DIR=	${WRKDIR}/out${n}
.endfor
STAGE0_MODULES=	libdispatch
STAGE1_MODULES=	${STAGE0_MODULES} \
		swiftsyntax
STAGE2_MODULES=	${STAGE1_MODULES} \
		foundation \
		llbuild
STAGE3_MODULES=	${STAGE2_MODULES} \
		xctest \
		swift-testing
STAGE4_MODULES=	${STAGE3_MODULES} \
		swiftpm
STAGE5_MODULES=	${STAGE4_MODULES} \
		indexstore-db \
		lldb \
		swift-driver \
		swiftformat \
		swiftdocc \
		sourcekit-lsp
COMMON_BUILDFLAGS=	\
		--install-prefix ${SWIFT_PREFIX} \
		--install-all true \
		--jobs ${MAKE_JOBS_NUMBER} \
		--extra-cmake-options="-DCMAKE_C_FLAGS_RELEASE='${CFLAGS} -DNDEBUG'" \
		--extra-cmake-options="-DCMAKE_CXX_FLAGS_RELEASE='${CXXFLAGS} -DNDEBUG'" \
		--extra-cmake-options="-DCLANG_DEFAULT_LINKER=lld" \
		--extra-cmake-options="-DLLVM_ENABLE_LLD=ON" \
		--extra-cmake-options="-DSWIFT_USE_LINKER=lld" \
		--verbose-build true \
		--llvm-targets-to-build "AArch64;X86" \
		--build-swift-dynamic-stdlib true \
		--build-swift-static-stdlib true \
		--build-swift-dynamic-sdk-overlay true \
		--build-swift-static-sdk-overlay true \
		${CCACHE_BUILDFLAGS} \
		${RELEASE_BUILDFLAGS}
STAGE0_BUILDFLAGS=	${COMMON_BUILDFLAGS} \
		--install-destdir ${OUT0_DIR} \
		--extra-cmake-options="-DSWIFT_ENABLE_SWIFT_IN_SWIFT=OFF" \
		--bootstrapping bootstrapping \
		--skip-early-swiftsyntax \
		--skip-early-swift-driver \
		${STAGE0_MODULES:C/^/--/:C/$/ true/}
.for n p in 1 0	 2 1  3 2  4 3	5 4
STAGE${n}_BUILDFLAGS=	${COMMON_BUILDFLAGS} \
		--install-destdir ${OUT${n}_DIR} \
		--native-swift-tools-path ${OUT${p}_DIR}${SWIFT_PREFIX}/bin \
		--extra-cmake-options="-DCMAKE_Swift_COMPILER=${OUT${p}_DIR}${SWIFT_PREFIX}/bin/swiftc" \
		--bootstrapping hosttools \
		${STAGE${n}_MODULES:C/^/--/:C/$/ true/}
.endfor
BOOTSTRAP_DIR=	${WRKDIR}/${PORTNAME}${PKGNAMESUFFIX}-bootstrap${SWIFT_PREFIX}
SWIFT_BUILDFLAGS=	${COMMON_BUILDFLAGS} \
		--install-destdir ${OUT5_DIR} \
		--native-swift-tools-path ${BOOTSTRAP_DIR}/bin \
		--extra-cmake-options="-DCMAKE_Swift_COMPILER=${BOOTSTRAP_DIR}/bin/swiftc" \
		--bootstrapping hosttools \
		${STAGE5_MODULES:C/^/--/:C/$/ true/}

.if defined(WITH_CCACHE_BUILD) && !defined(NO_CCACHE)
CCACHE_BUILDFLAGS=	--cmake-c-launcher ${CCACHE_BIN} \
			--cmake-cxx-launcher ${CCACHE_BIN}
.endif

.if !defined(WITH_DEBUG)
RELEASE_BUILDFLAGS=	--release \
			--no-assertions
.else
RELEASE_BUILDFLAGS=	--debug \
			--assertions
.endif

.if defined(BOOTSTRAP_MODE)
PLIST_SUB+=	BOOTSTRAP="@comment "
.else
PLIST_SUB+=	BOOTSTRAP=""
.endif

.include <bsd.port.pre.mk>

# Bootstrap swift toolchain has been built on FreeBSD 14 jail.
# So we need compat14x on FreeBSD 15 or later.
.if !defined(BOOTSTRAP_MODE)
.   if ${OSVERSION} >= 1500000
BUILD_DEPENDS+=	${LOCALBASE}/lib/compat/libutil.so.9:misc/compat14x
.   endif
.endif

post-extract:
	@${CP} ${WRKSRC}/swift-corelibs-libdispatch/dispatch/generic/module.modulemap \
		${WRKSRC}/swift-corelibs-libdispatch/dispatch

do-build:
.if defined(BOOTSTRAP_MODE)
# Stage 0: Minimum compiler without macros
# Stage 1: Macro-aware compiler
# Stage 2: Stage 1 + foundation and build tools
# Stage 3: Stage 2 + testing modules
# Stage 4: Stage 3 + SwiftPM
# Stage 5: Full toolchain
.   for n in 0 1 2 3 4 5
	@${ECHO_MSG} "======================"
	@${ECHO_MSG} "===>  Building stage ${n}"
	@${ECHO_MSG} "======================"
	@${RM} -r ${WRKSRC}/build
.	if ${n} == 1
	# Rename module.modulemap to avoid the error:
	# error: redefinition of module 'Dispatch'
	@${MV} ${WRKSRC}/swift-corelibs-libdispatch/dispatch/module.modulemap \
		${WRKSRC}/swift-corelibs-libdispatch/dispatch/module.modulemap.bak
	@${TOUCH} ${WRKSRC}/swift-corelibs-libdispatch/dispatch/module.modulemap
.	endif
.	if ${n} >= 1 && ${n} <= 4
	@${MKDIR} ${OUT${n}_DIR}${SWIFT_PREFIX}/bin
.	    for f in swift-build swift-run
	@${INSTALL_SCRIPT} ${FILESDIR}/swift-dummy \
		${OUT${n}_DIR}${SWIFT_PREFIX}/bin/${f}
.	    endfor
.	endif
	cd ${WRKSRC}/swift && \
	${SETENV} ${MAKE_ENV} ./utils/build-script ${STAGE${n}_BUILDFLAGS}
.   endfor
.else
	@${MV} ${WRKSRC}/swift-corelibs-libdispatch/dispatch/module.modulemap \
		${WRKSRC}/swift-corelibs-libdispatch/dispatch/module.modulemap.bak
	@${TOUCH} ${WRKSRC}/swift-corelibs-libdispatch/dispatch/module.modulemap
	cd ${WRKSRC}/swift && \
	${SETENV} ${MAKE_ENV} ./utils/build-script ${SWIFT_BUILDFLAGS}
.endif

do-install:
	cd ${OUT5_DIR} && ${COPYTREE_BIN} .${SWIFT_PREFIX}/bin ${STAGEDIR}
	cd ${OUT5_DIR} && \
	for dir in include lib local share; do \
		${COPYTREE_SHARE} .${SWIFT_PREFIX}/$${dir} ${STAGEDIR}; \
	done
	@${FIND} ${STAGEDIR}${SWIFT_PREFIX} -type f -exec ${FILE} {} ';' | \
		${GREP} 'ELF.*FreeBSD' | ${CUT} -d ':' -f 1 | \
		${XARGS} ${STRIP_CMD} --strip-debug
	@${GZIP_CMD} ${STAGEDIR}${SWIFT_PREFIX}/share/man/man1/swift.1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/swift/|} ${STAGEDIR}${DOCSDIR}

do-test:
	cd ${WRKSRC}/swift && \
	${SETENV} ${TEST_ENV} ./utils/run-test \
		--build-dir ${WRKSRC}/build/Ninja-Release \
		--build skip \
		--build-jobs ${MAKE_JOBS_NUMBER}

.if defined(BOOTSTRAP_MODE)
# Prepare pre-generated full swift toolchain for non-bootstrap builds by
# general users. The packages used here were produced locally using poudriere
# with bootstrap mode.
make-bootstrap-archive:
	@${RM} -r ${STAGEDIR}
	@${MKDIR} ${STAGEDIR}
	${TAR} -xz --strip-components 1 \
		-f ${WRKDIR}/${PORTNAME}${PKGNAMESUFFIX}-${DISTVERSION}.pkg \
		-C ${STAGEDIR}
	${TAR} -cJf ${WRKDIR}/${PORTNAME}${PKGNAMESUFFIX}-bootstrap-${DISTVERSION}-${SWIFT_ARCH}-unknown-${OPSYS:tl}${EXTRACT_SUFX} \
		--options 'xz:threads=0' \
		-s '|^\./|${PORTNAME}${PKGNAMESUFFIX}-bootstrap/|' \
		-C ${STAGEDIR} .
.endif

.include <bsd.port.post.mk>
