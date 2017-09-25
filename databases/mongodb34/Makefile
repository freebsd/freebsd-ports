# $FreeBSD$

PORTNAME=	mongodb
DISTVERSIONPREFIX=	r
DISTVERSION=	3.4.6
PORTREVISION=	3
CATEGORIES=	databases net
MASTER_SITES=	https://fastdl.mongodb.org/src/ \
		http://fastdl.mongodb.org/src/ \
		http://download.mongodb.org/src/
PKGNAMESUFFIX=	${PORTVERSION:R:S/.//}
DISTNAME=	mongodb-src-${DISTVERSIONPREFIX}${DISTVERSION}

MAINTAINER=	eric@camachat.org
COMMENT=	Distributed document-oriented "NoSQL" database

# mongodb is AGPLv3, C++ driver is APACHE20
LICENSE=	AGPLv3 APACHE20
LICENSE_COMB=	multi

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	"Only supported on amd64 (i386 deprecated in v3)"

LIB_DEPENDS=	libpcre.so:devel/pcre \
		libsnappy.so:archivers/snappy \
		libboost_system.so:devel/boost-libs
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}yaml>=3.11:devel/py-yaml \
		${PYTHON_PKGNAMEPREFIX}pymongo>=3.0:databases/pymongo

CONFLICTS_BUILD=	mongo-cxx-driver

CHOSEN_COMPILER_TYPE=	clang

USES=		compiler:c++14-lang cpe python:build scons
USE_RC_SUBR=	mongod

MAKE_ARGS=	--prefix=${STAGEDIR}${PREFIX} \
		--use-system-pcre --use-system-snappy \
		--use-system-boost --use-system-zlib \
		--cxx-std=14 --libc++ \
		--runtime-hardening=on \
		--disable-warnings-as-errors \
		VERBOSE=on

WITH_DEBUG=	yes

USERS=		mongodb
GROUPS=		mongodb

OPTIONS_DEFINE=		SASL SSL
OPTIONS_DEFAULT=	SASL SSL

SASL_LIB_DEPENDS=	libsasl2.so:security/cyrus-sasl2
SASL_MAKE_ARGS=		--use-sasl-client

SSL_USES=	ssl
SSL_MAKE_ARGS=	--ssl

ALL_TARGET=	core
TEST_TARGET=	unittests

PORTSCOUT=	limitw:1,even

CPE_PRODUCT=	mongodb

post-install:
.for f in mongo mongod mongoperf mongos
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${f}
.endfor
	${CP} ${WRKSRC}/rpm/mongod.conf ${STAGEDIR}${PREFIX}/etc/mongodb.conf.sample

do-test:
	@cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${MAKE_CMD} ${_MAKE_JOBS} ${MAKE_ARGS} ${TEST_TARGET} &&\
		${PYTHON_CMD} ${BUILD_WRKSRC}/buildscripts/resmoke.py\
		--suites=unittests --jobs=${MAKE_JOBS_NUMBER}

.include <bsd.port.mk>
