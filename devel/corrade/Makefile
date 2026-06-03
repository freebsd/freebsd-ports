PORTNAME=	corrade
DISTVERSIONPREFIX=	v
DISTVERSION=	2020.06-1783
DISTVERSIONSUFFIX=	-gd83e30e5
CATEGORIES=	devel

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	249ee71c78774f42301469d4f2f0a269d009cf66.patch:-p1 # https://github.com/mosra/corrade/pull/190

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++11/C++14 multiplatform utility library
WWW=		https://magnum.graphics/corrade/ \
		https://github.com/mosra/corrade

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake:testing compiler:c++14-lang
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	mosra
GH_TUPLE=	mosra:toolchains:2243706:toolchains/toolchains

CMAKE_ARGS_armv7=	-DCORRADE_CPU_USE_IFUNC:BOOL=OFF
CMAKE_ARGS=	-DLIB_SUFFIX:STRING="" \
		${CMAKE_ARGS_${ARCH}}

OPTIONS_DEFINE=	TEST
TEST_CMAKE_BOOL=	CORRADE_BUILD_TESTS

.include <bsd.port.pre.mk>

post-patch:
.if ${COMPILER_TYPE} == clang
	@${REINPLACE_CMD} -e 's|#include <__tuple>|#include <tuple>|g' \
		${WRKSRC}/src/Corrade/Utility/StlForwardArray.h \
		${WRKSRC}/src/Corrade/Utility/StlForwardTuple.h
.endif

# tests: 97% tests passed, 5 tests failed out of 143, see https://github.com/mosra/corrade/issues/189

.include <bsd.port.post.mk>
