PORTNAME=	mongodb
DISTVERSIONPREFIX=	r
DISTVERSION=	8.0.12
PORTREVISION=	2
CATEGORIES=	databases net
PKGNAMESUFFIX=	${DISTVERSION:R:S/.//}

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

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
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
		rust-cbindgen>0:devel/rust-cbindgen
# build depends used while running ${WRKSRC}/src/third_party/mozjs/gen-config.sh
BUILD_DEPENDS+=	gm4:devel/m4 \
		gsed:textproc/gsed
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libsnappy.so:archivers/snappy \
		libstemmer.so:textproc/snowballstemmer \
		libunwind.so:devel/libunwind \
		libyaml-cpp.so:devel/yaml-cpp \
		libzstd.so:archivers/zstd

FLAVORS=	default armv80a

armv80a_PKGNAMESUFFIX=	${DISTVERSION:R:S/.//}-armv80a

USES=		compiler:c++20-lang cpe python:build scons shebangfix ssl
# gmake is used while running ${WRKSRC}/src/third_party/mozjs/gen-config.sh
USES+=		gmake pkgconfig
CPE_PRODUCT=	mongodb

# mozjs tag comes from ${WRKSRC}/src/third_party/mozjs/get-sources.sh
MOZJS_TAG=	5acd3be6c9563ad3e7ca6182285c69a38de47bab

USE_GITHUB=	yes
GH_ACCOUNT=	mongodb mongodb-forks:mozjs
GH_PROJECT=	mongo spidermonkey:mozjs
GH_TAGNAME=	${MOZJS_TAG}:mozjs
USE_RC_SUBR=	mongod

SHEBANG_FILES=	buildscripts/scons.py
python_OLD_CMD=	@python_interpreter@

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	gen-config.sh
CONFIGURE_ARGS+=	${MOZJS_ARCH} \
			freebsd
CONFIGURE_ENV+=		PYTHON3="${PYTHON_CMD}"

MAKE_ARGS=	--allocator=system \
		--cxx-std=20 \
		--disable-warnings-as-errors \
		--libc++ \
		--runtime-hardening=on \
		--ssl \
		--use-system-libunwind \
		--use-system-snappy \
		--use-system-stemmer \
		--use-system-yaml \
		--use-system-zlib \
		--use-system-zstd \
		-j${MAKE_JOBS_NUMBER} \
		AR=llvm-ar \
		MONGO_VERSION=${DISTVERSION} \
		VERBOSE=on
ALL_TARGET=	install-servers

CFLAGS+=	-DBOOST_NO_CXX98_FUNCTION_BASE

CONFLICTS_INSTALL=	mongodb[0-9][0-9]

EXTRACT_AFTER_ARGS=	--exclude src/third_party/snappy-* \
			--exclude src/third_party/libstemmer_c \
			--exclude src/third_party/unwind \
			--exclude src/third_party/yaml-cpp \
			--exclude src/third_party/zlib-* \
			--exclude src/third_party/zstandard \
			--no-same-owner --no-same-permissions

# This ports is only following the Major Release.
# https://docs.mongodb.com/manual/reference/versioning/
PORTSCOUT=	limit:^8\.0\.

CONFIGURE_WRKSRC=	${MOZJS_WRKSRC}

USERS=		mongodb
GROUPS=		mongodb

OPTIONS_DEFINE=		LTO NOAVX SASL
OPTIONS_DEFINE_aarch64=	ARMV80A
OPTIONS_DEFAULT=	NOAVX SASL

# MongoDB on non-LSE ARM cpu like Raspberry Pi can work but is unsupported upstream.
# Can give corruption on high concurrency.
# Please read https://jira.mongodb.org/browse/SERVER-71772.
ARMV80A_DESC=	Enable non-LSE ARM64 CPUs like RPI4.
NOAVX_DESC=	"Disable AVX instructions on amd64 (Sandybridge+)"

ARMV80A_EXTRA_PATCHES=	${FILESDIR}/extrapatch-SConstruct

LTO_MAKE_ARGS=	--lto=on

NOAVX_MAKE_ARGS=	--experimental-optimization="-sandybridge"
NOAVX_EXTRA_PATCHES=	${FILESDIR}/extrapatch-src_third__party_mozjs_SConscript \
			${FILESDIR}/extrapatch-src_third__party_mozjs_extract_mozglue_misc_SIMD.cpp

SASL_LIB_DEPENDS=	libsasl2.so:security/cyrus-sasl2
SASL_MAKE_ARGS=		--use-sasl-client

MOZJS_WRKSRC=	${WRKSRC}/src/third_party/mozjs

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
	${SH} -xc "test \"X`grep -E '^LIB_GIT_REVISION=' ${MOZJS_WRKSRC}/get-sources.sh`\" = \"XLIB_GIT_REVISION=${MOZJS_TAG}\""

pre-configure:
# Replacement of ${WRKSRC}/src/third_party/mozjs/get-sources.sh
	${LN} -sF ${WRKDIR}/spidermonkey-${MOZJS_TAG} ${MOZJS_WRKSRC}/mozilla-release

do-build:
	${WRKSRC}/buildscripts/scons.py	-C ${WRKSRC} ${MAKE_ARGS}

do-install:
.for f in mongod mongos
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${f}
.endfor
	${INSTALL_DATA} ${WRKSRC}/rpm/mongod.conf ${STAGEDIR}${PREFIX}/etc/mongodb.conf.sample
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in LICENSE-Community.txt MPL-2 README THIRD-PARTY-NOTICES
	${MV} ${STAGEDIR}${PREFIX}/${doc} ${STAGEDIR}${DOCSDIR}/
.endfor
	${INSTALL_MAN} ${WRKSRC}/debian/mongod.1 ${STAGEDIR}${PREFIX}/share/man/man1/
	${INSTALL_MAN} ${WRKSRC}/debian/mongos.1 ${STAGEDIR}${PREFIX}/share/man/man1/
	${INSTALL_MAN} ${WRKSRC}/debian/mongodb-parameters.5 ${STAGEDIR}${PREFIX}/share/man/man5/
	${RM} ${STAGEDIR}${PREFIX}/bin/resmoke.py

do-test:
	${SH} ${FILESDIR}/make.test.sh "${STAGEDIR}${PREFIX}/bin"

.include <bsd.port.post.mk>
