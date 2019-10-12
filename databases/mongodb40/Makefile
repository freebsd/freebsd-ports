# $FreeBSD$

PORTNAME=	mongodb
DISTVERSIONPREFIX=	r
DISTVERSION=	4.0.12
CATEGORIES=	databases net
MASTER_SITES=	https://fastdl.mongodb.org/src/ \
		http://fastdl.mongodb.org/src/ \
		http://download.mongodb.org/src/
PKGNAMESUFFIX=	${PORTVERSION:R:S/.//}
DISTNAME=	mongodb-src-${DISTVERSIONPREFIX}${DISTVERSION}

MAINTAINER=	dev.ashevchuk@gmail.com
COMMENT=	Distributed document-oriented "NoSQL" database

# mongodb is AGPLv3, C++ driver is APACHE20
LICENSE=	AGPLv3 APACHE20
LICENSE_COMB=	multi

ONLY_FOR_ARCHS=	aarch64 amd64
ONLY_FOR_ARCHS_REASON=	"Only supported on amd64 and aarch64 (i386 deprecated in v3)"

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cheetah>=2.4.4:devel/py-cheetah@${PY_FLAVOR} \
		${PY_TYPING} \
		${PYTHON_PKGNAMEPREFIX}yaml>=3.11:devel/py-yaml@${PY_FLAVOR} \
		${LOCALBASE}/bin/ar:devel/binutils
LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libpcre.so:devel/pcre \
		libcurl.so:ftp/curl \
		libsnappy.so:archivers/snappy

USES=		compiler:c++14-lang cpe python:2.7,build scons shebangfix
USE_RC_SUBR=	mongod

CONFLICTS_BUILD=	mongo-cxx-driver
CONFLICTS_INSTALL=	mongodb3[46]

SHEBANG_FILES=	src/mongo/installer/compass/install_compass.in
python_OLD_CMD=	@python_interpreter@
MAKE_ARGS=	--prefix=${STAGEDIR}${PREFIX} \
		--use-system-pcre --use-system-snappy \
		--use-system-boost --use-system-zlib \
		--cxx-std=14 --libc++ \
		--runtime-hardening=on \
		--disable-warnings-as-errors \
		VERBOSE=on AR=${PREFIX}/bin/ar

USERS=		mongodb
GROUPS=		mongodb

OPTIONS_DEFINE=		SASL SSL
OPTIONS_DEFAULT=	SASL SSL

SASL_LIB_DEPENDS=	libsasl2.so:security/cyrus-sasl2
SASL_MAKE_ARGS=		--use-sasl-client

SSL_USES=	ssl
SSL_MAKE_ARGS=	--ssl

.include <bsd.port.options.mk>

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

.include <bsd.port.mk>
