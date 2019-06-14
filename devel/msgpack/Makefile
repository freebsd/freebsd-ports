# $FreeBSD$

PORTNAME=	msgpack
PORTVERSION=	3.2.0
DISTVERSIONPREFIX=	cpp-
CATEGORIES=	devel

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Efficient binary serialization, like JSON but smaller and faster

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE_1_0.txt

TEST_DEPENDS=	googletest>0:devel/googletest

USES=		cmake pathfix
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_PROJECT=	msgpack-c

CMAKE_OFF=	MSGPACK_BUILD_EXAMPLES
TEST_TARGET=	test

.include <bsd.port.options.mk>

.if ${ARCH} == "sparc64"
# required for __sync _* atomic operations on sparc
USE_GCC=	yes
.endif

pre-test:
	cd ${WRKSRC} && ${CMAKE_BIN} . && ${MAKE_CMD}

.include <bsd.port.mk>
