PORTNAME=	bun
DISTVERSIONPREFIX=	bun-v
DISTVERSION=	1.3.14
PORTREVISION=	3
CATEGORIES=	lang
MASTER_SITES=	GH \
		https://github.com/oven-sh/zig/releases/download/autobuild-04e7f6ac1e009525bc00934f20199c68f04e0a24/:ovenzig \
		https://github.com/oven-sh/WebKit/releases/download/autobuild-${WEBKIT_VERSION}/:webkit \
		https://nodejs.org/dist/v${NODE_VERSION}/:nodejshdr \
		LOCAL/yuri/:bootstrap
DISTFILES=	bootstrap-x86_64-linux-musl.zip:ovenzig \
		bun-webkit-freebsd-amd64.tar.gz:webkit \
		node-v${NODE_VERSION}-headers.tar.gz:nodejshdr \
		bun-1.3.13-93-bootstrap:bootstrap \
		bun-node-modules-${DISTVERSION}.tar.gz:bootstrap \
		bun-dep-tarballs-${DISTVERSION}.tar.gz:bootstrap \
		bun-cargo-vendor-lolhtml-${DISTVERSION}.tar.gz:bootstrap
DIST_SUBDIR=	${PORTNAME}
# Only auto-extract the GitHub source tarball; everything else is handled in post-extract.
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	JavaScript runtime, bundler, test runner, and package manager
WWW=		https://bun.com/ \
		https://github.com/oven-sh/bun

LICENSE=	LGPL20

ONLY_FOR_ARCHS=		amd64
ONLY_FOR_ARCHS_REASON=	bootstrap binary is only available for amd64 for now

# do-fetch requires npm (node_modules build) and cargo (lolhtml vendor)
FETCH_DEPENDS=	${LOCALBASE}/bin/npm:www/npm-node24 \
		git:devel/git \
		cargo:lang/rust \
		${LOCALBASE}/llvm${LLVM_VER}/bin/clang++:devel/llvm${LLVM_VER} \
		cmake:devel/cmake-core \
		ninja:devel/ninja \
		${LOCALBASE}/bin/node:www/node24
BUILD_DEPENDS=	${LOCALBASE}/llvm${LLVM_VER}/bin/clang++:devel/llvm${LLVM_VER} \
		cmake:devel/cmake-core \
		git:devel/git \
		ninja:devel/ninja \
		cargo:lang/rust \
		${LOCALBASE}/bin/node:www/node24 \
		${LOCALBASE}/bin/npm:www/npm-node24
TEST_DEPENDS=	bash:shells/bash

USES=		shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	oven-sh
GH_TUPLE=	simdutf:simdutf:v${SIMDUTF_VERSION}:simdutf_src

SHEBANG_FILES=	test/regression/issue/18239/data-generator.sh

LLVM_VER=	21 # build fails with llvm-19: error: unknown warning option '-Wno-character-conversion'

# WebKit/JavaScriptCore FreeBSD prebuilt
WEBKIT_VERSION=	bdf6aab38a9c6f99df3fd1486406ab6b74180fbb
WEBKIT_SHORT=	bdf6aab38a9c6f99
# simdutf source (used to rebuild SIMDUTF.cpp.o in libWTF.a for baseline builds)
SIMDUTF_VERSION=	8.2.0
# Node.js headers (official tarball from nodejs.org; do-fetch trims unused dirs)
NODE_VERSION=	24.3.0

# Custom tarballs are built by do-fetch and stored in DD.
# They are NOT listed in DISTFILES so checksum phase does not verify them.

