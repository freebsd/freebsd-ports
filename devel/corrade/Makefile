PORTNAME=	corrade
DISTVERSIONPREFIX=	v
DISTVERSION=	2020.06-1214
DISTVERSIONSUFFIX=	-g3bf6057d
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++11/C++14 multiplatform utility library
WWW=		https://magnum.graphics/corrade/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_FreeBSD_13_armv7=	compilation fails: error: use of undeclared identifier 'vshrn_high_n_u16'
BROKEN_FreeBSD_14_armv7=	compilation fails: error: use of undeclared identifier 'vshrn_high_n_u16'

USES=		cmake:testing compiler:c++14-lang
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	mosra
GH_TUPLE=	mosra:toolchains:65568a9:toolchains/toolchains

CMAKE_ARGS=	-DLIB_SUFFIX:STRING=""

OPTIONS_DEFINE=	TEST
TEST_CMAKE_BOOL=	CORRADE_BUILD_TESTS

.include <bsd.port.pre.mk>

post-patch:
.if ${COMPILER_TYPE} == clang
	@${REINPLACE_CMD} -e 's|#include <__tuple>|#include <tuple>|g' \
		${WRKSRC}/src/Corrade/Utility/StlForwardArray.h \
		${WRKSRC}/src/Corrade/Utility/StlForwardTuple.h
.endif

.include <bsd.port.post.mk>
