PORTNAME=	swift
DISTVERSIONPREFIX=	swift-
DISTVERSION=	6.4.0
DISTVERSIONSUFFIX=	-RELEASE
PORTREVISION=	1
CATEGORIES=	lang
PKGNAMESUFFIX=	6
DIST_SUBDIR=	${PORTNAME}

OLD_SWIFT_VERSION=		6.3.3
.if !defined(BOOTSTRAP_MODE)
BOOTSTRAP_SWIFT_VERSION=	${DISTVERSION}
.else
BOOTSTRAP_SWIFT_VERSION=	${OLD_SWIFT_VERSION}
.endif
MASTER_SITES=	LOCAL/tagattie/${PORTNAME}:bootstrap
.if make(makesum) && defined(MAKESUM_MODE)
.   for version in ${OLD_SWIFT_VERSION} ${DISTVERSION}
DISTFILES+=	${PORTNAME}${PKGNAMESUFFIX}-bootstrap-${version}-${SWIFT_ARCH}-unknown-${OPSYS:tl}${EXTRACT_SUFX}:bootstrap
.   endfor
.else
DISTFILES=	${PORTNAME}${PKGNAMESUFFIX}-bootstrap-${BOOTSTRAP_SWIFT_VERSION}-${SWIFT_ARCH}-unknown-${OPSYS:tl}${EXTRACT_SUFX}:bootstrap
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
		google:boringssl:0.20250818.0-64-g0226f3046:boringssl/boringssl \
		swiftlang:swift-cmark:${DISTVERSIONFULL}:swift_cmark/cmark \
		swiftlang:indexstore-db:${DISTVERSIONFULL}:indexstore_db/indexstore-db \
		swiftlang:swift-llbuild:${DISTVERSIONFULL}:swift_llbuild/llbuild \
		swiftlang:llvm-project:${DISTVERSIONFULL}:llvm_project/llvm-project \
		swiftlang:sourcekit-lsp:${DISTVERSIONFULL}:sourcekit_lsp/sourcekit-lsp \
		swiftlang:swift:${DISTVERSIONFULL}:swift/swift \
		apple:swift-argument-parser:1.8.2:swift_argument_parser/swift-argument-parser \
		apple:swift-asn1:1.3.2:swift_asn1/swift-asn1 \
		apple:swift-async-algorithms:1.0.1:swift_async_algorithms/swift-async-algorithms \
		apple:swift-atomics:1.3.1:swift_atomics/swift-atomics \
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
		apple:swift-nio:2.92.2:swift_nio/swift-nio \
		apple:swift-numerics:1.0.2:swift_numerics/swift-numerics \
		swiftlang:swift-sdk-generator:${DISTVERSIONFULL}:swift_sdk_generator/swift-sdk-generator \
		swiftlang:swift-stress-tester:${DISTVERSIONFULL}:swift_stress_tester/swift-stress-tester \
		swiftlang:swift-subprocess:0.5:swift_subprocess/swift-subprocess \
		swiftlang:swift-syntax:${DISTVERSIONFULL}:swift_syntax/swift-syntax \
		apple:swift-system:1.5.0:swift_system/swift-system \
		swiftlang:swift-testing:${DISTVERSIONFULL}:swift_testing/swift-testing \
		swiftlang:swift-toolchain-sarif:519c296:swift_toolchain_sarif/swift-toolchain-sarif \
		swiftlang:swift-toolchain-sqlite:1.0.9:swift_toolchain_sqlite/swift-toolchain-sqlite \
		swiftlang:swift-tools-protocols:${DISTVERSIONFULL}:swift_tools_protocols/swift-tools-protocols \
		swiftlang:swift-tools-support-core:${DISTVERSIONFULL}:swift_tools_support_core/swift-tools-support-core \
		swiftlang:swift-package-manager:${DISTVERSIONFULL}:swift_package_manager/swiftpm \
		WebAssembly:wasi-libc:wasi-sdk-32:wasi_libc/wasi-libc \
		swiftwasm:WasmKit:0.3.1:WasmKit/wasmkit

USE_PERL5=	build
USE_GNOME=	libxml2

SHEBANG_FILES=	swift/utils/api_checker/sdk-module-lists/infer-imports.py \
		swift/utils/api_checker/swift-api-checker.py \
		swift/utils/build-script \
		swift/utils/build-script-impl \
		swift/utils/run-test \
		swift/utils/swift-api-dump.py \
		swiftpm/Utilities/bootstrap

BINARY_ALIAS=	python3=${PYTHON_CMD}

WRKSRC=		${WRKDIR}/swift-${DISTVERSION}

