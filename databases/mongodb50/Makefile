PORTNAME=	mongodb
DISTVERSIONPREFIX=	r
DISTVERSION=	5.0.31
PORTREVISION=	1
CATEGORIES=	databases net
PKGNAMESUFFIX=	${DISTVERSION:R:S/.//}

MAINTAINER=	ronald@FreeBSD.org
COMMENT=	MongoDB Community Edition (5.0.x Branch)
WWW=		https://www.mongodb.com/docs/v5.0/

LICENSE=	APACHE20 SSPLv1 # mongodb is SSPLv1, C++ driver is APACHE20
LICENSE_COMB=	multi
LICENSE_NAME_SSPLv1=	Server Side Public License Version 1
LICENSE_FILE_SSPLv1=	${WRKSRC}/LICENSE-Community.txt
LICENSE_PERMS_SSPLv1=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

DEPRECATED=	EOL from October 2024, see https://www.mongodb.com/legal/support-policy/lifecycles, please use databases/mongodb60
EXPIRATION_DATE=	2025-07-30
ONLY_FOR_ARCHS=	aarch64 amd64 powerpc64le
ONLY_FOR_ARCHS_REASON=	only ported to amd64, aarch64, and powerpc64le on FreeBSD; upstream supports arm64, ppc64le, s390x, and x86-64

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}cheetah3>0:devel/py-cheetah3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=3.11:devel/py-pyyaml@${PY_FLAVOR}
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libpcre.so:devel/pcre \
		libsnappy.so:archivers/snappy \
		libstemmer.so:textproc/snowballstemmer \
		libunwind.so:devel/libunwind \
		libyaml-cpp.so:devel/yaml-cpp \
		libzstd.so:archivers/zstd

USES=		compiler:c++17-lang cpe llvm:max=18,build python:build scons shebangfix
USE_RC_SUBR=	mongod

USE_GITHUB=	yes
GH_ACCOUNT=	mongodb
GH_PROJECT=	mongo

SHEBANG_FILES=	buildscripts/scons.py
python_OLD_CMD=	@python_interpreter@

EXTRACT_AFTER_ARGS=	--exclude src/third_party/pcre-* \
			--exclude src/third_party/snappy-* \
			--exclude src/third_party/unwind \
			--exclude src/third_party/yaml-cpp \
			--exclude src/third_party/zlib-* \
			--exclude src/third_party/zstandard-* \
			--no-same-owner --no-same-permissions

# --modules= disables "enterprise" module from src/mongo/db/modules/
MAKE_ARGS=	--cxx-std=17 \
		--disable-warnings-as-errors \
		--libc++ \
		--modules= \
		--runtime-hardening=on \
		--use-system-libunwind \
		--use-system-pcre \
		--use-system-snappy \
		--use-system-stemmer \
		--use-system-yaml \
		--use-system-zlib \
		--use-system-zstd \
		-j ${MAKE_JOBS_NUMBER} \
		AR=llvm-ar \
		MONGO_VERSION=${DISTVERSION} \
		VERBOSE=on

CFLAGS+=	-DBOOST_NO_CXX98_FUNCTION_BASE \
		-Wno-deprecated-builtins

CONFLICTS_INSTALL=	mongodb[0-9][0-9] # etc/mongodb.conf.sample

USERS=		mongodb
GROUPS=		mongodb

OPTIONS_DEFINE=		LTO SASL SSL NOAVX
OPTIONS_DEFAULT=	SASL SSL NOAVX

NOAVX_DESC=	"Disable AVX instructions on amd64 (Sandybridge+)"

LTO_MAKE_ARGS=	--lto=on

NOAVX_MAKE_ARGS=	--experimental-optimization="-sandybridge"

SASL_LIB_DEPENDS=	libsasl2.so:security/cyrus-sasl2
SASL_MAKE_ARGS=		--use-sasl-client

SSL_USES=	ssl
SSL_MAKE_ARGS=	--ssl

.include <bsd.port.pre.mk>

.if ${ARCH} == aarch64 || ${ARCH} == powerpc64le
EXTRA_PATCHES=	${FILESDIR}/${ARCH}
.endif

ALL_TARGET=	install-core

# This ports is only following the Major Release.
# https://docs.mongodb.com/manual/reference/versioning/
PORTSCOUT=	limit:^5\.0\.

CPE_PRODUCT=	mongodb

pre-patch:
	${MV} ${WRKSRC}/src/third_party/wiredtiger/src/checksum/power8/crc32.sx ${WRKSRC}/src/third_party/wiredtiger/src/checksum/power8/crc32.S

do-build:
	${WRKSRC}/buildscripts/scons.py	-C ${WRKSRC} ${MAKE_ARGS}

do-install:
.for f in mongo mongod mongos
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${f}
.endfor
	${INSTALL_DATA} ${WRKSRC}/rpm/mongod.conf ${STAGEDIR}${PREFIX}/etc/mongodb.conf.sample
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in LICENSE-Community.txt MPL-2 README THIRD-PARTY-NOTICES
	${MV} ${STAGEDIR}${PREFIX}/${doc} ${STAGEDIR}${DOCSDIR}/
.endfor
	${RM} ${STAGEDIR}${PREFIX}/bin/resmoke.py

do-test:
	${SH} ${FILESDIR}/make.test.sh "${STAGEDIR}${PREFIX}/bin"

.include <bsd.port.post.mk>
