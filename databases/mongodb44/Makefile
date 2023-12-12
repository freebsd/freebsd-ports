PORTNAME=	mongodb
DISTVERSIONPREFIX=	r
DISTVERSION=	4.4.26
CATEGORIES=	databases net
MASTER_SITES=	https://fastdl.mongodb.org/src/ \
		http://fastdl.mongodb.org/src/
PKGNAMESUFFIX=	${DISTVERSION:R:S/.//}
DISTNAME=	mongodb-src-${DISTVERSIONPREFIX}${DISTVERSION}

MAINTAINER=	ronald@FreeBSD.org
COMMENT=	Distributed document-oriented "NoSQL" database (4.4.x Branch)
WWW=		https://docs.mongodb.com/v4.4/

LICENSE=	SSPLv1 APACHE20 # mongodb is SSPLv1, C++ driver is APACHE20
LICENSE_COMB=	multi
LICENSE_NAME_SSPLv1=	Server Side Public License Version 1
LICENSE_FILE_SSPLv1=	${WRKSRC}/LICENSE-Community.txt
LICENSE_PERMS_SSPLv1=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

ONLY_FOR_ARCHS=	aarch64 amd64 powerpc64le
ONLY_FOR_ARCHS_REASON=	only ported to amd64, aarch64, and powerpc64le on FreeBSD; upstream supports arm64, ppc64le, s390x, and x86-64

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cheetah3>0:devel/py-cheetah3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=3.11:devel/py-yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>0:sysutils/py-psutil@${PY_FLAVOR}
LIB_DEPENDS=	libpcre.so:devel/pcre \
		libcurl.so:ftp/curl \
		libsnappy.so:archivers/snappy

USES=		compiler:c++17-lang cpe python:build scons
USE_RC_SUBR=	mongod

MAKE_ARGS=	--use-system-zlib \
		--use-system-pcre \
		--use-system-snappy \
		--libc++ \
		--cxx-std=17 \
		--runtime-hardening=on \
		-j ${MAKE_JOBS_NUMBER} \
		--disable-warnings-as-errors \
		VERBOSE=on \
		AR=llvm-ar

CFLAGS+=	-D_HAS_AUTO_PTR_ETC=0

CONFLICTS_INSTALL=	mongodb[0-9][0-9] # etc/mongodb.conf.sample

PORTSCOUT=	limit:^4\.4\.

USERS=		mongodb
GROUPS=		mongodb

OPTIONS_DEFINE=			LTO SASL SSL
OPTIONS_DEFINE_aarch64=	ARMV80A
OPTIONS_DEFAULT=		LTO SASL SSL
OPTIONS_DEFAULT_aarch64=	ARMV80A
OPTIONS_EXCLUDE_aarch64=	${OPTIONS_EXCLUDE_${ARCH}_${OSREL:R}}
OPTIONS_EXCLUDE_aarch64_14=	LTO # Does not work with llvm12 on aarch64.

# MongoDB on non-LSE ARM cpu like Raspberry Pi can work but is unsupported upstream.
# Can give corruption on high concurrency.
# Please read https://jira.mongodb.org/browse/SERVER-71772.
ARMV80A_DESC=	Enable non-LSE ARM64 CPUs like RPI4.

ARMV80A_EXTRA_PATCHES=	${FILESDIR}/extrapatch-SConstruct

LTO_MAKE_ARGS=	--lto=on

SASL_LIB_DEPENDS=	libsasl2.so:security/cyrus-sasl2
SASL_MAKE_ARGS=		--use-sasl-client

SSL_USES=	ssl
SSL_MAKE_ARGS=	--ssl

.include <bsd.port.pre.mk>

.if ${ARCH} == aarch64 || ${ARCH} == powerpc64le
EXTRA_PATCHES+=	${FILESDIR}/${ARCH}
.endif

ALL_TARGET=	install-core

CPE_PRODUCT=	mongodb

pre-patch:
	${MV} ${WRKSRC}/src/third_party/wiredtiger/src/checksum/power8/crc32.sx ${WRKSRC}/src/third_party/wiredtiger/src/checksum/power8/crc32.S

do-install:
.for f in mongo mongod mongos
	${INSTALL_PROGRAM} ${WRKSRC}/build/install${PREFIX}/bin/${f} ${STAGEDIR}${PREFIX}/bin
.endfor
	${INSTALL_DATA} ${WRKSRC}/rpm/mongod.conf ${STAGEDIR}${PREFIX}/etc/mongodb.conf.sample

.include <bsd.port.post.mk>
