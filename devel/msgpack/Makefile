# $FreeBSD$

PORTNAME=	msgpack
PORTVERSION=	3.1.0
DISTVERSIONPREFIX=	cpp-
CATEGORIES=	devel

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Efficient binary serialization, like JSON but smaller and faster

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE_1_0.txt

USES=		cmake pathfix
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_PROJECT=	msgpack-c

OPTIONS_DEFINE=	TEST

TEST_BUILD_DEPENDS=	googletest>0:devel/googletest
TEST_TEST_TARGET=	test

.include <bsd.port.options.mk>

.if ${ARCH} == "sparc64"
# required for __sync _* atomic operations on sparc
USE_GCC=	yes
.endif

# poudriere doesn't run tests yet, so hook them manually
# https://github.com/freebsd/poudriere/pull/355
pre-install-TEST-on: do-test

.include <bsd.port.mk>
