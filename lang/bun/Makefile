PORTNAME=	bun
DISTVERSIONPREFIX=	bun-v
DISTVERSION=	1.4.4
CATEGORIES=	lang

LLVM_VER=	23
NODE_VERSION=	26.3.0
# samm-git/WebKit release = bun's pinned commit (d6375c72affe0f70) + the FreeBSD
# membarrier fix.  bun keys its prebuilt cache/identity by the commit *it* pins,
# so WEBKIT_COMMIT/WEBKIT_SHORT use that, not the fork's WEBKIT_VERSION.
WEBKIT_VERSION=	b590f37da67cd02009bec23d112167cc1bf1a1d3
WEBKIT_COMMIT=	d6375c72affe0f70222cdcb45012b10f0bf3a9d5
WEBKIT_SHORT=	d6375c72affe0f70
# Full sha: bun's build const-slices it and the source tarball has no .git.
BUN_GIT_SHA=	38afee6c84fcf48c0edb2466aa4b27d287a59c30

# bun needs a Rust nightly: its source uses unstable `#![feature(...)]`s (stable
# rustc fails E0554) and the release profile passes -Zbuild-std (which needs
# rust-src).  lang/rust-nightly is a moving target and its updates have broken
# bun's type_info reflection patches, so depend on the pinned binary toolchain
# in lang/rust-nightly-bun instead.  Bumping that port is a deliberate change:
# re-sync src/collections/multi_array_list.rs from bun main, regenerate
# patch-src_collections_{multi_array_list,lib}.rs, update RUSTC_TESTED_VERSION
# and the rust-nightly-bun pin together.  On a bun bump, refresh
# GH_TUPLE/_BUN_DEP_CACHE and run `make makesum`.
RUSTC_TESTED_VERSION=	1.100.0-nightly (feaadeeac 2026-09-19)

MASTER_SITES=	GH \
		https://github.com/oven-sh/bun/releases/download/${DISTVERSIONPREFIX}${DISTVERSION}/:bootstrap \
		https://github.com/samm-git/WebKit/releases/download/autobuild-${WEBKIT_VERSION}/:webkit \
		https://nodejs.org/dist/v${NODE_VERSION}/:nodehdr
DISTFILES=	bun-freebsd-${BUN_ASSET_ARCH}.zip:bootstrap \
		bun-webkit-freebsd-${WEBKIT_ASSET_ARCH}.tar.gz:webkit \
		node-v${NODE_VERSION}-headers.tar.gz:nodehdr
