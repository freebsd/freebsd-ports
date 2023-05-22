PORTNAME=	corrade
DISTVERSIONPREFIX=	v
DISTVERSION=	2020.06-1214
DISTVERSIONSUFFIX=	-g3bf6057d
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++11/C++14 multiplatform utility library
WWW=		https://magnum.graphics/corrade/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake:testing compiler:c++14-lang
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	mosra
GH_TUPLE=	mosra:toolchains:65568a9:toolchains/toolchains

CMAKE_ARGS=	-DLIB_SUFFIX:STRING=""

OPTIONS_DEFINE=	TEST
TEST_CMAKE_BOOL=	CORRADE_BUILD_TESTS

.include <bsd.port.mk>
