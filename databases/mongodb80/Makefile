PORTNAME=	mongodb
DISTVERSIONPREFIX=	r
DISTVERSION=	8.0.38
CATEGORIES=	databases net
MASTER_SITES+=	https://codeload.github.com/bazelbuild/bazel-central-registry/tar.gz/${BAZEL_REGISTRY_COMMIT}?dummy=/:bazel_registry \
		https://codeload.github.com/mongodb-forks/rules_poetry/tar.gz/${RULES_POETRY_COMMIT}?dummy=/:rules_poetry
PKGNAMESUFFIX=	${DISTVERSION:R:S/.//}
BAZEL_REGISTRY_DISTFILE=	bazelbuild-bazel-central-registry-${BAZEL_REGISTRY_COMMIT}_GH0.tar.gz
RULES_POETRY_DISTFILE=	mongodb-forks-rules_poetry-${RULES_POETRY_COMMIT}_GH0.tar.gz
DISTFILES+=	${BAZEL_REGISTRY_DISTFILE}:bazel_registry \
		${RULES_POETRY_DISTFILE}:rules_poetry

# Archives downloaded by Bazel as "group site distfile". They are added to the
# Bazel repository cache in pre-configure instead of being extracted. Most are
# Bazel modules: the bazel-central-registry has their URLs in
# modules/<name>/<version>/source.json. To regenerate the lists after an
# update, run "make -f Makefile.bazel-cache".
BAZEL_DISTFILES=	\
	apple_support https://github.com/bazelbuild/apple_support/releases/download/1.23.1/ apple_support.1.23.1.tar.gz \
	aspect_bazel_lib https://github.com/bazel-contrib/bazel-lib/releases/download/v2.13.0/ bazel-lib-v2.13.0.tar.gz \
	aspect_rules_js https://github.com/aspect-build/rules_js/releases/download/v2.1.3/ rules_js-v2.1.3.tar.gz \
	bats_core https://github.com/bats-core/bats-core/archive/v1.10.0.tar.gz?dummy=/ bats-core-1.10.0.tar.gz \
	bazel_clang_tidy https://github.com/mongodb-forks/bazel_clang_tidy/archive/33c9013349b6178897598e67929201356b0ad5ea.tar.gz?dummy=/ bazel_clang_tidy-33c9013349b6178897598e67929201356b0ad5ea.tar.gz \
	bazel_features https://github.com/bazel-contrib/bazel_features/releases/download/v1.37.0/ bazel_features-v1.37.0.tar.gz \
	bazel_skylib https://github.com/bazelbuild/bazel-skylib/releases/download/1.7.1/ bazel-skylib-1.7.1.tar.gz \
	buildifier_prebuilt https://github.com/keith/buildifier-prebuilt/archive/refs/tags/6.4.0.tar.gz?dummy=/ buildifier-prebuilt-6.4.0.tar.gz \
	platforms https://github.com/bazelbuild/platforms/releases/download/0.0.9/ platforms-0.0.9.tar.gz \
	protobuf https://github.com/protocolbuffers/protobuf/releases/download/v29.0-rc3/ protobuf-29.0-rc3.zip \
	rules_cc https://github.com/bazelbuild/rules_cc/releases/download/0.0.16/ rules_cc-0.0.16.tar.gz \
	rules_cc_0_0_9 https://github.com/bazelbuild/rules_cc/releases/download/0.0.9/ rules_cc-0.0.9.tar.gz \
	rules_java https://github.com/bazelbuild/rules_java/releases/download/8.5.1/ rules_java-8.5.1.tar.gz \
	rules_kotlin https://github.com/bazelbuild/rules_kotlin/releases/download/v1.9.6/ rules_kotlin-v1.9.6.tar.gz \
	rules_license https://github.com/bazelbuild/rules_license/releases/download/1.0.0/ rules_license-1.0.0.tar.gz \
	rules_multitool https://github.com/theoremlp/rules_multitool/releases/download/v0.4.0/ rules_multitool-0.4.0.tar.gz \
	rules_nodejs https://github.com/bazel-contrib/rules_nodejs/releases/download/v6.3.0/ rules_nodejs-v6.3.0.tar.gz \
	rules_pkg https://github.com/bazelbuild/rules_pkg/releases/download/1.2.0/ rules_pkg-1.2.0.tar.gz \
	rules_proto https://github.com/bazelbuild/rules_proto/archive/refs/tags/5.3.0-21.7.tar.gz?dummy=/ rules_proto-5.3.0-21.7.tar.gz \
	rules_python https://github.com/bazelbuild/rules_python/releases/download/1.0.0/ rules_python-1.0.0.tar.gz \
	rules_shell https://github.com/bazelbuild/rules_shell/releases/download/v0.2.0/ rules_shell-v0.2.0.tar.gz
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
COMMENT=	MongoDB Community Edition (8.0.x Branch)
WWW=		https://www.mongodb.com/docs/v8.0/

LICENSE=	APACHE20 SSPLv1 # mongodb is SSPLv1, C++ driver is APACHE20
LICENSE_COMB=	multi
LICENSE_NAME_SSPLv1=	Server Side Public License Version 1
LICENSE_FILE_SSPLv1=	${WRKSRC}/LICENSE-Community.txt
LICENSE_PERMS_SSPLv1=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

ONLY_FOR_ARCHS=	aarch64 amd64 powerpc64le
ONLY_FOR_ARCHS_REASON=	only ported to amd64, aarch64, and powerpc64le on FreeBSD; upstream supports arm64, ppc64le, s390x, and x86-64

BUILD_DEPENDS=	bazel:devel/bazel7 \
		bash:shells/bash \
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
USES=		compiler:c++20-lang cpe gmake pkgconfig python:build shebangfix ssl
CPE_PRODUCT=	mongodb

# mozjs tag comes from ${WRKSRC}/src/third_party/mozjs/scripts/import.sh
MOZJS_TAG=	7aeaf7a44d420360bde75db8453636092c3e2f56
BAZEL_REGISTRY_COMMIT=	5df17720d4367282afb8e5ca27a35199ab7620e4
RULES_POETRY_COMMIT=	917630033c736c188605cf0f558c34afc1eca540

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

BAZEL=			${LOCALBASE}/bin/bazel
BAZEL_OUTPUT_USER_ROOT=	${WRKDIR}/bazel
BAZEL_REPOSITORY_CACHE=${WRKDIR}/bazel-repository-cache
# --batch: run the build in the bazel JVM directly instead of through the
# client/server pair. The client's "is the server's cwd still my workspace"
# check (GetProcessCWD() in blaze_util_bsd.cc) returns an empty path instead
# of nullptr when the kernel cannot resolve the cwd, e.g. inside a poudriere
# jail, which makes the client kill and restart the server forever.
BAZEL_STARTUP_ARGS=	--batch \
			--output_user_root=${BAZEL_OUTPUT_USER_ROOT}
BAZEL_ENV=		BAZEL_SH=${LOCALBASE}/bin/bash \
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
			--repo_env=CC=${CC} \
			--repo_env=CXX=${CXX} \
			--repo_env=LOCALBASE=${LOCALBASE} \
			--repo_env=MONGO_USE_SYSTEM_PYTHON=1 \
			--repo_env=PYTHON_CMD=${PYTHON_CMD} \
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
			--cxxopt=-DBOOST_NO_CXX98_FUNCTION_BASE \
			--cxxopt=-Wno-unused-function \
			--cxxopt=-Wno-invalid-offsetof \
			--cxxopt=-Wno-defaulted-function-deleted \
			--cxxopt=-Wno-unknown-warning-option \
			--cxxopt=-Wno-macro-redefined \
			--linkopt=-L${LOCALBASE}/lib \
			--linkopt=-lm \
			--linkopt=-pthread \
			--linkopt=-lexecinfo \
			--linkopt=-lkvm \
			--noexperimental_collect_system_network_usage
# rules_java registers the @local_jdk toolchains, which Bazel loads even though
# the build does not use Java. Without JAVA_HOME, @local_jdk takes the java home
# from "which javac", which for the javavm wrapper is ${LOCALBASE}, and globs all
# of it. A JAVA_HOME without bin/java gives stub toolchains instead.
BAZEL_ARGS+=		--repo_env=JAVA_HOME=/nonexistent
ALL_TARGET=		install-dist

CONFLICTS_INSTALL=	mongodb[0-9][0-9]

BINARY_ALIAS=	python3=${PYTHON_CMD}
EXTRACT_AFTER_ARGS=	--no-same-owner --no-same-permissions
EXTRACT_ONLY=	${_DISTFILES:${_BAZEL_NOEXTRACT:ts:}}

# This ports is only following the Major Release.
# https://docs.mongodb.com/manual/reference/versioning/
PORTSCOUT=	limit:^8\.0\.

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

post-extract:
# Verify we downloaded the proper mozjs git tag.
	${SH} -xc "test \"X`grep -E '^LIB_GIT_REVISION=' ${MOZJS_WRKSRC}/scripts/import.sh`\" = \"XLIB_GIT_REVISION=${MOZJS_TAG}\""
	${PATCH} -d ${WRKDIR}/spidermonkey-${MOZJS_TAG} -p1 < ${PATCHDIR}/d497aa4f770ca02f6083e93b94996a8fe32c2ff4.patch

post-patch:
	${PATCH} -d ${RULES_POETRY_WRKSRC} -p0 < ${WRKSRC}/bazel/rules_poetry/rules_poetry.patch

pre-configure:
# Replacement of ${WRKSRC}/src/third_party/mozjs/scripts/import.sh
	${LN} -sF ${WRKDIR}/spidermonkey-${MOZJS_TAG} ${MOZJS_WRKSRC}/mozilla-release
# Bazel finds the files it downloads in its repository cache by sha256, which
# is also the checksum of a module in its source.json.
# BAZEL_HTTP_RULES_URLS_AS_DEFAULT_CANONICAL_ID=0 makes Bazel find them without
# the id- files of the download URLs. With downloads disabled, Bazel also reads
# the files of the file:// registry from the cache.
	${PYTHON_CMD} ${FILESDIR}/bazel-cache-add.py ${BAZEL_REPOSITORY_CACHE} \
		${BAZEL_REGISTRY_WRKSRC} ${_BAZEL_CACHE_ARGS}

do-build:
	${MKDIR} ${BAZEL_REPOSITORY_CACHE}
	cd ${WRKSRC} && ${SETENV} ${BAZEL_ENV} ${BAZEL} ${BAZEL_STARTUP_ARGS} build ${BAZEL_ARGS} ${ALL_TARGET}

do-install:
	${INSTALL_PROGRAM} ${BAZEL_INSTALL_WRKSRC}/bin/mongod ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_PROGRAM} ${BAZEL_INSTALL_WRKSRC}/bin/mongos ${STAGEDIR}${PREFIX}/bin/
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

.include <bsd.port.post.mk>