PLIST_SUB=	SWIFT_ARCH=${SWIFT_ARCH} \
		SWIFT_TARGET_TRIPLE=${SWIFT_ARCH}-unknown-${OPSYS:tl}
PORTDOCS=	CHANGELOG.md CONTRIBUTING.md README.md

OPTIONS_DEFINE=	DOCS

SWIFT_ARCH=	${ARCH:S/amd64/x86_64/}
# SwiftPM expects swift toolchain executables are located in
# <sdk root>/usr/local/bin.
# See ${WRKSRC}/swiftpm/Sources/PackageModel/Toolchain.swift.
SWIFT_SDK_PREFIX=	${PREFIX}/${PORTNAME}${PKGNAMESUFFIX}
SWIFT_TOOLCHAIN_PREFIX=	/usr/local
BOOTSTRAP_DIR=	${WRKDIR}/${PORTNAME}${PKGNAMESUFFIX}-bootstrap${SWIFT_TOOLCHAIN_PREFIX}
.for n in 0 1 2 3 4 5
OUT${n}_DIR=	${WRKDIR}/out${n}
.endfor
# STAGE0_MODULES=	libdispatch
# STAGE1_MODULES=	${STAGE0_MODULES}
STAGE2_MODULES=	foundation
STAGE3_MODULES=${STAGE2_MODULES} \
		xctest \
		swift-testing
STAGE4_MODULES=	${STAGE3_MODULES} \
		swiftsyntax \
		llbuild \
		swift-testing-macros \
		swiftpm
STAGE5_MODULES=	${STAGE4_MODULES} \
		indexstore-db \
		lldb \
		swift-driver \
		swiftformat \
		swiftdocc \
		sourcekit-lsp
# FIXME: Exclude wasmkit from build for now because it doesn't build
# with a lot of errors from swift-nio
#		wasmkit
SWIFT_MODULES=	${STAGE5_MODULES}
COMMON_BUILDFLAGS=	\
		--build-subdir Ninja-Build \
		--install-prefix ${SWIFT_TOOLCHAIN_PREFIX} \
		--install-all true \
		--jobs ${MAKE_JOBS_NUMBER} \
		--host-cc /usr/bin/clang \
		--host-cxx /usr/bin/clang++ \
		--extra-cmake-options="-DCMAKE_C_FLAGS='${CFLAGS}'" \
		--extra-cmake-options="-DCMAKE_CXX_FLAGS='${CXXFLAGS}'" \
		--extra-cmake-options="-DCLANG_DEFAULT_LINKER=lld" \
		--extra-cmake-options="-DLLVM_ENABLE_LLD=ON" \
		--extra-cmake-options="-DSWIFT_USE_LINKER=lld" \
		--verbose-build true \
		--skip-clean-libdispatch true \
		--llvm-targets-to-build "AArch64;X86" \
		--llvm-install-components "llvm-ar;llvm-nm;llvm-ranlib;llvm-cov;llvm-profdata;llvm-objdump;llvm-objcopy;llvm-symbolizer;IndexStore;clang;clang-resource-headers;builtins;runtimes;clangd;libclang;lld;LTO;clang-features-file" \
		--bootstrapping hosttools \
		${CCACHE_BUILDFLAGS} \
		${RELEASE_BUILDFLAGS}
STAGE0_BUILDFLAGS=	\
		${COMMON_BUILDFLAGS} \
		--install-destdir ${OUT0_DIR} \
		--native-clang-tools-path ${BOOTSTRAP_DIR}/bin \
		--native-llvm-tools-path ${BOOTSTRAP_DIR}/bin \
		--native-swift-tools-path ${BOOTSTRAP_DIR}/bin \
		--extra-cmake-options="-DCMAKE_Swift_COMPILER=${BOOTSTRAP_DIR}/bin/swiftc" \
		--extra-cmake-options="-DSWIFT_BUILD_STDLIB_CXX_MODULE:BOOL=OFF" \
		--extra-cmake-options="-DSWIFT_BUILD_STDLIB_EXTRA_TOOLCHAIN_CONTENT:BOOL=OFF" \
		--build-swift-dynamic-stdlib false \
		--build-swift-static-stdlib false \
		--build-swift-dynamic-sdk-overlay false \
		--build-swift-static-sdk-overlay false \
		--skip-build-freebsd true \
		--skip-test-freebsd true \
		--swift-install-components "autolink-driver;compiler;clang-resource-dir-symlink;tools;toolchain-tools"