# Dep tarball cache names and their upstream GitHub URLs.
# Names are {depname}-{sha256(url)[0:16]}.tar.gz (computed by bun's fetch-cli.ts).
# Used by do-fetch to pre-populate the bun dep tarballs cache.
_BUN_DEP_TARBALLS=	\
	boringssl-5e15ff9594809574.tar.gz:https://github.com/oven-sh/boringssl/archive/0c5fce43b7ed5eb6001487ee48ac65766f5ddcd1.tar.gz \
	brotli-723494d4c3a9902a.tar.gz:https://github.com/google/brotli/archive/v1.1.0.tar.gz \
	cares-4e43539b43c0f4ae.tar.gz:https://github.com/c-ares/c-ares/archive/3ac47ee46edd8ea40370222f91613fc16c434853.tar.gz \
	hdrhistogram-97084f213075a65e.tar.gz:https://github.com/HdrHistogram/HdrHistogram_c/archive/be60a9987ee48d0abf0d7b6a175bad8d6c1585d1.tar.gz \
	highway-b2dcc6002e95cc47.tar.gz:https://github.com/google/highway/archive/2607d3b5b0113992fe84d3848859eae13b3b52c1.tar.gz \
	libarchive-4296b191210d6b1b.tar.gz:https://github.com/libarchive/libarchive/archive/ded82291ab41d5e355831b96b0e1ff49e24d8939.tar.gz \
	libdeflate-ce0e2d9805b30dcc.tar.gz:https://github.com/ebiggers/libdeflate/archive/c8c56a20f8f621e6a966b716b31f1dedab6a41e3.tar.gz \
	libjpeg-turbo-297099166a01f75e.tar.gz:https://github.com/libjpeg-turbo/libjpeg-turbo/archive/e352b02f794f701407b39af08576035ba3360d60.tar.gz \
	libspng-e6aca86c593b51ad.tar.gz:https://github.com/randy408/libspng/archive/fb768002d4288590083a476af628e51c3f1d47cd.tar.gz \
	libwebp-2ced709f169b40bd.tar.gz:https://github.com/webmproject/libwebp/archive/b7e29b9d75bd31422b00c2a446d49d7af06c328d.tar.gz \
	lolhtml-929339b1d898e66b.tar.gz:https://github.com/cloudflare/lol-html/archive/77127cd2b8545998756e8d64e36ee2313c4bb312.tar.gz \
	lshpack-73e0c55d12ea4fc2.tar.gz:https://github.com/litespeedtech/ls-hpack/archive/8905c024b6d052f083a3d11d0a169b3c2735c8a1.tar.gz \
	lsqpack-ceeb8e315778b938.tar.gz:https://github.com/litespeedtech/ls-qpack/archive/1e9c5b8e59f8161c54f168a570c8bfdc59ded0c3.tar.gz \
	lsquic-d3ef6cf1fbedd7f9.tar.gz:https://github.com/litespeedtech/lsquic/archive/3181911301b1aa4f54c1ed690901abc674ee08fb.tar.gz \
	mimalloc-4a1c4f1f45e31b88.tar.gz:https://github.com/oven-sh/mimalloc/archive/f15aecb94fc8096008bf87b90c53ed682026914a.tar.gz \
	picohttpparser-fad59b16ad4752cc.tar.gz:https://github.com/h2o/picohttpparser/archive/066d2b1e9ab820703db0837a7255d92d30f0c9f5.tar.gz \
	tinycc-2f1f629056328c7b.tar.gz:https://github.com/oven-sh/tinycc/archive/12882eee073cfe5c7621bcfadf679e1372d4537b.tar.gz \
	zlib-655c6ecdb6fc9cd5.tar.gz:https://github.com/zlib-ng/zlib-ng/archive/12731092979c6d07f42da27da673a9f6c7b13586.tar.gz \
	zstd-e010993a24072468.tar.gz:https://github.com/facebook/zstd/archive/f8745da6ff1ad1e7bab384bd1f9d742439278e99.tar.gz

DD=		${DISTDIR}/${DIST_SUBDIR}
BUN_CACHE_DIR=	${WRKDIR}/bun-cache
BUN_ZIG_DIR=	${WRKDIR}/oven-zig
BUN_BUILD_DIR=	${WRKSRC}/build/release

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.pre.mk>

