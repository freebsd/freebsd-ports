PORTNAME=	dart
DISTVERSION=	3.13.5
CATEGORIES=	lang
MASTER_SITES=	https://github.com/pattems/dart-sdk-freebsd/releases/download/${DISTVERSION}/
DISTFILES=	dart-sdk-${DISTVERSION}-src${EXTRACT_SUFX} \
		dart-sdk-${BOOTSTRAP_VERSION}-bootstrap-freebsd15-${ARCH}${EXTRACT_SUFX}
DIST_SUBDIR=	dart

MAINTAINER=	patrick@crandol.com
COMMENT=	Dart programming language SDK
WWW=		https://dart.dev/

LICENSE=	APACHE20 BSD3CLAUSE ICU MIT ZLIB
LICENSE_COMB=	multi
LICENSE_NAME_ICU=	Unicode License V3
LICENSE_FILE_APACHE20=	${WRKSRC}/third_party/perfetto/src/LICENSE
LICENSE_FILE_BSD3CLAUSE=	${WRKSRC}/LICENSE
LICENSE_FILE_ICU=	${WRKSRC}/third_party/icu/LICENSE
LICENSE_FILE_MIT=	${WRKSRC}/third_party/pkg/tar/LICENSE
LICENSE_FILE_ZLIB=	${WRKSRC}/third_party/zlib/LICENSE
LICENSE_PERMS_ICU=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

ONLY_FOR_ARCHS=	aarch64 amd64
ONLY_FOR_ARCHS_REASON=	no bootstrap SDK for other architectures yet

BUILD_DEPENDS=	gn:devel/gn

USES=		ninja:build python:build tar:xz

MAKE_ENV=	HOME=${WRKDIR}

# The build scripts ask git for version information and cope with git
# failing, but not with it being absent.
BINARY_ALIAS=	git=false python3=${PYTHON_CMD}

# The source distfile is a gclient checkout of the release tag without the
# prebuilt Linux toolchains. The bootstrap is a FreeBSD build of the Dart
# SDK, used to run the Dart parts of the build. Both are made with the tools
# in https://github.com/pattems/dart-sdk-freebsd: tools/make-dist.sh for
# the source, and docs/bootstrap.md describes the bootstraps.
BOOTSTRAP_VERSION=	3.13.5

DART_ARCH=	${ARCH:S/aarch64/arm64/:S/amd64/x64/}

WRKSRC=		${WRKDIR}/dart-sdk-${DISTVERSION}

# Same arguments as tools/gn.py --mode release --arch x64 (or arm64), except
# for those that need a git checkout (verify_sdk_hash, dart_version_git_info).
# Perfetto is off by default on FreeBSD; the patch-third__party_perfetto_*
# files backport Perfetto's FreeBSD support so it can be enabled.
GN_ARGS=	target_os="freebsd" \
		host_cpu="${DART_ARCH}" \
		target_cpu="${DART_ARCH}" \
		dart_target_arch="${DART_ARCH}" \
		dart_use_compressed_pointers=false \
		dart_use_crashpad=false \
		dart_snapshot_kind="app-jit" \
		is_debug=false \
		is_release=true \
		is_product=false \
		dart_debug=false \
		dart_runtime_mode="develop" \
		is_clang=true \
		dart_stripped_binary="exe.stripped/dart" \
		dartvm_stripped_binary="exe.stripped/dartvm" \
		dart_aotruntime_stripped_binary="exe.stripped/dartaotruntime_product" \
		gen_snapshot_stripped_binary="exe.stripped/gen_snapshot_product" \
		analyze_snapshot_binary="exe.stripped/analyze_snapshot" \
		wasm_opt_stripped_binary="exe.stripped/wasm-opt" \
		use_rbe=false \
		verify_sdk_hash=false \
		dart_version_git_info=false \
		dart_support_perfetto=true

.include <bsd.port.options.mk>

.if ${OSVERSION} < 1405000
IGNORE=		requires FreeBSD 14.5 or later
.endif

# Record the bootstrap for every architecture in distinfo.
.if make(makesum)
DISTFILES=	dart-sdk-${DISTVERSION}-src${EXTRACT_SUFX} \
		${ONLY_FOR_ARCHS:@a@dart-sdk-${BOOTSTRAP_VERSION}-bootstrap-freebsd15-${a}${EXTRACT_SUFX}@}
.endif

SDKDIR=		lib/dart
SDK_PROGRAMS=	bin/dart bin/dartaotruntime bin/dartvm bin/utils/gen_snapshot \
		bin/utils/wasm-opt

post-extract:
	${MV} ${WRKDIR}/dart-sdk ${WRKSRC}/tools/sdks/dart-sdk

# The patches are generated from a git series written to go upstream
# (patches/${DISTVERSION} in https://github.com/pattems/dart-sdk-freebsd);
# "series NNNN" in their headers refers to it. Files the series adds are in
# ${FILESDIR}.
post-patch:
	${CP} ${FILESDIR}/largefile.h ${WRKSRC}/runtime/platform/
	${CP} ${FILESDIR}/process_signal_map.h ${WRKSRC}/runtime/bin/

do-configure:
	${MKDIR} ${WRKSRC}/out/release
	@${RM} ${WRKSRC}/out/release/args.gn
.for a in ${GN_ARGS}
	@${ECHO_CMD} '${a}' >> ${WRKSRC}/out/release/args.gn
.endfor
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} gn gen out/release

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		ninja -C out/release -j ${MAKE_JOBS_NUMBER} create_sdk

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${SDKDIR}
	cd ${WRKSRC}/out/release/dart-sdk && \
		${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/${SDKDIR}
	${FIND} ${STAGEDIR}${PREFIX}/${SDKDIR} -name '*.sym' -delete
# The SDK already contains the stripped binaries (see *_stripped_binary),
# but not stripped AOT snapshots, which are ELF shared objects with
# DWARF. The VM doesn't need it for Dart stack traces.
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SDKDIR}/bin/snapshots/*_aot.dart.snapshot \
		${STAGEDIR}${PREFIX}/${SDKDIR}/bin/snapshots/dart2bytecode.dart.snapshot \
		${STAGEDIR}${PREFIX}/${SDKDIR}/bin/snapshots/dart2wasm_product.snapshot
	cd ${STAGEDIR}${PREFIX}/${SDKDIR} && ${CHMOD} 555 ${SDK_PROGRAMS}
	${RLN} ${STAGEDIR}${PREFIX}/${SDKDIR}/bin/dart ${STAGEDIR}${PREFIX}/bin/dart
	${RLN} ${STAGEDIR}${PREFIX}/${SDKDIR}/bin/dartaotruntime \
		${STAGEDIR}${PREFIX}/bin/dartaotruntime

.include <bsd.port.mk>
