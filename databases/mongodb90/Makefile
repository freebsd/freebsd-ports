PORTNAME=	mongodb
DISTVERSIONPREFIX=	r
DISTVERSION=	9.0.0-alpha1
PORTREVISION=	2
CATEGORIES=	databases net
MASTER_SITES+=	https://github.com/WebAssembly/wasi-sdk/releases/download/wasi-sdk-${WASI_SDK_VERSION:R}/:wasi_sdk \
		https://codeload.github.com/bazelbuild/bazel-central-registry/tar.gz/${BAZEL_REGISTRY_COMMIT}?dummy=/:bazel_registry \
		https://codeload.github.com/mongodb-forks/rules_poetry/tar.gz/${RULES_POETRY_COMMIT}?dummy=/:rules_poetry
PKGNAMESUFFIX=	${DISTVERSION:R:S/.//}
BAZEL_REGISTRY_DISTFILE=	bazelbuild-bazel-central-registry-${BAZEL_REGISTRY_COMMIT}_GH0.tar.gz
RULES_POETRY_DISTFILE=	mongodb-forks-rules_poetry-${RULES_POETRY_COMMIT}_GH0.tar.gz
# The wasm32-wasip2 sysroot and compiler-rt builtins of wasi-sdk, see
# post-extract and the wasi_repo.bzl patch. The version comes from
# ${WRKSRC}/bazel/toolchains/cc/mongo_wasm/toolchain/wasi_repo.bzl.
WASI_SDK_VERSION=	33.0
WASI_SYSROOT_DISTFILE=	wasi-sysroot-${WASI_SDK_VERSION}+m.tar.gz
WASI_LIBCLANG_RT_DISTFILE=	libclang_rt-${WASI_SDK_VERSION}+m.tar.gz
DISTFILES+=	${BAZEL_REGISTRY_DISTFILE}:bazel_registry \
		${RULES_POETRY_DISTFILE}:rules_poetry \
		${WASI_SYSROOT_DISTFILE}:wasi_sdk \
		${WASI_LIBCLANG_RT_DISTFILE}:wasi_sdk

# Archives downloaded by Bazel as "group site distfile". They are added to the
# Bazel repository cache in post-extract instead of being extracted. Most are
# Bazel modules: the bazel-central-registry has their URLs in
# modules/<name>/<version>/source.json. To find the full list after an update,
# build once with an empty repository cache without --repository_disable_download.
BAZEL_DISTFILES=	\
	apple_support https://github.com/bazelbuild/apple_support/releases/download/1.24.1/ apple_support.1.24.1.tar.gz \
	aspect_bazel_lib https://github.com/bazel-contrib/bazel-lib/releases/download/v2.13.0/ bazel-lib-v2.13.0.tar.gz \
	aspect_rules_js https://github.com/aspect-build/rules_js/releases/download/v2.1.3/ rules_js-v2.1.3.tar.gz \
	bats_core https://github.com/bats-core/bats-core/archive/v1.10.0.tar.gz?dummy=/ bats-core-1.10.0.tar.gz \
	bazel_clang_tidy https://github.com/mongodb-forks/bazel_clang_tidy/archive/refs/tags/v1.7.tar.gz?dummy=/ bazel_clang_tidy-1.7.tar.gz \
	bazel_features https://github.com/bazel-contrib/bazel_features/releases/download/v1.37.0/ bazel_features-v1.37.0.tar.gz \
	bazel_skylib https://github.com/bazelbuild/bazel-skylib/releases/download/1.9.0/ bazel-skylib-1.9.0.tar.gz \
	buildifier_prebuilt https://github.com/keith/buildifier-prebuilt/archive/refs/tags/6.4.0.tar.gz?dummy=/ buildifier-prebuilt-6.4.0.tar.gz \
	platforms https://github.com/bazelbuild/platforms/releases/download/0.0.11/ platforms-0.0.11.tar.gz \
	rules_cc https://github.com/bazelbuild/rules_cc/releases/download/0.2.10/ rules_cc-0.2.10.tar.gz \
	rules_foreign_cc https://github.com/bazel-contrib/rules_foreign_cc/releases/download/0.15.1/ rules_foreign_cc-0.15.1.tar.gz \
	rules_go https://github.com/bazelbuild/rules_go/releases/download/v0.50.1/ rules_go-v0.50.1.zip \
	rules_java https://github.com/bazelbuild/rules_java/releases/download/8.6.1/ rules_java-8.6.1.tar.gz \
	rules_kotlin https://github.com/bazelbuild/rules_kotlin/releases/download/v1.9.6/ rules_kotlin-v1.9.6.tar.gz \
	rules_license https://github.com/bazelbuild/rules_license/releases/download/1.0.0/ rules_license-1.0.0.tar.gz \
	rules_multitool https://github.com/theoremlp/rules_multitool/releases/download/v0.4.0/ rules_multitool-0.4.0.tar.gz \
	rules_nodejs https://github.com/bazel-contrib/rules_nodejs/releases/download/v6.3.0/ rules_nodejs-v6.3.0.tar.gz \
	rules_perl https://github.com/bazel-contrib/rules_perl/archive/refs/tags/0.2.4.tar.gz?dummy=/ rules_perl-0.2.4.tar.gz \
	rules_pkg https://github.com/bazelbuild/rules_pkg/releases/download/1.2.0/ rules_pkg-1.2.0.tar.gz \
	rules_proto https://github.com/bazelbuild/rules_proto/releases/download/7.1.0/ rules_proto-7.1.0.tar.gz \
	rules_python https://github.com/bazel-contrib/rules_python/releases/download/1.8.5/ rules_python-1.8.5.tar.gz \
	rules_rust https://github.com/bazelbuild/rules_rust/releases/download/0.69.0/ rules_rust-0.69.0.tar.gz \
	rules_shell https://github.com/bazelbuild/rules_shell/releases/download/v0.6.1/ rules_shell-v0.6.1.tar.gz \
	spidermonkey_wasi https://mdb-build-public.s3.amazonaws.com/spidermonkey-wasm/FIREFOX_140_12_0esr_RELEASE/spidermonkey-wasip2-release.tar.gz?dummy=/ spidermonkey-wasip2-release-FIREFOX_140_12_0esr_RELEASE.tar.gz
# npm packages downloaded by rules_js, see ${WRKSRC}/pnpm-lock.yaml.
BAZEL_NPM_DISTFILES=	\
	npm_eslint https://registry.npmjs.org/eslint/-/ eslint-9.19.0.tgz \
	npm_prettier https://registry.npmjs.org/prettier/-/ prettier-3.4.2.tgz

.for group site distfile in ${BAZEL_DISTFILES} ${BAZEL_NPM_DISTFILES}
MASTER_SITES+=	${site}:${group}
DISTFILES+=	${distfile}:${group}
_BAZEL_NOEXTRACT+=	N${distfile}
.endfor
.for group site distfile in ${BAZEL_DISTFILES}
_BAZEL_CACHE_ARGS+=	${_DISTDIR}/${distfile}
.endfor
.for group site distfile in ${BAZEL_NPM_DISTFILES}
_BAZEL_CACHE_ARGS+=	--npm ${_DISTDIR}/${distfile} ${site}${distfile}
.endfor

MAINTAINER=	ronald@FreeBSD.org
COMMENT=	MongoDB Community Edition (9.0.x Branch)
WWW=		https://www.mongodb.com/docs/v9.0/

LICENSE=	APACHE20 SSPLv1 # mongodb is SSPLv1, C++ driver is APACHE20
LICENSE_COMB=	multi
LICENSE_NAME_SSPLv1=	Server Side Public License Version 1
LICENSE_FILE_SSPLv1=	${WRKSRC}/LICENSE-Community.txt
LICENSE_PERMS_SSPLv1=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

ONLY_FOR_ARCHS=	aarch64 amd64 powerpc64le
ONLY_FOR_ARCHS_REASON=	only ported to amd64, aarch64, and powerpc64le on FreeBSD; upstream supports arm64, ppc64le, s390x, and x86-64

BUILD_DEPENDS=	bazel:devel/bazel7 \
		bash:shells/bash \
		rg:textproc/ripgrep \
		${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}cheetah3>0:devel/py-cheetah3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}distro>0:sysutils/py-distro@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gitpython>0:devel/py-gitpython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pymongo>0:databases/py-pymongo@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=3.11:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}retry2>0:devel/py-retry2@${PY_FLAVOR} \
		rust-cbindgen>0:devel/rust-cbindgen \
		yq:textproc/go-yq
