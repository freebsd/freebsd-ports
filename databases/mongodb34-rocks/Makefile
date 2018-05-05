# $FreeBSD$

PORTNAME=	mongodb
PORTVERSION=	3.4.6
DISTVERSIONPREFIX=	r
PORTREVISION=	5
CATEGORIES=	databases net
MASTER_SITES=	https://fastdl.mongodb.org/src/ \
		http://fastdl.mongodb.org/src/ \
		http://download.mongodb.org/src/
PKGNAMESUFFIX=	${PORTVERSION:R:S/.//}-rocks
DISTNAME=	mongodb-src-${DISTVERSIONPREFIX}${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	numisemis@yahoo.com
COMMENT=	Distributed document-oriented database with a RocksDB Storage Engine

# mongodb is AGPLv3, C++ driver is APACHE20
LICENSE=	AGPLv3 APACHE20
LICENSE_COMB=	multi

BROKEN=		fails to link
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2018-06-06
BROKEN_SSL=	openssl-devel
BROKEN_SSL_REASON_openssl-devel=	no member named 'SSLv2_method' in the global namespace

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	"Only supported on amd64 (i386 deprecated in v3)"

LIB_DEPENDS=	libpcre.so:devel/pcre \
		libsnappy.so:archivers/snappy \
		libboost_system.so:devel/boost-libs \
		librocksdb.so:databases/rocksdb \
		liblz4.so:archivers/liblz4
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}yaml>=3.11:devel/py-yaml \
		${PYTHON_PKGNAMEPREFIX}pymongo>=3.0:databases/pymongo

USES=		compiler:c++14-lang cpe python:build scons
USE_RC_SUBR=	mongod \
		mongos

USE_GITHUB=	nodefault
GH_TUPLE=	mongodb-partners:mongo-rocks:r${PORTVERSION}:module/src/mongo/db/modules/rocks

CHOSEN_COMPILER_TYPE=	clang
CXXSTD=		c++14

CONFLICTS_BUILD=	mongo-cxx-driver
CONFLICTS_INSTALL=	mongodb \
			mongodb32 \
			mongodb34

WITH_DEBUG=yes
MAKE_ARGS=	--prefix=${STAGEDIR}${PREFIX} \
		--use-system-pcre --use-system-snappy \
		--use-system-boost --use-system-zlib \
		--libc++ --runtime-hardening=on \
		--disable-warnings-as-errors \
		VERBOSE=on

USERS=	mongodb
GROUPS=	mongodb

PORTSCOUT=	limitw:1,even

CPE_PRODUCT=	mongodb

OPTIONS_DEFINE=		SASL SSL
OPTIONS_DEFAULT=	SASL SSL

SASL_LIB_DEPENDS=	libsasl2.so:security/cyrus-sasl2
SASL_MAKE_ARGS=		--use-sasl-client

SSL_MAKE_ARGS=	--ssl
SSL_USES=	ssl

ALL_TARGET=	core
TEST_TARGET=	unittests

post-install:
.for f in mongo mongod mongoperf mongos
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${f}
.endfor
	${CP} ${WRKSRC}/rpm/mongod.conf ${STAGEDIR}${PREFIX}/etc/mongod.conf.sample

do-test:
	@cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${MAKE_CMD} ${_MAKE_JOBS} ${MAKE_ARGS} ${TEST_TARGET} &&\
		${PYTHON_CMD} ${BUILD_WRKSRC}/buildscripts/resmoke.py\
		--suites=unittests --jobs=${MAKE_JOBS_NUMBER}

.include <bsd.port.mk>
