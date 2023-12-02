PORTNAME=	mongodb
DISTVERSIONPREFIX=	r
DISTVERSION=	5.0.23
CATEGORIES=	databases net
MASTER_SITES=	https://fastdl.mongodb.org/src/ \
		http://fastdl.mongodb.org/src/
PKGNAMESUFFIX=	${DISTVERSION:R:S/.//}
DISTNAME=	mongodb-src-${DISTVERSIONPREFIX}${DISTVERSION}

MAINTAINER=	ronald@FreeBSD.org
COMMENT=	Distributed document-oriented "NoSQL" database (5.0.x Branch)
WWW=		https://docs.mongodb.com/v5.0/

LICENSE=	APACHE20 SSPLv1 # mongodb is SSPLv1, C++ driver is APACHE20
LICENSE_COMB=	multi
LICENSE_NAME_SSPLv1=	Server Side Public License Version 1
LICENSE_FILE_SSPLv1=	${WRKSRC}/LICENSE-Community.txt
LICENSE_PERMS_SSPLv1=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

ONLY_FOR_ARCHS=	aarch64 amd64 powerpc64le
ONLY_FOR_ARCHS_REASON=	only ported to amd64, aarch64, and powerpc64le on FreeBSD; upstream supports arm64, ppc64le, s390x, and x86-64

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cheetah3>0:devel/py-cheetah3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=3.11:devel/py-yaml@${PY_FLAVOR}
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libpcre.so:devel/pcre \
		libsnappy.so:archivers/snappy \
		libstemmer.so:textproc/snowballstemmer \
		libunwind.so:devel/libunwind \
		libyaml-cpp.so:devel/yaml-cpp \
		libzstd.so:archivers/zstd

USES=		compiler:c++17-lang cpe python:build scons shebangfix
USE_RC_SUBR=	mongod

SHEBANG_FILES=	buildscripts/scons.py
python_OLD_CMD=	@python_interpreter@

MAKE_ARGS=	--cxx-std=17 \
		--disable-warnings-as-errors \
		--libc++ \
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
		VERBOSE=on

CFLAGS+=	-DBOOST_NO_CXX98_FUNCTION_BASE

CONFLICTS_INSTALL=	mongodb[0-9][0-9] # etc/mongodb.conf.sample

USERS=		mongodb
GROUPS=		mongodb

OPTIONS_DEFINE=		LTO SASL SSL NOAVX
OPTIONS_DEFAULT=	LTO SASL SSL

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

post-patch:
	${RM} -rf ${WRKSRC}/src/third_party/pcre-*
	${RM} -rf ${WRKSRC}/src/third_party/snappy-*
	${RM} -rf ${WRKSRC}/src/third_party/unwind
	${RM} -rf ${WRKSRC}/src/third_party/yaml-cpp
	${RM} -rf ${WRKSRC}/src/third_party/zlib-*
	${RM} -rf ${WRKSRC}/src/third_party/zstandard-*

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

.include <bsd.port.post.mk>
