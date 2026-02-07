PORTNAME=	cli11
DISTVERSIONPREFIX=	v
DISTVERSION=	2.6.1
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Command line parser for C++11 and beyond
WWW=		https://github.com/CLIUtils/CLI11

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	${LOCALBASE}/include/boost/optional.hpp:devel/boost-libs \
		catch>0:devel/catch # fails with catch2-3.x, see https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=267078

USES=		cmake:testing compiler:c++11-lang

USE_GITHUB=	yes
GH_ACCOUNT=	CLIUtils
GH_PROJECT=	CLI11

CMAKE_OFF=	BUILD_TESTING CLI11_BUILD_EXAMPLES
CMAKE_TESTING_ON=	BUILD_TESTING # CLI11_BOOST # tests fail with Boost, see https://github.com/CLIUtils/CLI11/issues/645

NO_ARCH=	yes

# tests as of 2.6.1: 100% tests passed, 0 tests failed out of 24

.include <bsd.port.mk>
