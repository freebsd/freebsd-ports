# $FreeBSD$

PORTNAME=	range-v3
DISTVERSION=	0.10.0
CATEGORIES=	devel

MAINTAINER=	henry.hu.sh@gmail.com
COMMENT=	Experimental range library for C++11/14/17

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cmake compiler:c++11-lang
USE_GITHUB=	yes
GH_ACCOUNT=	ericniebler
NO_ARCH=	yes

OPTIONS_DEFINE=	TESTS EXAMPLES
OPTIONS_DEFAULT=

# See issue 1321, 1441, etc.
TESTS_DESC=	Build tests (fail with clang 9.0)
EXAMPLES_DESC=	Build examples

TESTS_CMAKE_BOOL=	RANGE_V3_TESTS
EXAMPLES_CMAKE_BOOL=	RANGE_V3_EXAMPLES

post-install:
	@${RM} ${STAGEDIR}${PREFIX}/include/module.modulemap

.include <bsd.port.mk>
