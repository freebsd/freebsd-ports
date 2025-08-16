PORTNAME=	mongodb
DISTVERSIONPREFIX=	r
DISTVERSION=	6.0.26
CATEGORIES=	databases net
MASTER_SITES=	https://hg.mozilla.org/mozilla-central/raw-rev/:patches
PKGNAMESUFFIX=	${DISTVERSION:R:S/.//}
DISTFILES=	223087fdc29f18678f6174e9807b8780e439acf6:patches # https://bugzilla.mozilla.org/1894423
EXTRACT_ONLY=	${GH_ACCOUNT}-${GH_PROJECT}-${DISTVERSIONPREFIX}${DISTVERSION}_GH0.tar.gz \
		${GH_ACCOUNT}-forks-spidermonkey-${MOZJS_TAG}_GH0.tar.gz

MAINTAINER=	ronald@FreeBSD.org
COMMENT=	MongoDB Community Edition (6.0.x Branch)
WWW=		https://www.mongodb.com/docs/v6.0/

LICENSE=	APACHE20 SSPLv1 # mongodb is SSPLv1, C++ driver is APACHE20
LICENSE_COMB=	multi
LICENSE_NAME_SSPLv1=	Server Side Public License Version 1
LICENSE_FILE_SSPLv1=	${WRKSRC}/LICENSE-Community.txt
LICENSE_PERMS_SSPLv1=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

DEPRECATED=	EOL starting August 2025, see https://www.mongodb.com/legal/support-policy/lifecycles, please use databases/mongodb70
EXPIRATION_DATE=	2025-10-30

ONLY_FOR_ARCHS=	aarch64 amd64 powerpc64le
ONLY_FOR_ARCHS_REASON=	only ported to amd64, aarch64, and powerpc64le on FreeBSD; upstream supports arm64, ppc64le, s390x, and x86-64

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}cheetah3>0:devel/py-cheetah3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pymongo>0:databases/py-pymongo@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=3.11:devel/py-pyyaml@${PY_FLAVOR}
# build depends used while running ${WRKSRC}/src/third_party/mozjs/gen-config.sh
BUILD_DEPENDS+=	autoconf2.13:devel/autoconf2.13 \
		gsed:textproc/gsed
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libicuuc.so:devel/icu \
		libpcre.so:devel/pcre \
		libsnappy.so:archivers/snappy \
		libstemmer.so:textproc/snowballstemmer \
		libunwind.so:devel/libunwind \
		libyaml-cpp.so:devel/yaml-cpp \
		libzstd.so:archivers/zstd

USES=		compiler:c++17-lang cpe python:build scons shebangfix ssl
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

MAKE_ARGS=	--cxx-std=17 \
		--disable-warnings-as-errors \
		--libc++ \
		--runtime-hardening=on \
		--ssl \
		--use-system-icu \
		--use-system-libunwind \
		--use-system-pcre \
		--use-system-snappy \
		--use-system-stemmer \
		--use-system-yaml \
		--use-system-zlib \
		--use-system-zstd \
		-j${MAKE_JOBS_NUMBER} \
		AR=llvm-ar \
		MONGO_VERSION=${DISTVERSION} \
		VERBOSE=on

CFLAGS+=	-DBOOST_NO_CXX98_FUNCTION_BASE \
		-Wno-deprecated-builtins

CONFLICTS_INSTALL=	mongodb[0-9][0-9]

EXTRACT_AFTER_ARGS=	--exclude src/third_party/icu4c-* \
			--exclude src/third_party/pcre-* \
			--exclude src/third_party/snappy-* \
			--exclude src/third_party/libstemmer_c \
			--exclude src/third_party/unwind \
			--exclude src/third_party/yaml-cpp \
			--exclude src/third_party/zlib-* \
			--exclude src/third_party/zstandard \
			--no-same-owner --no-same-permissions

USERS=		mongodb
GROUPS=		mongodb

OPTIONS_DEFINE=		LTO NOAVX SASL
OPTIONS_DEFAULT=	NOAVX SASL

NOAVX_DESC=	"Disable AVX instructions on amd64 (Sandybridge+)"

LTO_MAKE_ARGS=	--lto=on

NOAVX_MAKE_ARGS=	--experimental-optimization="-sandybridge"

SASL_LIB_DEPENDS=	libsasl2.so:security/cyrus-sasl2
SASL_MAKE_ARGS=		--use-sasl-client

.include <bsd.port.pre.mk>

ALL_TARGET=	install-core

# This ports is only following the Major Release.
# https://docs.mongodb.com/manual/reference/versioning/
PORTSCOUT=	limit:^6\.0\.

CPE_PRODUCT=	mongodb

.if ${ARCH} == amd64
MOZJS_ARCH=	x86_64
.elif ${ARCH} == powerpc64le
MOZJS_ARCH=	ppc64le
.elif ${ARCH} == aarch64
MOZJS_ARCH=	${ARCH}
.endif

post-extract:
# Verify we downloaded the proper mozjs git tag.
	${SH} -xc "test \"X`grep -E '^LIB_GIT_REVISION=' ${WRKSRC}/src/third_party/mozjs/get-sources.sh`\" = \"XLIB_GIT_REVISION=${MOZJS_TAG}\""

post-patch:
# fix build with python-3.11
	${REINPLACE_CMD} -e 's#rU#r#g' ${WRKDIR}/spidermonkey-${MOZJS_TAG}/python/mozbuild/mozbuild/util.py
	${REINPLACE_CMD} -e 's#rU#r#g' ${WRKDIR}/spidermonkey-${MOZJS_TAG}/python/mozbuild/mozbuild/preprocessor.py
	${REINPLACE_CMD} -e 's#rU#r#g' ${WRKDIR}/spidermonkey-${MOZJS_TAG}/python/mozbuild/mozbuild/backend/base.py
	${REINPLACE_CMD} -e 's#rU#r#g' ${WRKDIR}/spidermonkey-${MOZJS_TAG}/python/mozbuild/mozbuild/action/process_define_files.py
	${PATCH} -d ${WRKSRC}/src/third_party/mozjs/extract --quiet -p1 -V none < ${DISTDIR}/223087fdc29f18678f6174e9807b8780e439acf6

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
	${INSTALL_MAN} ${WRKSRC}/debian/mongod.1 ${STAGEDIR}${PREFIX}/share/man/man1/
	${INSTALL_MAN} ${WRKSRC}/debian/mongos.1 ${STAGEDIR}${PREFIX}/share/man/man1/
	${INSTALL_MAN} ${WRKSRC}/debian/mongodb-parameters.5 ${STAGEDIR}${PREFIX}/share/man/man5/
	${RM} ${STAGEDIR}${PREFIX}/bin/resmoke.py

do-test:
	${SH} ${FILESDIR}/make.test.sh "${STAGEDIR}${PREFIX}/bin"

.include <bsd.port.post.mk>
