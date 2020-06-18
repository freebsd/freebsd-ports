# $FreeBSD$

PORTNAME=	mongodb
DISTVERSIONPREFIX=	r
DISTVERSION=	4.2.8
CATEGORIES=	databases net
MASTER_SITES=	https://fastdl.mongodb.org/src/ \
		http://fastdl.mongodb.org/src/
PKGNAMESUFFIX=	${DISTVERSION:R:S/.//}
DISTNAME=	mongodb-src-${DISTVERSIONPREFIX}${DISTVERSION}

MAINTAINER=	ronald-lists@klop.ws
COMMENT=	Distributed document-oriented "NoSQL" database (4.2.x Branch)

# mongodb is SSPL, C++ driver is APACHE20
LICENSE=	SSPL APACHE20
LICENSE_COMB=	multi

ONLY_FOR_ARCHS=	aarch64 amd64
ONLY_FOR_ARCHS_REASON=	"Only ported to amd64 and aarch64 on FreeBSD. Upstream supports arm64, ppc64le, s390x and x86-64."

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cheetah3>0:devel/py-cheetah3@${PY_FLAVOR} \
		${PY_TYPING} \
		${PYTHON_PKGNAMEPREFIX}yaml>=3.11:devel/py-yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>0:sysutils/py-psutil@${PY_FLAVOR} \
		${LOCALBASE}/bin/ar:devel/binutils
LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libpcre.so:devel/pcre \
		libcurl.so:ftp/curl \
		libsnappy.so:archivers/snappy

USES=		compiler:c++17-lang cpe python:3.5+,build scons shebangfix
USE_RC_SUBR=	mongod

LICENSE_FILE_SSPL=	${WRKSRC}/LICENSE-Community.txt
LICENSE_NAME_SSPL=	Server Side Public License
LICENSE_PERMS_SSPL=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

CONFLICTS_BUILD=	mongo-cxx-driver
CONFLICTS_INSTALL=	mongodb36 mongodb40

OPTIONS_DEFINE=	SASL SSL
OPTIONS_DEFAULT=SASL SSL

SHEBANG_FILES=	src/mongo/installer/compass/install_compass.in
python_OLD_CMD=	@python_interpreter@
MAKE_ARGS=	--prefix=${STAGEDIR}${PREFIX} \
		--use-system-zlib \
		--use-system-pcre \
		--use-system-snappy \
		--use-system-boost \
		--libc++ \
		--cxx-std=17 \
		--runtime-hardening=on \
		-j ${MAKE_JOBS_NUMBER} \
		--disable-warnings-as-errors \
		VERBOSE=on \
		AR=${PREFIX}/bin/ar

USERS=		mongodb
GROUPS=		mongodb

SASL_LIB_DEPENDS=	libsasl2.so:security/cyrus-sasl2
SASL_MAKE_ARGS=		--use-sasl-client

SSL_USES=	ssl
SSL_MAKE_ARGS=	--ssl

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1200057
SUB_LIST+=	LEGACY_LIMITS="@comment " MODERN_LIMITS=""
.else
SUB_LIST+=	LEGACY_LIMITS="" MODERN_LIMITS="@comment "
.endif

.if ${ARCH} == aarch64
EXTRA_PATCHES=	${FILESDIR}/aarch64
.endif

ALL_TARGET=	core

PORTSCOUT=	limitw:1,even

CPE_PRODUCT=	mongodb

post-install:
.for f in mongo mongod mongos
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${f}
.endfor
	${CP} ${WRKSRC}/rpm/mongod.conf ${STAGEDIR}${PREFIX}/etc/mongodb.conf.sample

.include <bsd.port.post.mk>
