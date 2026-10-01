PORTNAME=	mongodb
DISTVERSIONPREFIX=	r
DISTVERSION=	8.0.29
CATEGORIES=	databases net
MASTER_SITES+=	LOCAL/ronald:mongodb_bazel \
		https://codeload.github.com/bazelbuild/bazel-central-registry/tar.gz/${BAZEL_REGISTRY_COMMIT}?dummy=/:bazel_registry \
		https://codeload.github.com/mongodb-forks/rules_poetry/tar.gz/${RULES_POETRY_COMMIT}?dummy=/:rules_poetry
PKGNAMESUFFIX=	${DISTVERSION:R:S/.//}
BAZEL_CACHE_DISTFILE=	${PORTNAME}-${DISTVERSIONFULL}-bazel-repository-cache.tar.gz
BAZEL_REGISTRY_DISTFILE=	bazelbuild-bazel-central-registry-${BAZEL_REGISTRY_COMMIT}_GH0.tar.gz
RULES_POETRY_DISTFILE=	mongodb-forks-rules_poetry-${RULES_POETRY_COMMIT}_GH0.tar.gz
DISTFILES+=	${BAZEL_CACHE_DISTFILE}:mongodb_bazel \
		${BAZEL_REGISTRY_DISTFILE}:bazel_registry \
		${RULES_POETRY_DISTFILE}:rules_poetry

MAINTAINER=	ronald@FreeBSD.org
COMMENT=	MongoDB Community Edition (8.0.x Branch)
WWW=		https://www.mongodb.com/docs/v8.0/

LICENSE=	APACHE20 SSPLv1 # mongodb is SSPLv1, C++ driver is APACHE20
LICENSE_COMB=	multi
LICENSE_NAME_SSPLv1=	Server Side Public License Version 1
LICENSE_FILE_SSPLv1=	${WRKSRC}/LICENSE-Community.txt
LICENSE_PERMS_SSPLv1=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BROKEN_FreeBSD_16=	src/third_party/boost/boost/mpl/aux_/integral_wrapper.hpp:71:51: error: in-class initializer for static data member is not a constant expression

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
		git:devel/git@tiny \
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
BAZEL_STARTUP_ARGS=	--output_user_root=${BAZEL_OUTPUT_USER_ROOT}
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
			--action_env=PATH=${LOCALBASE}/bin:/bin:/usr/bin \
			--repo_env=CC=${CC} \
			--repo_env=CXX=${CXX} \
			--repo_env=LOCALBASE=${LOCALBASE} \
			--repo_env=MONGO_USE_SYSTEM_PYTHON=1 \
			--repo_env=PATH=${LOCALBASE}/bin:/bin:/usr/bin \
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
			--linkopt=-L${LOCALBASE}/lib \
			--linkopt=-lm \
			--linkopt=-pthread \
			--linkopt=-lexecinfo \
			--linkopt=-lkvm \
			--noexperimental_collect_system_network_usage
ALL_TARGET=		install-core

CONFLICTS_INSTALL=	mongodb[0-9][0-9]

BINARY_ALIAS=	python3=${PYTHON_CMD}
EXTRACT_AFTER_ARGS=	--no-same-owner --no-same-permissions

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

pre-configure:
# Replacement of ${WRKSRC}/src/third_party/mozjs/scripts/import.sh
	${LN} -sF ${WRKDIR}/spidermonkey-${MOZJS_TAG} ${MOZJS_WRKSRC}/mozilla-release

post-patch:
	${PATCH} -d ${RULES_POETRY_WRKSRC} -p0 < ${WRKSRC}/bazel/rules_poetry/rules_poetry.patch

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

.include <bsd.port.post.mk>