STAGE1_BUILDFLAGS=	\
		${COMMON_BUILDFLAGS} \
		--install-destdir ${OUT1_DIR} \
		--native-clang-tools-path ${OUT0_DIR}${SWIFT_TOOLCHAIN_PREFIX}/bin \
		--native-llvm-tools-path ${OUT0_DIR}${SWIFT_TOOLCHAIN_PREFIX}/bin \
		--native-swift-tools-path ${OUT0_DIR}${SWIFT_TOOLCHAIN_PREFIX}/bin \
		--extra-cmake-options="-DCMAKE_Swift_COMPILER=${BOOTSTRAP_DIR}/bin/swiftc" \
		--build-swift-dynamic-stdlib true \
		--build-swift-static-stdlib true \
		--build-swift-dynamic-sdk-overlay true \
		--build-swift-static-sdk-overlay true
.for n p in 2 1 3 2 4 3 5 4
STAGE${n}_BUILDFLAGS=	\
		${COMMON_BUILDFLAGS} \
		--install-destdir ${OUT${n}_DIR} \
		--native-clang-tools-path ${OUT${p}_DIR}${SWIFT_TOOLCHAIN_PREFIX}/bin \
		--native-llvm-tools-path ${OUT${p}_DIR}${SWIFT_TOOLCHAIN_PREFIX}/bin \
		--native-swift-tools-path ${OUT${p}_DIR}${SWIFT_TOOLCHAIN_PREFIX}/bin \
		--extra-cmake-options="-DCMAKE_Swift_COMPILER=${OUT${p}_DIR}${SWIFT_TOOLCHAIN_PREFIX}/bin/swiftc" \
		--build-swift-dynamic-stdlib true \
		--build-swift-static-stdlib true \
		--build-swift-dynamic-sdk-overlay true \
		--build-swift-static-sdk-overlay true
.endfor
SWIFT_BUILDFLAGS=	\
		${COMMON_BUILDFLAGS} \
		--install-destdir ${OUT5_DIR} \
		--native-clang-tools-path ${BOOTSTRAP_DIR}/bin \
		--native-llvm-tools-path ${BOOTSTRAP_DIR}/bin \
		--native-swift-tools-path ${BOOTSTRAP_DIR}/bin \
		--extra-cmake-options="-DCMAKE_Swift_COMPILER=${BOOTSTRAP_DIR}/bin/swiftc" \
		--build-swift-dynamic-stdlib true \
		--build-swift-static-stdlib true \
		--build-swift-dynamic-sdk-overlay true \
		--build-swift-static-sdk-overlay true
STAGE1_ENV=	LD_LIBRARY_PATH=${BOOTSTRAP_DIR}/lib/swift/freebsd
STAGE4_ENV=	SKIP_BUILD_SWIFTPM_INTERNALTESTSUPPORT=1

.if defined(WITH_CCACHE_BUILD) && !defined(NO_CCACHE)
CCACHE_BUILDFLAGS=	--cmake-c-launcher ${CCACHE_BIN} \
			--cmake-cxx-launcher ${CCACHE_BIN}
.endif

.if !defined(WITH_DEBUG)
.   if !defined(BOOTSTRAP_MODE)
RELEASE_BUILDFLAGS=	--release \
			--no-assertions
.   else
RELEASE_BUILDFLAGS=	--release-debuginfo \
			--assertions
.   endif
.else
RELEASE_BUILDFLAGS=	--debug \
			--assertions
.endif

DEVEL_BUILDFLAGS=	--skip-clean-libdispatch true \
			--skip-clean-foundation true \
			--skip-clean-xctest true \
			--skip-clean-llbuild true \
			--skip-clean-swiftpm true \
			--skip-clean-swift-driver true

.if defined(BOOTSTRAP_MODE)
PLIST_SUB+=	NON_BOOTSTRAP="@comment "
.else
PLIST_SUB+=	NON_BOOTSTRAP=""
.endif

.include <bsd.port.pre.mk>

# Bootstrap swift toolchain has been built on FreeBSD 14 jail.
# So we need compat14x on FreeBSD 15 or later.
.if ${OSVERSION} >= 1500000
BUILD_DEPENDS+=	${LOCALBASE}/lib/compat/libutil.so.9:misc/compat14x
.endif