# build depends used while running ${WRKSRC}/src/third_party/mozjs/scripts/gen-config.sh
BUILD_DEPENDS+=	gm4:devel/m4 \
		gsed:textproc/gsed
LIB_DEPENDS=	libcurl.so:ftp/curl

FLAVORS=	default armv80a

armv80a_PKGNAMESUFFIX=	${DISTVERSION:R:S/.//}-armv80a

# gmake is used while running ${WRKSRC}/src/third_party/mozjs/scripts/gen-config.sh
USES=		cargo compiler:c++20-lang cpe gmake pkgconfig python:build \
		shebangfix ssl
CPE_PRODUCT=	mongodb

# mozjs tag comes from ${WRKSRC}/src/third_party/mozjs/scripts/import.sh
MOZJS_TAG=	7aeaf7a44d420360bde75db8453636092c3e2f56
BAZEL_REGISTRY_COMMIT=	5df17720d4367282afb8e5ca27a35199ab7620e4
RULES_POETRY_COMMIT=	092d43107d13e711ac4ac92050d8b570bcc8ef43

USE_GITHUB=	yes
GH_ACCOUNT=	mongodb mongodb-forks:mozjs
GH_PROJECT=	mongo spidermonkey:mozjs
GH_TAGNAME=	${MOZJS_TAG}:mozjs
USE_RC_SUBR=	mongod

SHEBANG_FILES=	src/third_party/mozjs/scripts/gen-config.sh

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	scripts/gen-config.sh
CONFIGURE_ARGS=		${MOZJS_ARCH} \
			freebsd
CONFIGURE_ENV+=		PYTHON3="${PYTHON_CMD}"

# The crates in Makefile.crates are used by rules_rust from the Bazel
# repository cache and by cargo while bootstrapping cargo-bazel, see
# post-extract. rules_rust uses lang/rust instead of downloading a Rust
# toolchain, see the freebsd_local_toolchain.patch.
CARGO_BUILD=		no
CARGO_CONFIGURE=	no
CARGO_INSTALL=		no
CARGO_TEST=		no
CARGO_CARGOLOCK=	${WRKSRC}/bazel/crates.toml
CARGO_VENDOR_DIR=	${WRKDIR}/cargo-crates
RULES_RUST_VERSION=	0.69.0
RULES_RUST_WRKSRC=	${WRKDIR}/rules_rust-${RULES_RUST_VERSION}

BAZEL=			${LOCALBASE}/bin/bazel
BAZEL_OUTPUT_USER_ROOT=	${WRKDIR}/bazel
BAZEL_REPOSITORY_CACHE=${WRKDIR}/bazel-repository-cache
BAZEL_STARTUP_ARGS=	--batch \
			--output_user_root=${BAZEL_OUTPUT_USER_ROOT}
BAZEL_ENV=		BAZEL_SH=${LOCALBASE}/bin/bash \
			CARGO_NET_OFFLINE=true \
			CC="${CC}" \
			CXX="${CXX}" \
			HOME=${WRKDIR} \
			MONGO_USE_SYSTEM_PYTHON=1 \
			PYTHON_CMD=${PYTHON_CMD} \
			TMPDIR=${WRKDIR}
BAZEL_ARGS=		--repository_cache=${BAZEL_REPOSITORY_CACHE} \
			--distdir=${DISTDIR} \
			--registry=file://${BAZEL_REGISTRY_WRKSRC} \
			--repository_disable_download \
			--lockfile_mode=off \
			--//bazel/config:running_through_bazelisk=True \
			--config=local \
			--config=opt \
			--verbose_failures \
			--jobs=${MAKE_JOBS_NUMBER} \
			--action_env=AR=llvm-ar \
			--action_env=CC=${CC} \
			--action_env=CXX=${CXX} \
			--repo_env=BAZEL_HTTP_RULES_URLS_AS_DEFAULT_CANONICAL_ID=0 \
			--repo_env=CARGO_BAZEL_SKIP_DIGEST_CHECK=1 \
			--repo_env=CC=${CC} \
			--repo_env=CXX=${CXX} \
			--repo_env=LOCALBASE=${LOCALBASE} \
			--repo_env=MONGO_USE_SYSTEM_PYTHON=1 \
			--repo_env=PYTHON_CMD=${PYTHON_CMD} \
			--repo_env=RULES_RUST_LOCAL_TOOLCHAIN=${LOCALBASE} \
			--repo_env=WASI_SDK_DIR=${WASI_SDK_WRKSRC} \
			--build_enterprise=False \
			--enterprise_feature_all=False \
			--allocator=system \
			--libunwind=off \
			--ssl=True \
			--disable_warnings_as_errors=True \
			--create_dwp=False \
			--copt=-isystem${LOCALBASE}/include \
			--define=GIT_COMMIT_HASH=freebsd-${PORTVERSION} \
			--define=MONGO_DISTMOD=freebsd \
			--define=MONGO_VERSION=${DISTVERSION} \
			--cxxopt=-isystem${LOCALBASE}/include \
			--cxxopt=-Iexternal/abseil-cpp~ \
			--cxxopt=-DBOOST_NO_CXX98_FUNCTION_BASE \
			--cxxopt=-Wno-unused-function \
			--cxxopt=-Wno-invalid-offsetof \
			--cxxopt=-Wno-defaulted-function-deleted \
			--cxxopt=-Wno-unknown-warning-option \
			--cxxopt=-Wno-macro-redefined \
			--cxxopt=-Wno-register \
			--linkopt=-L${LOCALBASE}/lib \
			--linkopt=-lm \
			--linkopt=-lcrypto \
			--linkopt=-pthread \
			--linkopt=-lexecinfo \
			--linkopt=-lkvm \
			--noexperimental_collect_system_network_usage
ALL_TARGET=		install-core

CONFLICTS_INSTALL=	mongodb[0-9][0-9]

BINARY_ALIAS=	python3=${PYTHON_CMD}
EXTRACT_AFTER_ARGS=	--no-same-owner --no-same-permissions
EXTRACT_ONLY=	${_DISTFILES:N${WASI_SYSROOT_DISTFILE}:N${WASI_LIBCLANG_RT_DISTFILE}:${_BAZEL_NOEXTRACT:ts:}}

# This ports is only following the Major Release.
# https://docs.mongodb.com/manual/reference/versioning/
PORTSCOUT=	limit:^9\.0\.

CONFIGURE_WRKSRC=	${MOZJS_WRKSRC}

USERS=		mongodb
GROUPS=		mongodb

OPTIONS_DEFINE=		LTO NOAVX
OPTIONS_DEFINE_aarch64=	ARMV80A
OPTIONS_DEFAULT=	NOAVX

# MongoDB on non-LSE ARM cpu like Raspberry Pi can work but is unsupported upstream.
# Can give corruption on high concurrency.
# Please read https://jira.mongodb.org/browse/SERVER-71772.
ARMV80A_DESC=	Enable non-LSE ARM64 CPUs like RPI4.
NOAVX_DESC=	"Disable AVX instructions on amd64 (Sandybridge+)"

ARMV80A_VARS=	BAZEL_ARGS+="--copt=-march=armv8-a --cxxopt=-march=armv8-a"

LTO_VARS=	BAZEL_ARGS+=--thin_lto=True

NOAVX_EXTRA_PATCHES=	${FILESDIR}/extrapatch-src_third__party_mozjs_extract_mozglue_misc_SIMD.cpp

MOZJS_WRKSRC=	${WRKSRC}/src/third_party/mozjs
WASI_SDK_WRKSRC=	${WRKDIR}/wasi-sdk
BAZEL_REGISTRY_WRKSRC=	${WRKDIR}/bazel-central-registry-${BAZEL_REGISTRY_COMMIT}
RULES_POETRY_WRKSRC=	${WRKDIR}/rules_poetry-${RULES_POETRY_COMMIT}
BAZEL_INSTALL_WRKSRC=	${WRKSRC}/bazel-bin/${ALL_TARGET}

.if ${FLAVOR:U} == armv80a
OPTIONS_SET+=	ARMV80A
.endif

.include <bsd.port.pre.mk>

.if ${FLAVOR:U} == armv80a && ${ARCH} != aarch64
IGNORE=		flavor armv80a is only valid on aarch64
.endif

.if ${ARCH} == amd64
MOZJS_ARCH=	x86_64
.elif ${ARCH} == powerpc64le
MOZJS_ARCH=	ppc64le
.elif ${ARCH} == aarch64
MOZJS_ARCH=	${ARCH}
.endif

# The default wasm JS engine embeds wasmtime, which needs a Rust toolchain.
# Use the legacy native mozjs engine there, like upstream does on ppc64le.
.if ${ARCH} == aarch64
BAZEL_ARGS+=	--//bazel/config:js_engine=mozjs
.else
# clang22 compiles the mozjs wasm module, see the wasi_repo.bzl patch
BUILD_DEPENDS+=	clang22:devel/llvm22@lite
.endif

post-extract:
# Verify we downloaded the proper mozjs git tag.
	${SH} -xc "test \"X`grep -E '^LIB_GIT_REVISION=' ${MOZJS_WRKSRC}/scripts/import.sh`\" = \"XLIB_GIT_REVISION=${MOZJS_TAG}\""

post-patch:
	${PATCH} -d ${RULES_POETRY_WRKSRC} -p0 < ${WRKSRC}/bazel/rules_poetry/rules_poetry.patch

pre-configure:
# Replacement of ${WRKSRC}/src/third_party/mozjs/scripts/import.sh
	${LN} -sF ${WRKDIR}/spidermonkey-${MOZJS_TAG} ${MOZJS_WRKSRC}/mozilla-release
	${PYTHON_CMD} ${WRKSRC}/bazel/resmoke/derive_suite_selectors.py
	cd ${WRKSRC} && ${PYTHON_CMD} -c 'from pathlib import Path; from bazel.auto_header.gen_all_headers import spawn_all_headers_thread; th, state = spawn_all_headers_thread(Path(".")); th.join(); assert state["ok"], state["err"]; print("Generated all_headers (%s)" % ("wrote" if state["wrote"] else "unchanged"))'
	cd ${WRKSRC} && ${SETENV} RG_PATH=${LOCALBASE}/bin/rg ${PYTHON_CMD} -c 'from pathlib import Path; from bazel.auto_header.auto_header import gen_auto_headers; state = gen_auto_headers(Path(".")); assert state["ok"], state["err"]; print("Generated auto_headers (%s wrote, %s skipped)" % (state["wrote"], state["skipped"]))'
# Bazel finds the files it downloads in its repository cache by sha256, which
# is also the checksum of a crate in Cargo.lock and of a module in its
# source.json. BAZEL_HTTP_RULES_URLS_AS_DEFAULT_CANONICAL_ID=0 makes Bazel
# find them without the id- files of the download URLs. With downloads
# disabled, Bazel also reads the files of the file:// registry from the cache.
	${PYTHON_CMD} ${FILESDIR}/bazel-cache-add.py ${BAZEL_REPOSITORY_CACHE} \
		${CARGO_CRATES:S|^|${_DISTDIR}/${CARGO_DIST_SUBDIR}/|:S|$|${CARGO_CRATE_EXT}|} \
		${BAZEL_REGISTRY_WRKSRC} ${_BAZEL_CACHE_ARGS}
# Assemble the parts of the wasi-sdk used with the native clang22: the
# wasm32-wasip2 sysroot with exceptions, the compiler-rt builtins and the clang
# resource headers.
	${MKDIR} ${WASI_SDK_WRKSRC}/share/wasi-sysroot ${WASI_SDK_WRKSRC}/lib/clang/22/lib
	${TAR} -xf ${_DISTDIR}/${WASI_SYSROOT_DISTFILE} -C ${WASI_SDK_WRKSRC}/share/wasi-sysroot \
		--strip-components 1 --exclude llvm-lto --exclude noeh \
		${WASI_SYSROOT_DISTFILE:S/.tar.gz$//:S|$|/include/c++|} \
		${WASI_SYSROOT_DISTFILE:S/.tar.gz$//:S|$|/include/wasm32-wasip2|} \
		${WASI_SYSROOT_DISTFILE:S/.tar.gz$//:S|$|/lib/wasm32-wasip2|} \
		${WASI_SYSROOT_DISTFILE:S/.tar.gz$//:S|$|/share|}
	${TAR} -xf ${_DISTDIR}/${WASI_LIBCLANG_RT_DISTFILE} -C ${WASI_SDK_WRKSRC}/lib/clang/22/lib \
		--strip-components 1 ${WASI_LIBCLANG_RT_DISTFILE:S/.tar.gz$//:S|$|/wasm32-unknown-wasip2|}
	${LN} -s ${LOCALBASE}/llvm22/lib/clang/22/include ${WASI_SDK_WRKSRC}/lib/clang/22/include
# cargo-bazel is bootstrapped with cargo using HOME=${WRKDIR}.
	${MKDIR} ${WRKDIR}/.cargo
	${PRINTF} "[source.cargo]\ndirectory = '%s'\n[source.crates-io]\nreplace-with = 'cargo'\n" \
		${CARGO_VENDOR_DIR} > ${WRKDIR}/.cargo/config.toml

do-build:
	${MKDIR} ${BAZEL_REPOSITORY_CACHE}
	cd ${WRKSRC} && ${SETENV} ${BAZEL_ENV} ${BAZEL} ${BAZEL_STARTUP_ARGS} build ${BAZEL_ARGS} ${ALL_TARGET}

do-install:
	${INSTALL_PROGRAM} ${BAZEL_INSTALL_WRKSRC}/bin/mongod ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_PROGRAM} ${BAZEL_INSTALL_WRKSRC}/bin/mongos ${STAGEDIR}${PREFIX}/bin/
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/mongod
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/mongos
	${INSTALL_DATA} ${WRKSRC}/rpm/mongod.conf ${STAGEDIR}${PREFIX}/etc/mongodb.conf.sample
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in LICENSE-Community.txt distsrc/MPL-2 distsrc/README distsrc/THIRD-PARTY-NOTICES
	${INSTALL_DATA} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}/
.endfor
	${INSTALL_MAN} ${WRKSRC}/debian/mongod.1 ${STAGEDIR}${PREFIX}/share/man/man1/
	${INSTALL_MAN} ${WRKSRC}/debian/mongos.1 ${STAGEDIR}${PREFIX}/share/man/man1/
	${INSTALL_MAN} ${WRKSRC}/debian/mongodb-parameters.5 ${STAGEDIR}${PREFIX}/share/man/man5/

do-test:
	${SH} ${FILESDIR}/make.test.sh "${STAGEDIR}${PREFIX}/bin"

# The FreeBSD entries in files/patch-bazel_crates.lock and
# files/patch-bazel_cargo__bindeps.lock come from a repin: run bazel cquery
# with --repo_env=CARGO_BAZEL_REPIN=1, CARGO_BAZEL_REPIN_ONLY=crates (or
# cargo_bindeps) and CARGO_NET_OFFLINE=false, after cargo-bazel has been
# bootstrapped and with ${WRKDIR}/.cargo/config.toml moved away. The
# cargo_bindeps repin needs a cargo that reports a -nightly version (a wrapper
# script setting RUSTC_BOOTSTRAP=1) in RULES_RUST_LOCAL_TOOLCHAIN.

# Regenerate Makefile.crates with the crates used by mongodb (its Cargo.lock
# files) and by rules_rust: the cargo-bazel bootstrap (its Cargo.lock), the
# cargo tools (3rdparty/crates/defs.bzl) and tinyjson.
# Run "make makesum" afterwards.
make-crates: extract
	${MKDIR} ${RULES_RUST_WRKSRC}
	${TAR} -xf ${BAZEL_REPOSITORY_CACHE}/content_addressable/sha256/$$(${SED} -n \
		's/.*"integrity": "sha256-\(.*\)",/\1/p' \
		${BAZEL_REGISTRY_WRKSRC}/modules/rules_rust/${RULES_RUST_VERSION}/source.json | \
		b64decode -r | od -An -tx1 | ${TR} -d ' \n')/file \
		-C ${RULES_RUST_WRKSRC} cargo/3rdparty/crates/defs.bzl \
		crate_universe/Cargo.lock rust/private/repository_utils.bzl
	{ for f in ${WRKSRC}/bazel/crates.toml ${WRKSRC}/bazel/cargo_bindeps.toml \
		${RULES_RUST_WRKSRC}/crate_universe/Cargo.lock; do \
		${_CARGO_AWK} ${SCRIPTSDIR}/cargo-crates.awk $$f; \
	done; \
	${SED} -n 's|.*"https://static.crates.io/crates/\([^/]*\)/\([^/]*\)/download".*|\1-\2|p' \
		${RULES_RUST_WRKSRC}/cargo/3rdparty/crates/defs.bzl; \
	${SED} -n 's|.*static.crates.io/crates/tinyjson/\(tinyjson-.*\)\.crate.*|\1|p' \
		${RULES_RUST_WRKSRC}/rust/private/repository_utils.bzl; } | \
		${SED} -e 's/^CARGO_CRATES=//' -e 's/[[:space:]\\]//g' | ${GREP} -v '^$$' | ${SORT} -u | \
		${AWK} '{ c[n++] = $$0 } END { s = "CARGO_CRATES="; \
			for (i = 0; i < n; i++) { printf "%s\t%s%s\n", s, c[i], (i < n - 1 ? " \\" : ""); s = "\t" } }' \
		> ${MASTERDIR}/Makefile.crates

.include <bsd.port.post.mk>
