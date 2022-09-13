PORTNAME=	mongodb
DISTVERSIONPREFIX=	r
DISTVERSION=	6.0.1
CATEGORIES=	databases net
PKGNAMESUFFIX=	${DISTVERSION:R:S/.//}

MAINTAINER=	ronald-lists@klop.ws
COMMENT=	Distributed document-oriented "NoSQL" database (6.0.x Branch)
WWW=		https://docs.mongodb.com/v6.0/

LICENSE=	APACHE20 SSPLv1 # mongodb is SSPLv1, C++ driver is APACHE20
LICENSE_COMB=	multi
LICENSE_NAME_SSPLv1=	Server Side Public License Version 1
LICENSE_FILE_SSPLv1=	${WRKSRC}/LICENSE-Community.txt
LICENSE_PERMS_SSPLv1=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

ONLY_FOR_ARCHS=	aarch64 amd64
ONLY_FOR_ARCHS_REASON=	only ported to amd64 and aarch64 on FreeBSD; upstream supports arm64, ppc64le, s390x, and x86-64

BUILD_DEPENDS=	${LOCALBASE}/bin/ar:devel/binutils \
		${PYTHON_PKGNAMEPREFIX}cheetah3>0:devel/py-cheetah3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pymongo>0:databases/pymongo@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=3.11:devel/py-yaml@${PY_FLAVOR}
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libpcre.so:devel/pcre \
		libsnappy.so:archivers/snappy

USES=		compiler:c++17-lang cpe python:3.5+,build scons shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	mongodb
GH_PROJECT=	mongo
USE_RC_SUBR=	mongod

SHEBANG_FILES=	buildscripts/scons.py
python_OLD_CMD=	@python_interpreter@

CONFLICTS_INSTALL=	mongodb[0-9][0-9]

USERS=		mongodb
GROUPS=		mongodb

OPTIONS_DEFINE=		LTO SASL SSL
OPTIONS_DEFAULT=	LTO SASL SSL

MAKE_ARGS=	${MAKE_JOBS_NUMBER} \
		--cxx-std=17 \
		--disable-warnings-as-errors \
		--libc++ \
		--runtime-hardening=on \
		--use-system-pcre \
		--use-system-snappy \
		--use-system-zlib \
		-j \
		AR=${PREFIX}/bin/ar \
		MONGO_VERSION=${DISTVERSION} \
		VERBOSE=on

LTO_MAKE_ARGS=	--lto=on

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
PORTSCOUT=	limit:^6\.0\.

CPE_PRODUCT=	mongodb

#pre-patch:
#	${MV} ${WRKSRC}/src/third_party/wiredtiger/src/checksum/power8/crc32.sx ${WRKSRC}/src/third_party/wiredtiger/src/checksum/power8/crc32.S

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
