# Created by: Brendan Molloy <brendan+freebsd@bbqsrc.net>
# $FreeBSD$

PORTNAME=	mongodb32
PORTVERSION=	3.2.11
DISTVERSIONPREFIX=	r
CATEGORIES=	databases net
MASTER_SITES=	https://fastdl.mongodb.org/src/ \
		http://fastdl.mongodb.org/src/ \
		http://download.mongodb.org/src/
DISTNAME=	mongodb-src-${DISTVERSIONPREFIX}${PORTVERSION}

MAINTAINER=	brendan+freebsd@bbqsrc.net
COMMENT=	Distributed document-oriented "NoSQL" database

# mongodb is AGPLv3, C++ driver is APACHE20
LICENSE=	AGPLv3 APACHE20
LICENSE_COMB=	multi

LIB_DEPENDS=	libpcre.so:devel/pcre \
		libsnappy.so:archivers/snappy
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}yaml>=3.11:devel/py-yaml \
		${PYTHON_PKGNAMEPREFIX}pymongo>=3.0:databases/pymongo

CHOSEN_COMPILER_TYPE=	clang

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	"Only supported on amd64 (i386 deprecated in v3)"

CONFLICTS_BUILD=	mongo-cxx-driver
OPTIONS_DEFINE=		SASL SSL
OPTIONS_DEFAULT=	SASL SSL

SASL_LIB_DEPENDS=	libsasl2.so:security/cyrus-sasl2
SASL_MAKE_ARGS=		--use-sasl-client

SSL_USE=	yes
SSL_MAKE_ARGS=	--ssl

USES=		compiler cpe execinfo python:build scons

MAKE_ARGS=	--prefix=${STAGEDIR}${PREFIX} \
		--use-system-pcre --use-system-snappy \
		--release

USERS=	mongodb
GROUPS=	mongodb

USE_RC_SUBR=	mongod

ALL_TARGET=	core
TEST_TARGET=	unittests

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1002000
# Cannot be built
IGNORE=	unsupported on FreeBSD 10.1 or older
.endif
# Bugs when compiled with < Clang 3.7
#  - https://jira.mongodb.org/browse/SERVER-21217
#  - https://jira.mongodb.org/browse/SERVER-22740
.if ${COMPILER_TYPE} == clang && ${COMPILER_VERSION} < 37
BUILD_DEPENDS+=	${LOCALBASE}/bin/clang37:lang/clang37
CPP=	${LOCALBASE}/bin/clang-cpp37
CC=	${LOCALBASE}/bin/clang37
CXX=	${LOCALBASE}/bin/clang++37
.endif

post-install:
.for f in mongo mongod mongoperf mongos mongosniff
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${f}
.endfor
	${CP} ${WRKSRC}/rpm/mongod.conf ${STAGEDIR}${PREFIX}/etc/mongodb.conf.sample

do-test:
	@cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${MAKE_CMD} ${_MAKE_JOBS} ${MAKE_ARGS} ${TEST_TARGET} &&\
		${PYTHON_CMD} ${BUILD_WRKSRC}/buildscripts/resmoke.py\
		--suites=unittests --jobs=${MAKE_JOBS_NUMBER}

PORTSCOUT=	limitw:1,even

CPE_PRODUCT=	mongodb

.include <bsd.port.post.mk>