.if empty(CPUTYPE)
_BUN_CPU_FLAGS=	--baseline=true
.else
_BUN_CPU_FLAGS=	--cpu=${CPUTYPE} --baseline=false
.endif

# do-fetch: download the standard distfiles, then build the 3 custom archives
# (node_modules, dep tarballs, cargo vendor) if they are not already cached.
# All files land in ${DD} so make checksum and poudriere can reuse them.
do-fetch:
	@${MKDIR} ${DD}
	# Fetch directly-downloadable distfiles (GH0 uses DEFAULT master site, no group suffix)
	@${SETENV} ${_DO_FETCH_ENV} ${_MASTER_SITES_ENV} dp_SITE_FLAVOR=MASTER \
		${SH} ${SCRIPTSDIR}/do-fetch.sh \
			${DISTNAME}${EXTRACT_SUFX} \
			${DISTFILES:M*\:ovenzig} \
			${DISTFILES:M*\:webkit} \
			${DISTFILES:M*\:nodejshdr} \
			${DISTFILES:M*\:simdutf_src} \
			${DISTFILES:M*\:bootstrap:N*node-modules-*:N*dep-tarballs-*:N*cargo-vendor-*}
	# Build bun-node-modules tarball (npm ci with vendored package-lock*.json).
	# Uses deterministic tar so the checksum is reproducible across builds.
	@if ! [ -f "${DD}/bun-node-modules-${DISTVERSION}.tar.gz" ]; then \
		${ECHO_CMD} "===> Building bun-node-modules-${DISTVERSION}.tar.gz" && \
		_NTmp=$$(mktemp -d /tmp/bun-nmod.XXXXXX) && \
		bsdtar xzf ${DD}/${DISTNAME}${EXTRACT_SUFX} -C $$_NTmp && \
		_NSrc=$$_NTmp/${WRKSRC:T} && \
		${SED} -i '' \
			's|"@types/bun": "workspace:\*"|"@types/bun": "file:packages/@types/bun"|' \
			$$_NSrc/package.json && \
		${SED} -i '' \
			's|"bun-types": "workspace:"|"bun-types": "file:../bun-types"|' \
			$$_NSrc/packages/@types/bun/package.json && \
		${CP} ${FILESDIR}/package-lock.json $$_NSrc/package-lock.json && \
		${CP} ${FILESDIR}/package-lock-bun-error.json \
			$$_NSrc/packages/bun-error/package-lock.json && \
		${CP} ${FILESDIR}/package-lock-node-fallbacks.json \
			$$_NSrc/src/node-fallbacks/package-lock.json && \
		(cd $$_NSrc && ${LOCALBASE}/bin/npm ci --ignore-scripts) && \
		(cd $$_NSrc/packages/bun-error && \
			${LOCALBASE}/bin/npm ci --ignore-scripts) && \
		(cd $$_NSrc/src/node-fallbacks && \
			${LOCALBASE}/bin/npm ci --ignore-scripts) && \
		${FIND} $$_NSrc/node_modules \
			$$_NSrc/packages/bun-error/node_modules \
			$$_NSrc/src/node-fallbacks/node_modules \
			-name '.package-lock.json' -delete && \
		${FIND} $$_NSrc/node_modules \
			$$_NSrc/packages/bun-error/node_modules \
			$$_NSrc/src/node-fallbacks/node_modules \
			-type d -name '@*' -empty -delete && \
		${FIND} $$_NSrc/node_modules \
			$$_NSrc/packages/bun-error/node_modules \
			$$_NSrc/src/node-fallbacks/node_modules \
			-exec ${TOUCH} -h -d 1970-01-01T00:00:00Z {} \; && \
		(cd $$_NSrc && \
		  ${FIND} node_modules packages/bun-error/node_modules \
			src/node-fallbacks/node_modules -print0 \
		  | ${SORT} -z \
		  | ${SETENV} -i ${TAR} czf ${DD}/bun-node-modules-${DISTVERSION}.tar.gz \
			--format=cpio --gid 0 --uid 0 --options gzip:!timestamp \
			--no-recursion --null -T -) && \
		${RM} -rf $$_NTmp; \
	fi
	# Build bun-dep-tarballs + bun-cargo-vendor-lolhtml tarballs.
	# Uses deterministic tar so checksums are reproducible across builds.
	@if ! [ -f "${DD}/bun-dep-tarballs-${DISTVERSION}.tar.gz" ] || \
		! [ -f "${DD}/bun-cargo-vendor-lolhtml-${DISTVERSION}.tar.gz" ]; then \
		${ECHO_CMD} "===> Downloading bun dep tarballs" && \
		_DTmp=$$(mktemp -d /tmp/bun-dtp.XXXXXX) && \
		${MKDIR} $$_DTmp/tarballs && \
		for _tu in ${_BUN_DEP_TARBALLS}; do \
			_tc=$${_tu%%:*}; _url=$${_tu#*:}; \
			if ! [ -f "$$_DTmp/tarballs/$$_tc" ]; then \
				${FETCH_CMD} ${FETCH_BEFORE_ARGS} $$_url ${FETCH_AFTER_ARGS} \
					-o $$_DTmp/tarballs/$$_tc || exit 1; \
			fi; \
		done && \
		if ! [ -f "${DD}/bun-dep-tarballs-${DISTVERSION}.tar.gz" ]; then \
			${ECHO_CMD} "===> Packaging bun-dep-tarballs-${DISTVERSION}.tar.gz" && \
			( cd $$_DTmp && \
			  ${FIND} tarballs -exec ${TOUCH} -h -d 1970-01-01T00:00:00Z {} \; && \
			  ${FIND} tarballs -print0 \
			  | ${SORT} -z \
			  | ${SETENV} -i ${TAR} czf ${DD}/bun-dep-tarballs-${DISTVERSION}.tar.gz \
				--format=cpio --gid 0 --uid 0 --options gzip:!timestamp \
				--no-recursion --null -T - ); \
		fi && \
		if ! [ -f "${DD}/bun-cargo-vendor-lolhtml-${DISTVERSION}.tar.gz" ]; then \
			${ECHO_CMD} "===> Vendoring lolhtml Rust crates" && \
			_LTmp=$$(mktemp -d /tmp/bun-lol.XXXXXX) && \
			bsdtar xzf $$_DTmp/tarballs/lolhtml-929339b1d898e66b.tar.gz \
				-C $$_LTmp --strip-components 1 && \
			(cd $$_LTmp/c-api && \
				${SETENV} HOME=$$_LTmp \
				${LOCALBASE}/bin/cargo vendor vendor) && \
			${FIND} $$_LTmp/c-api/vendor -exec ${TOUCH} -h -d 1970-01-01T00:00:00Z {} \; && \
			( cd $$_LTmp/c-api && \
			  ${FIND} vendor -print0 \
			  | ${SORT} -z \
			  | ${SETENV} -i ${TAR} czf ${DD}/bun-cargo-vendor-lolhtml-${DISTVERSION}.tar.gz \
				--format=cpio --gid 0 --uid 0 --options gzip:!timestamp \
				--no-recursion --null -T - ) && \
			${RM} -rf $$_LTmp; \
		fi && \
		${RM} -rf $$_DTmp; \
	fi

post-extract:
	# Set up bun cache directory structure
	@${MKDIR} ${BUN_CACHE_DIR}/tarballs
	# Extract oven-sh/zig fork (Linux binary, via linux compat)
	@${MKDIR} ${BUN_ZIG_DIR}
	@cd ${BUN_ZIG_DIR} && bsdtar -xf ${DD}/bootstrap-x86_64-linux-musl.zip
	@${CHMOD} +x ${BUN_ZIG_DIR}/bootstrap-x86_64-linux-musl/zig
	# Install pre-built native FreeBSD bun bootstrap binary
	@${MKDIR} ${WRKDIR}/bun-bootstrap
	@${CP} ${DD}/bun-1.3.13-93-bootstrap ${WRKDIR}/bun-bootstrap/bun
	@${CHMOD} +x ${WRKDIR}/bun-bootstrap/bun
	# Extract WebKit prebuilt into cache
	@${MKDIR} ${BUN_CACHE_DIR}/webkit-${WEBKIT_SHORT}-freebsd
	@tar xzf ${DD}/bun-webkit-freebsd-amd64.tar.gz \
		-C ${BUN_CACHE_DIR}/webkit-${WEBKIT_SHORT}-freebsd \
		--strip-components 1
	@${ECHO_CMD} "${WEBKIT_VERSION}" > \
		${BUN_CACHE_DIR}/webkit-${WEBKIT_SHORT}-freebsd/.identity
	# Extract dep tarballs into cache
	@tar xzf ${DD}/bun-dep-tarballs-${DISTVERSION}.tar.gz \
		-C ${BUN_CACHE_DIR}
	# Extract vendored Rust crates for lolhtml
	@${MKDIR} ${WRKDIR}/cargo-vendor-lolhtml
	@tar xzf ${DD}/bun-cargo-vendor-lolhtml-${DISTVERSION}.tar.gz \
		-C ${WRKDIR}/cargo-vendor-lolhtml
	# Configure cargo to use vendored sources (via CARGO_HOME config)
	@${MKDIR} ${WRKDIR}/.cargo
	@${PRINTF} '[source.crates-io]\nreplace-with = "vendored-sources"\n\n[source.vendored-sources]\ndirectory = "%s/vendor"\n' \
		${WRKDIR}/cargo-vendor-lolhtml > ${WRKDIR}/.cargo/config.toml
	# Extract nodejs headers into bun cache and remove dirs bun doesn't need
	@${MKDIR} ${BUN_CACHE_DIR}/nodejs-headers-${NODE_VERSION}
	@tar xzf ${DD}/node-v${NODE_VERSION}-headers.tar.gz \
		-C ${BUN_CACHE_DIR}/nodejs-headers-${NODE_VERSION} \
		--strip-components 1
	@${RM} -rf \
		${BUN_CACHE_DIR}/nodejs-headers-${NODE_VERSION}/include/node/openssl \
		${BUN_CACHE_DIR}/nodejs-headers-${NODE_VERSION}/include/node/uv \
		${BUN_CACHE_DIR}/nodejs-headers-${NODE_VERSION}/include/node/uv.h
	@${ECHO_CMD} "${NODE_VERSION}" > \
		${BUN_CACHE_DIR}/nodejs-headers-${NODE_VERSION}/.identity
	# Extract node_modules into WRKSRC
	@tar xzf ${DD}/bun-node-modules-${DISTVERSION}.tar.gz \
		-C ${WRKSRC}
.if empty(CPUTYPE)
	# Baseline build: rebuild SIMDUTF.cpp.o from simdutf ${SIMDUTF_VERSION} without
	# the icelake (AVX-512) and haswell (AVX2) runtime-dispatch targets.  The
	# pre-built FreeBSD WebKit lacks a "-baseline" variant (unlike Linux/Windows),
	# so its libWTF.a SIMDUTF.cpp.o contains AVX-512 icelake dispatch code that
	# would otherwise appear in the final binary.
	@${ECHO_CMD} "===> Rebuilding SIMDUTF.cpp.o for baseline (no icelake/haswell)"
	@_SDTmp=$$(mktemp -d /tmp/bun-simdutf.XXXXXX) && \
	bsdtar xzf ${DD}/simdutf-simdutf-v${SIMDUTF_VERSION}_GH0.tar.gz \
		-C $$_SDTmp --strip-components 1 && \
	${LOCALBASE}/llvm${LLVM_VER}/bin/clang++ \
		-std=c++17 -march=nehalem -O2 \
		-ffunction-sections -fdata-sections \
		-fno-exceptions -fno-rtti \
		-DSIMDUTF_IMPLEMENTATION_ICELAKE=0 \
		-DSIMDUTF_IMPLEMENTATION_HASWELL=0 \
		-I$$_SDTmp/include -I$$_SDTmp/src \
		-c $$_SDTmp/src/simdutf.cpp \
		-o $$_SDTmp/SIMDUTF.cpp.o && \
	${LOCALBASE}/llvm${LLVM_VER}/bin/llvm-ar d \
		${BUN_CACHE_DIR}/webkit-${WEBKIT_SHORT}-freebsd/lib/libWTF.a \
		SIMDUTF.cpp.o && \
	${LOCALBASE}/llvm${LLVM_VER}/bin/llvm-ar r \
		${BUN_CACHE_DIR}/webkit-${WEBKIT_SHORT}-freebsd/lib/libWTF.a \
		$$_SDTmp/SIMDUTF.cpp.o && \
	${RM} -rf $$_SDTmp
.endif

post-patch:
	# Install FreeBSD-specific bun-internal patches applied by bun's build
	# system (fetchDep) when it extracts each vendor tarball from cache.
	# These disable AVX2/AVX/AVX-512 code paths that would otherwise appear
	# in the ELF binary even with -march=x86-64.
	@${MKDIR} ${WRKSRC}/patches/libdeflate
	@${CP} ${FILESDIR}/bun-libdeflate-adler32-disable-avx2.patch \
		${WRKSRC}/patches/libdeflate/adler32-disable-avx2.patch
	@${CP} ${FILESDIR}/bun-libdeflate-crc32-disable-avx.patch \
		${WRKSRC}/patches/libdeflate/crc32-disable-avx.patch
	@${MKDIR} ${WRKSRC}/patches/boringssl
	@${CP} ${FILESDIR}/bun-boringssl-disable-avx512-gcm.patch \
		${WRKSRC}/patches/boringssl/disable-avx512-gcm.patch

do-build:
	@cd ${WRKSRC} && \
		${SETENV} PATH=${LOCALBASE}/llvm${LLVM_VER}/bin:${LOCALBASE}/bin:/usr/bin:/bin \
		BUN_ZIG_PATH=${BUN_ZIG_DIR}/bootstrap-x86_64-linux-musl \
		BUN_HOST_OS=freebsd \
		FREEBSD_SYSROOT=/ \
		CARGO_HOME=${WRKDIR}/.cargo \
		GIT_SHA=${DISTVERSIONSUFFIX:S/-g//} \
		${WRKDIR}/bun-bootstrap/bun scripts/build.ts \
			--os=freebsd \
			--cacheDir=${BUN_CACHE_DIR} \
			--buildDir=${BUN_BUILD_DIR} \
			--profile=release \
			-j${MAKE_JOBS_NUMBER} \
			${_BUN_CPU_FLAGS}

do-install:
	${INSTALL_PROGRAM} ${BUN_BUILD_DIR}/bun ${STAGEDIR}${PREFIX}/bin/

do-test:
	@${ECHO_CMD} "==> Running Bun version check..."
	${STAGEDIR}${PREFIX}/bin/bun --version
	@${ECHO_CMD} "==> Installing test dependencies..."
	cd ${WRKSRC}/test && ${STAGEDIR}${PREFIX}/bin/bun install \
		--frozen-lockfile --ignore-scripts
	@${ECHO_CMD} "==> Running Bun regression tests..."
	cd ${WRKSRC} && ${STAGEDIR}${PREFIX}/bin/bun test --timeout 120000 --parallel 1

.include <bsd.port.post.mk>