post-extract:
# FIXME: Bootstrap toolchain (6.3.3) has been prepared to use wrong paths.
# So adjust the toolchain paths to meet Swift's expectation.
# Remove this after bootstrap toolchain is updated to 6.4.0.
	@if [ -f ${BOOTSTRAP_DIR}/swift6/bin/swift ]; then \
		${CP} -R ${BOOTSTRAP_DIR}/swift6/* \
			${BOOTSTRAP_DIR}; \
		${RM} -r ${BOOTSTRAP_DIR}/swift6; \
	fi
# Work around a clang 21 header modules/libc++ wchar.h regression on FreeBSD
.if (${OSVERSION} >= 1404501 && ${OSVERSION} < 1500000) || \
    (${OSVERSION} >= 1501501 && ${OSVERSION} < 1600000) || \
     ${OSVERSION} >= 1600017
	@${CP} ${FILESDIR}/extra-swift-wchar.h \
		${WRKSRC}/llvm-project/llvm/include/wchar.h
	@${CP} ${FILESDIR}/extra-swift-wchar.h \
		${WRKSRC}/swift/stdlib/public/SwiftShims/swift/shims/wchar.h
.endif

do-build:
# Stage 0: Bare minimum compiler without macros and stdlib
# Stage 1: Minimum compiler with stdlib, without macros
# Stage 2: Macro-aware compiler + foundation libs
# Stage 3: Stage 2 + testing modules
# Stage 4: Stage 3 + build tools and SwiftPM
# Stage 5: Full toolchain
.if defined(BOOTSTRAP_MODE)
.   for n p in 0 0 1 0 2 1 3 2 4 3 5 4
	@${ECHO_MSG} "======================"
	@${ECHO_MSG} "===>  Building stage ${n}"
	@${ECHO_MSG} "======================"
	@${RM} -r ${WRKSRC}/build ${OUT${n}_DIR}
	# Work around a clang 21 header modules/libc++ wchar.h regression on FreeBSD
.	if (${OSVERSION} >= 1404501 && ${OSVERSION} < 1500000) || \
	   (${OSVERSION} >= 1501501 && ${OSVERSION} < 1600000) || \
	    ${OSVERSION} >= 1600017
	@${MKDIR} ${WRKSRC}/build/Ninja-Build/swift-${OPSYS:tl}-${SWIFT_ARCH}/lib/swift
	@${CP} ${FILESDIR}/extra-swift-wchar.h \
		${WRKSRC}/build/Ninja-Build/swift-${OPSYS:tl}-${SWIFT_ARCH}/lib/swift/wchar.h
.	endif
	# Build process expects swift-build and swift-run to be executable,
	# which are not yet available in these stages. So make symbolic links
	# to those in bootstrap swift toolchain as a workaround.
.	if ${n} >= 2 && ${n} <= 4
	@${MKDIR} ${OUT${n}_DIR}${SWIFT_TOOLCHAIN_PREFIX}/bin
.	    for f in swift-build swift-run
	@${RLN} ${BOOTSTRAP_DIR}/bin/${f} \
		${OUT${n}_DIR}${SWIFT_TOOLCHAIN_PREFIX}/bin/${f}
.	    endfor
.	endif
	# Build libdispatch module first
	cd ${WRKSRC}/swift && \
	${SETENV} ${MAKE_ENV} ${STAGE${n}_ENV} \
		./utils/build-script ${STAGE${n}_BUILDFLAGS} \
		--libdispatch true
	# Tweak libdispatch's VFS overlay file to avoid the error during
	# build of the rest of the modules:
	# error: redefinition of module 'Dispatch'
.	if ${n} >= 2
.	    for lib in libdispatch libdispatch_static
	@${CP} ${WRKSRC}/build/Ninja-Build/${lib}-${OPSYS:tl}-${SWIFT_ARCH}/dispatch-vfs-overlay.yaml \
		${WRKSRC}/build/Ninja-Build/${lib}-${OPSYS:tl}-${SWIFT_ARCH}/dispatch-vfs-overlay.yaml.bak
	@${AWK} '/^    contents:/{print "    contents: []"; exit} {print}' \
		${WRKSRC}/build/Ninja-Build/${lib}-${OPSYS:tl}-${SWIFT_ARCH}/dispatch-vfs-overlay.yaml.bak > \
		${WRKSRC}/build/Ninja-Build/${lib}-${OPSYS:tl}-${SWIFT_ARCH}/dispatch-vfs-overlay.yaml
.	    endfor
	# Build the rest of the modules
	cd ${WRKSRC}/swift && \
	${SETENV} ${MAKE_ENV} ${STAGE${n}_ENV} \
		./utils/build-script ${STAGE${n}_BUILDFLAGS} \
		${DEVEL_BUILDFLAGS} \
		${STAGE${n}_MODULES:C/^/--/:C/$/ true/}
.	endif
.   endfor
.else
.   if (${OSVERSION} >= 1404501 && ${OSVERSION} < 1500000) || \
       (${OSVERSION} >= 1501501 && ${OSVERSION} < 1600000) || \
	${OSVERSION} >= 1600017
	# Work around a clang 21 header modules/libc++ wchar.h regression on FreeBSD
	@${MKDIR} ${WRKSRC}/build/Ninja-Build/swift-${OPSYS:tl}-${SWIFT_ARCH}/lib/swift
	@${CP} ${FILESDIR}/extra-swift-wchar.h \
		${WRKSRC}/build/Ninja-Build/swift-${OPSYS:tl}-${SWIFT_ARCH}/lib/swift/wchar.h
.   endif
	# Build libdispatch module first
	cd ${WRKSRC}/swift && \
	${SETENV} ${MAKE_ENV} \
		./utils/build-script ${SWIFT_BUILDFLAGS} \
		--libdispatch true
	# Tweak libdispatch's VFS overlay file to avoid the error during
	# build of the rest of the modules:
	# error: redefinition of module 'Dispatch'
.   for lib in libdispatch libdispatch_static
	@${CP} ${WRKSRC}/build/Ninja-Build/${lib}-${OPSYS:tl}-${SWIFT_ARCH}/dispatch-vfs-overlay.yaml \
		${WRKSRC}/build/Ninja-Build/${lib}-${OPSYS:tl}-${SWIFT_ARCH}/dispatch-vfs-overlay.yaml.bak
	@${AWK} '/^    contents:/{print "    contents: []"; exit} {print}' \
		${WRKSRC}/build/Ninja-Build/${lib}-${OPSYS:tl}-${SWIFT_ARCH}/dispatch-vfs-overlay.yaml.bak > \
		${WRKSRC}/build/Ninja-Build/${lib}-${OPSYS:tl}-${SWIFT_ARCH}/dispatch-vfs-overlay.yaml
.   endfor
	# Build the rest of the modules
	cd ${WRKSRC}/swift && \
	${SETENV} ${MAKE_ENV} \
		./utils/build-script ${SWIFT_BUILDFLAGS} \
		${SWIFT_MODULES:C/^/--/:C/$/ true/}
.endif

do-install:
.for dir in bin lib
	@${FIND} ${OUT5_DIR}${SWIFT_TOOLCHAIN_PREFIX}/${dir} -type f -exec ${FILE} {} ';' | \
		${GREP} 'ELF.*FreeBSD' | ${CUT} -d ':' -f 1 | \
		${XARGS} ${STRIP_CMD} --strip-debug
.endfor
	cd ${OUT5_DIR} && ${COPYTREE_BIN} .${SWIFT_TOOLCHAIN_PREFIX}/bin ${STAGEDIR}${SWIFT_SDK_PREFIX}
	cd ${OUT5_DIR} && \
	for dir in include lib local share; do \
		${COPYTREE_SHARE} .${SWIFT_TOOLCHAIN_PREFIX}/$${dir} ${STAGEDIR}${SWIFT_SDK_PREFIX}; \
	done
	@${GZIP_CMD} ${STAGEDIR}${SWIFT_SDK_PREFIX}${SWIFT_TOOLCHAIN_PREFIX}/share/man/man1/swift.1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/swift/|} ${STAGEDIR}${DOCSDIR}

do-test:
	cd ${WRKSRC}/swift && \
	${SETENV} ${TEST_ENV} ./utils/run-test \
		--build-dir ${WRKSRC}/build/Ninja-Build \
		--build skip \
		--build-jobs ${MAKE_JOBS_NUMBER}

.if defined(BOOTSTRAP_MODE)
# Prepare pre-generated full swift toolchain for non-bootstrap builds by
# general users. The package used here was produced locally using poudriere
# with bootstrap mode.
make-bootstrap-archive:
	@${RM} -r ${STAGEDIR}
	@${MKDIR} ${STAGEDIR}
	${TAR} -xz --strip-components 4 \
		-f ${WRKDIR}/${PORTNAME}${PKGNAMESUFFIX}-${DISTVERSION}.pkg \
		-C ${STAGEDIR} \
		--include '/usr/local/swift6/*'
	${TAR} -cJf ${WRKDIR}/${PORTNAME}${PKGNAMESUFFIX}-bootstrap-${DISTVERSION}-${SWIFT_ARCH}-unknown-${OPSYS:tl}${EXTRACT_SUFX} \
		--options 'xz:threads=${MAKE_JOBS_NUMBER}' \
		-s '|^\./|${PORTNAME}${PKGNAMESUFFIX}-bootstrap/|' \
		-C ${STAGEDIR} .
.endif

.include <bsd.port.post.mk>