DIST_SUBDIR=	${PORTNAME}
# Only the GitHub source tarball is auto-extracted; the bootstrap/WebKit/headers
# tarballs are unpacked by hand in post-extract.
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX} \
		${CARGO_CRATES:S/^/rust\/crates\//:S/$/.crate/}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	JavaScript runtime, bundler, test runner, and package manager
WWW=		https://bun.com/ \
		https://github.com/oven-sh/bun

LICENSE=	MIT LGPL20
LICENSE_COMB=	multi

ONLY_FOR_ARCHS=		aarch64 amd64
ONLY_FOR_ARCHS_REASON=	requires an upstream FreeBSD bootstrap binary (only aarch64/amd64 are published)

USES=		shebangfix cargo
USE_GITHUB=	yes
GH_ACCOUNT=	oven-sh
GH_TUPLE=	oven-sh:boringssl:41bf9b59c2ebf277a7aa427e1ecad5cc80dd4d4f:boringssl \
		google:brotli:db24a98aed38a16de78cc05ca15cdd8dc2a0d92d:brotli \
		c-ares:c-ares:c7a3138dcfe3bb0eaaf10c0c24c36dc66dc790ab:cares \
		HdrHistogram:HdrHistogram_c:18c7a324383dded1451d15621cd018b0048057d0:hdrhistogram \
		google:highway:2607d3b5b0113992fe84d3848859eae13b3b52c1:highway \
		libarchive:libarchive:27cbc7827172698143e440801fc0ba39ccb4f1f5:libarchive \
		ebiggers:libdeflate:92e6a0db9fa848d742f9eb286c92afc60f2c3dda:libdeflate \
		libjpeg-turbo:libjpeg-turbo:c85e6b905bf237038faa936dab160ebfc5da0344:libjpeg_turbo \
		randy408:libspng:fb768002d4288590083a476af628e51c3f1d47cd:libspng \
		oven-sh:libuv:8023581113b276e7c1aee3f82da57ca0893faab1:libuv \
		webmproject:libwebp:b7e29b9d75bd31422b00c2a446d49d7af06c328d:libwebp \
		oven-sh:lol-html:725ce499aa9b71e38b7a2d0a9fbb6d7294a4079e:lolhtml \
		litespeedtech:ls-hpack:cf0f70dd10b352194c97448eb5d00b4aa484f531:lshpack \
		litespeedtech:ls-qpack:91567706c41c0d97ab8dc576873ecd472d7869fa:lsqpack \
		litespeedtech:lsquic:f812ceb9529e26717df78c6064a2ff648b949f3e:lsquic \
		oven-sh:mimalloc:92ef6587c57b262f6e6abf513f7776a2f8d12aeb:mimalloc \
		h2o:picohttpparser:f4d94b48b31e0abae029ebeafcfd9ca0680ede58:picohttpparser \
		sru-systems:rust-argon2:ed81866f163f0c7026aa6fd8388adf37242eb32a:rust_argon2 \
		oven-sh:tinycc:05f0fafaa3be31e31d7b4b5c17dc60f62c991171:tinycc \
		zlib-ng:zlib-ng:12731092979c6d07f42da27da673a9f6c7b13586:zlib \
		facebook:zstd:f8745da6ff1ad1e7bab384bd1f9d742439278e99:zstd
SHEBANG_FILES=	test/regression/issue/18239/data-generator.sh

BUILD_DEPENDS=	${LOCALBASE}/llvm${LLVM_VER}/bin/clang++:devel/llvm${LLVM_VER} \
		${LOCALBASE}/llvm${LLVM_VER}/bin/ld.lld:devel/llvm${LLVM_VER} \
		${RUST_PREFIX}/bin/cargo:lang/rust-nightly-bun \
		${LOCALBASE}/bin/cmake:devel/cmake-core \
		${LOCALBASE}/bin/ninja:devel/ninja \
		git:devel/git
# do-fetch builds the offline caches, so the toolchain is needed at fetch too.
FETCH_DEPENDS=	${RUST_PREFIX}/bin/cargo:lang/rust-nightly-bun

RUST_PREFIX=		${LOCALBASE}/rust-nightly-bun
CARGO_BUILDDEP=		no
CARGO=			${RUST_PREFIX}/bin/cargo
RUSTC=			${RUST_PREFIX}/bin/rustc
RUSTDOC=			${RUST_PREFIX}/bin/rustdoc
CARGO_CONFIGURE=	no
CARGO_BUILD=		no
CARGO_INSTALL=		no
CARGO_TEST=		no

.include <bsd.port.pre.mk>

# Asset names: bun uses x64/aarch64, the WebKit prebuilt amd64/arm64.
.if ${ARCH} == amd64
BUN_ASSET_ARCH=		x64
WEBKIT_ASSET_ARCH=	amd64
WEBKIT_CACHE_SUFFIX=
# bun assembles x86-only crypto code (BoringSSL) with nasm at build time.
BUILD_DEPENDS+=		${LOCALBASE}/bin/nasm:devel/nasm
.elif ${ARCH} == aarch64
BUN_ASSET_ARCH=		aarch64
WEBKIT_ASSET_ARCH=	arm64
WEBKIT_CACHE_SUFFIX=	-arm64
.endif

# Keep checksums for both supported architectures in distinfo.  A normal
# fetch only needs the current architecture, but `make makesum` must include
# both so it does not drop the other one.
.if make(makesum)
DISTFILES=	bun-freebsd-x64.zip:bootstrap \
		bun-webkit-freebsd-amd64.tar.gz:webkit \
		node-v${NODE_VERSION}-headers.tar.gz:nodehdr \
		bun-freebsd-aarch64.zip:bootstrap \
		bun-webkit-freebsd-arm64.tar.gz:webkit
.endif

DD=		${DISTDIR}/${DIST_SUBDIR}
BUN_BOOTSTRAP_DIR=	${WRKDIR}/bun-bootstrap
BUN_BOOTSTRAP=		${BUN_BOOTSTRAP_DIR}/bun
BUN_CACHE_DIR=		${WRKDIR}/bun-cache
BUN_BUILD_DIR=		${WRKSRC}/build/release
BUN_INSTALL_CACHE_DIR=	${WRKDIR}/bun-install-cache
CARGO_HOME=		${WRKDIR}/cargo-home
# USES=cargo adds crate distfiles after ALLFILES is first expanded; keep
# makesum/checksum aware of them.
_CKSUMFILES=		${ALLFILES:S/^/${DIST_SUBDIR}\//} \
			${CARGO_CRATES:S/^/rust\/crates\//:S/$/.crate/:S/^/${DIST_SUBDIR}\//}
WEBKIT_CACHE_DIR=	${BUN_CACHE_DIR}/webkit-${WEBKIT_SHORT}-freebsd${WEBKIT_CACHE_SUFFIX}
NODE_HEADERS_CACHE_DIR=	${BUN_CACHE_DIR}/nodejs-headers-${NODE_VERSION}

PLIST_FILES=	bin/${PORTNAME}

# Upstream dependency archives are fetched as normal distfiles (GH_TUPLE) and
# copied into the build's tarball cache in post-extract.  The cache name is
# <dep>-<sha256(url)[0:16]>.tar.gz, as expected by scripts/build/fetch-cli.ts.
# Keep this list in sync with GH_TUPLE.  On a bun bump, take the dependency
# URLs from scripts/build/deps/*.ts, refresh GH_TUPLE and the cache names here,
# then run `make makesum`.
_BUN_DEP_CACHE=	\
		boringssl-ce854d7300ee8a35.tar.gz:oven-sh-boringssl-41bf9b59c2ebf277a7aa427e1ecad5cc80dd4d4f_GH0.tar.gz \
		brotli-27f9ec806f9750c6.tar.gz:google-brotli-db24a98aed38a16de78cc05ca15cdd8dc2a0d92d_GH0.tar.gz \
		cares-1685a3355527fdec.tar.gz:c-ares-c-ares-c7a3138dcfe3bb0eaaf10c0c24c36dc66dc790ab_GH0.tar.gz \
		hdrhistogram-89207ecaa5b6a22f.tar.gz:HdrHistogram-HdrHistogram_c-18c7a324383dded1451d15621cd018b0048057d0_GH0.tar.gz \
		highway-b2dcc6002e95cc47.tar.gz:google-highway-2607d3b5b0113992fe84d3848859eae13b3b52c1_GH0.tar.gz \
		libarchive-1a3a126350c6e47f.tar.gz:libarchive-libarchive-27cbc7827172698143e440801fc0ba39ccb4f1f5_GH0.tar.gz \
		libdeflate-9113bd7317ae5193.tar.gz:ebiggers-libdeflate-92e6a0db9fa848d742f9eb286c92afc60f2c3dda_GH0.tar.gz \
		libjpeg-turbo-a7b6d7c73979a459.tar.gz:libjpeg-turbo-libjpeg-turbo-c85e6b905bf237038faa936dab160ebfc5da0344_GH0.tar.gz \
		libspng-e6aca86c593b51ad.tar.gz:randy408-libspng-fb768002d4288590083a476af628e51c3f1d47cd_GH0.tar.gz \
		libuv-0f29c74cc80722ca.tar.gz:oven-sh-libuv-8023581113b276e7c1aee3f82da57ca0893faab1_GH0.tar.gz \
		libwebp-2ced709f169b40bd.tar.gz:webmproject-libwebp-b7e29b9d75bd31422b00c2a446d49d7af06c328d_GH0.tar.gz \
		lolhtml-d63099fc6ce4f6e5.tar.gz:oven-sh-lol-html-725ce499aa9b71e38b7a2d0a9fbb6d7294a4079e_GH0.tar.gz \
		lshpack-57f11d39f91979cb.tar.gz:litespeedtech-ls-hpack-cf0f70dd10b352194c97448eb5d00b4aa484f531_GH0.tar.gz \
		lsqpack-24fd48c0f630f603.tar.gz:litespeedtech-ls-qpack-91567706c41c0d97ab8dc576873ecd472d7869fa_GH0.tar.gz \
		lsquic-ecd56644a06346db.tar.gz:litespeedtech-lsquic-f812ceb9529e26717df78c6064a2ff648b949f3e_GH0.tar.gz \
		mimalloc-139477488b3dc239.tar.gz:oven-sh-mimalloc-92ef6587c57b262f6e6abf513f7776a2f8d12aeb_GH0.tar.gz \
		picohttpparser-f0abcbe6c6083ef3.tar.gz:h2o-picohttpparser-f4d94b48b31e0abae029ebeafcfd9ca0680ede58_GH0.tar.gz \
		rust-argon2-87c5404c7fc9aa9c.tar.gz:sru-systems-rust-argon2-ed81866f163f0c7026aa6fd8388adf37242eb32a_GH0.tar.gz \
		tinycc-e715321533b32b83.tar.gz:oven-sh-tinycc-05f0fafaa3be31e31d7b4b5c17dc60f62c991171_GH0.tar.gz \
		zlib-655c6ecdb6fc9cd5.tar.gz:zlib-ng-zlib-ng-12731092979c6d07f42da27da673a9f6c7b13586_GH0.tar.gz \
		zstd-e010993a24072468.tar.gz:facebook-zstd-f8745da6ff1ad1e7bab384bd1f9d742439278e99_GH0.tar.gz

_BUN_LOLHTML_DISTFILE=	oven-sh-lol-html-725ce499aa9b71e38b7a2d0a9fbb6d7294a4079e_GH0.tar.gz
_BUN_RUST_ARGON2_DISTFILE=	sru-systems-rust-argon2-ed81866f163f0c7026aa6fd8388adf37242eb32a_GH0.tar.gz

# post-fetch builds the derived bun install cache.  Dependency source archives
# and Rust crates are normal distfiles (GH_TUPLE and USES=cargo).
post-fetch:
	@${ECHO_MSG} "===> Building bun install cache"
	@${MKDIR} ${BUN_BOOTSTRAP_DIR}
	@cd ${BUN_BOOTSTRAP_DIR} && ${TAR} xf ${DD}/bun-freebsd-${BUN_ASSET_ARCH}.zip
	@${MV} ${BUN_BOOTSTRAP_DIR}/bun-freebsd-${BUN_ASSET_ARCH}/bun ${BUN_BOOTSTRAP}
	@${CHMOD} +x ${BUN_BOOTSTRAP}
	# 1. Dependency archives are standard distfiles (GH_TUPLE); they are
	# copied into the build cache in post-extract.
	# 2. extract the pristine source once, for bun install cache warming
	@${RM} -rf ${WRKDIR}/gen && ${MKDIR} ${WRKDIR}/gen
	@${TAR} xf ${DD}/${DISTNAME}${EXTRACT_SUFX} -C ${WRKDIR}/gen
	# 3. warm the bun install cache (root + the two standalone package dirs)
	@if [ ! -f "${DD}/bun-install-cache-${DISTVERSION}.tar.gz" ]; then \
		${ECHO_MSG} "  bun install (warming cache)"; \
		cd ${WRKDIR}/gen/${WRKSRC:T} && \
			${SETENV} BUN_INSTALL_CACHE_DIR=${BUN_INSTALL_CACHE_DIR} \
				${BUN_BOOTSTRAP} install --frozen-lockfile && \
		cd ${WRKDIR}/gen/${WRKSRC:T}/packages/bun-error && \
			${SETENV} BUN_INSTALL_CACHE_DIR=${BUN_INSTALL_CACHE_DIR} \
				${BUN_BOOTSTRAP} install --frozen-lockfile && \
		cd ${WRKDIR}/gen/${WRKSRC:T}/src/node-fallbacks && \
			${SETENV} BUN_INSTALL_CACHE_DIR=${BUN_INSTALL_CACHE_DIR} \
				${BUN_BOOTSTRAP} install --frozen-lockfile && \
		${TAR} czf ${DD}/bun-install-cache-${DISTVERSION}.tar.gz \
			-C ${BUN_INSTALL_CACHE_DIR} .; \
	fi

post-extract:
	# Bootstrap bun (official upstream FreeBSD release binary)
	@${MKDIR} ${BUN_BOOTSTRAP_DIR}
	@cd ${BUN_BOOTSTRAP_DIR} && ${TAR} xf ${DD}/bun-freebsd-${BUN_ASSET_ARCH}.zip
	@${MV} ${BUN_BOOTSTRAP_DIR}/bun-freebsd-${BUN_ASSET_ARCH}/bun ${BUN_BOOTSTRAP}
	@${CHMOD} +x ${BUN_BOOTSTRAP}
	# WebKit prebuilt (JSC/WTF), including its bundled ICU headers
	@${MKDIR} ${WEBKIT_CACHE_DIR}
	@${TAR} xf ${DD}/bun-webkit-freebsd-${WEBKIT_ASSET_ARCH}.tar.gz \
		-C ${WEBKIT_CACHE_DIR} --strip-components 1
	@${ECHO_CMD} "${WEBKIT_COMMIT}" > ${WEBKIT_CACHE_DIR}/.identity
	# Node.js headers into the build cache
	@${MKDIR} ${NODE_HEADERS_CACHE_DIR}
	@${TAR} xf ${DD}/node-v${NODE_VERSION}-headers.tar.gz \
		-C ${NODE_HEADERS_CACHE_DIR} --strip-components 1
	@${RM} -rf ${NODE_HEADERS_CACHE_DIR}/include/node/openssl \
		${NODE_HEADERS_CACHE_DIR}/include/node/uv \
		${NODE_HEADERS_CACHE_DIR}/include/node/uv.h
	@${ECHO_CMD} "${NODE_VERSION}" > ${NODE_HEADERS_CACHE_DIR}/.identity
	# dependency tarball cache + warmed bun install cache
	@${MKDIR} ${BUN_CACHE_DIR}/tarballs
	@for _e in ${_BUN_DEP_CACHE}; do \
		_cache=$${_e%%:*}; _dist=$${_e#*:}; \
		${CP} ${DD}/$${_dist} ${BUN_CACHE_DIR}/tarballs/$${_cache}; \
	done
	@${MKDIR} ${BUN_INSTALL_CACHE_DIR}
	# Cargo uses the vendored crates fetched by USES=cargo.  Keep this in
	# $CARGO_HOME rather than the project .cargo/config.toml, which the bun
	# build regenerates for its own linker settings.
	@${MKDIR} ${CARGO_HOME}
	@${ECHO_CMD} "[source.cargo]" > ${CARGO_HOME}/config.toml
	@${ECHO_CMD} "directory = '${CARGO_VENDOR_DIR}'" >> ${CARGO_HOME}/config.toml
	@${ECHO_CMD} "[source.crates-io]" >> ${CARGO_HOME}/config.toml
	@${ECHO_CMD} "replace-with = 'cargo'" >> ${CARGO_HOME}/config.toml
	@${TAR} xf ${DD}/bun-install-cache-${DISTVERSION}.tar.gz -C ${BUN_INSTALL_CACHE_DIR}

# Fail early if the pinned toolchain is not the one these patches target.
pre-configure:
	@if ${RUST_PREFIX}/bin/rustc --version | ${GREP} -Fq "${RUSTC_TESTED_VERSION}"; then \
		${ECHO_MSG} "Rust nightly matches ${RUSTC_TESTED_VERSION}"; \
	else \
		${ECHO_MSG} "bun requires Rust ${RUSTC_TESTED_VERSION}; installed:"; \
		${RUST_PREFIX}/bin/rustc --version | ${SED} 's/^/    /'; \
		if [ "${ALLOW_UNTESTED_RUST}" != "yes" ]; then \
			${ECHO_MSG} "Refusing to build; set ALLOW_UNTESTED_RUST=yes to override."; \
			exit 1; \
		fi; \
		${ECHO_MSG} "ALLOW_UNTESTED_RUST=yes set; continuing."; \
	fi

do-build:
	@cd ${WRKSRC} && ${SETENV} \
		PATH=${RUST_PREFIX}/bin:${LOCALBASE}/llvm${LLVM_VER}/bin:${LOCALBASE}/bin:/usr/bin:/bin \
		BUN_TOOLCHAIN_LLVM=${LOCALBASE}/llvm${LLVM_VER} \
		BUN_TOOLCHAIN_RUST=${RUST_PREFIX} \
		BUN_TOOLCHAIN_CARGO=${RUST_PREFIX}/bin/cargo \
		CC=clang \
		CXX=clang++ \
		CARGO_HOME=${CARGO_HOME} \
		CARGO_NET_OFFLINE=true \
		BUN_INSTALL_CACHE_DIR=${BUN_INSTALL_CACHE_DIR} \
		GIT_SHA=${BUN_GIT_SHA} \
		${BUN_BOOTSTRAP} scripts/build.ts \
			--profile=release \
			--canary=off \
			--cacheDir=${BUN_CACHE_DIR} \
			--buildDir=${BUN_BUILD_DIR} \
			-j${MAKE_JOBS_NUMBER}

do-install:
	${INSTALL_PROGRAM} ${BUN_BUILD_DIR}/bun ${STAGEDIR}${PREFIX}/bin/

do-test:
	@${ECHO_MSG} "==> Running Bun smoke tests..."
	${STAGEDIR}${PREFIX}/bin/bun --version
	${STAGEDIR}${PREFIX}/bin/bun -e 'console.log("hello from", process.platform, process.arch)'

.include <bsd.port.post.mk>
