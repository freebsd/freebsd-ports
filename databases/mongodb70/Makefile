PORTNAME=	mongodb
DISTVERSIONPREFIX=	r
DISTVERSION=	7.0.4
CATEGORIES=	databases net
PKGNAMESUFFIX=	${DISTVERSION:R:S/.//}

MAINTAINER=	ronald@FreeBSD.org
COMMENT=	Distributed document-oriented "NoSQL" database (7.0.x Branch)
WWW=		https://www.mongodb.com/docs/v7.0/

LICENSE=	APACHE20 SSPLv1 # mongodb is SSPLv1, C++ driver is APACHE20
LICENSE_COMB=	multi
LICENSE_NAME_SSPLv1=	Server Side Public License Version 1
LICENSE_FILE_SSPLv1=	${WRKSRC}/LICENSE-Community.txt
LICENSE_PERMS_SSPLv1=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

ONLY_FOR_ARCHS=	aarch64 amd64 powerpc64le
ONLY_FOR_ARCHS_REASON=	only ported to amd64, aarch64, and powerpc64le on FreeBSD; upstream supports arm64, ppc64le, s390x, and x86-64

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cheetah3>0:devel/py-cheetah3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pymongo>0:databases/py-pymongo@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=3.11:devel/py-yaml@${PY_FLAVOR}
# build depends used while running ${WRKSRC}/src/third_party/mozjs/gen-config.sh
BUILD_DEPENDS+=	autoconf2.13:devel/autoconf2.13 \
		gsed:textproc/gsed
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libpcre2-8.so:devel/pcre2 \
		libsnappy.so:archivers/snappy \
		libstemmer.so:textproc/snowballstemmer \
		libunwind.so:devel/libunwind \
		libyaml-cpp.so:devel/yaml-cpp \
		libzstd.so:archivers/zstd

USES=		compiler:c++20-lang cpe python:build scons shebangfix
# gmake is used while running ${WRKSRC}/src/third_party/mozjs/gen-config.sh
USES+=		gmake pkgconfig

# mozjs tag comes from ${WRKSRC}/src/third_party/mozjs/get-sources.sh
MOZJS_TAG=	82aac6af18abcd5bf188afbc821779ccb0ca0902

USE_GITHUB=	yes
GH_ACCOUNT=	mongodb mongodb-forks:mozjs
GH_PROJECT=	mongo spidermonkey:mozjs
GH_TAGNAME=	${MOZJS_TAG}:mozjs
USE_RC_SUBR=	mongod

SHEBANG_FILES=	buildscripts/scons.py
python_OLD_CMD=	@python_interpreter@

MAKE_ARGS=	--allocator=system \
		--cxx-std=20 \
		--disable-warnings-as-errors \
		--libc++ \
		--runtime-hardening=on \
		--use-system-libunwind \
		--use-system-pcre2 \
		--use-system-snappy \
		--use-system-stemmer \
		--use-system-yaml \
		--use-system-zlib \
		--use-system-zstd \
		-j${MAKE_JOBS_NUMBER} \
		AR=llvm-ar \
		MONGO_VERSION=${DISTVERSION} \
		VERBOSE=on

CFLAGS+=	-DBOOST_NO_CXX98_FUNCTION_BASE

CONFLICTS_INSTALL=	mongodb[0-9][0-9]

USERS=		mongodb
GROUPS=		mongodb

OPTIONS_DEFINE=		LTO SASL SSL NOAVX
OPTIONS_DEFINE_aarch64=	ARMV80A
OPTIONS_DEFAULT=	SASL SSL

# MongoDB on non-LSE ARM cpu like Raspberry Pi can work but is unsupported upstream.
# Can give corruption on high concurrency.
# Please read https://jira.mongodb.org/browse/SERVER-71772.
ARMV80A_DESC=	Enable non-LSE ARM64 CPUs like RPI4.
NOAVX_DESC=	"Disable AVX instructions on amd64 (Sandybridge+)"

ARMV80A_EXTRA_PATCHES=	${FILESDIR}/extrapatch-SConstruct

LTO_MAKE_ARGS=	--lto=on

NOAVX_MAKE_ARGS=	--experimental-optimization="-sandybridge"

SASL_LIB_DEPENDS=	libsasl2.so:security/cyrus-sasl2
SASL_MAKE_ARGS=		--use-sasl-client

SSL_USES=	ssl
SSL_MAKE_ARGS=	--ssl

.include <bsd.port.pre.mk>

ALL_TARGET=	install-core

# This ports is only following the Major Release.
# https://docs.mongodb.com/manual/reference/versioning/
PORTSCOUT=	limit:^7\.0\.

CPE_PRODUCT=	mongodb

.if ${ARCH} == amd64
MOZJS_ARCH=	x86_64
.elif ${ARCH} == powerpc64le
MOZJS_ARCH=	ppc64le
.elif ${ARCH} == aarch64
MOZJS_ARCH=	${ARCH}
.endif

post-patch:
	${RM} -rf ${WRKSRC}/src/third_party/pcre2
	${RM} -rf ${WRKSRC}/src/third_party/snappy-*
	${RM} -rf ${WRKSRC}/src/third_party/libstemmer_c
	${RM} -rf ${WRKSRC}/src/third_party/unwind
	${RM} -rf ${WRKSRC}/src/third_party/yaml-cpp
	${RM} -rf ${WRKSRC}/src/third_party/zlib-*
	${RM} -rf ${WRKSRC}/src/third_party/zstandard

do-configure:
# Replacement of ${WRKSRC}/src/third_party/mozjs/get-sources.sh
	${LN} -sF ${WRKDIR}/spidermonkey-${MOZJS_TAG} ${WRKSRC}/src/third_party/mozjs/mozilla-release
	cd ${WRKSRC}/src/third_party/mozjs/mozilla-release/js/src && ${LOCALBASE}/bin/autoconf2.13
	cd ${WRKSRC}/src/third_party/mozjs && PYTHON3="${PYTHON_CMD}" ${SH} ./gen-config.sh ${MOZJS_ARCH} freebsd

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
	${RM} ${STAGEDIR}${PREFIX}/bin/resmoke.py

.include <bsd.port.post.mk>
