PORTNAME=	cli11
DISTVERSIONPREFIX=	v
DISTVERSION=	2.1.2
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Command line parser for C++11 and beyond

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	${LOCALBASE}/include/boost/optional.hpp:devel/boost-libs

USES=		cmake:testing compiler:c++11-lang

USE_GITHUB=	yes
GH_ACCOUNT=	CLIUtils
GH_PROJECT=	CLI11

CMAKE_OFF=	BUILD_TESTING CLI11_BUILD_EXAMPLES
CMAKE_TESTING_ON=	BUILD_TESTING # CLI11_BOOST # tests fail with Boost, see https://github.com/CLIUtils/CLI11/issues/645

NO_ARCH=	yes

.include <bsd.port.mk>
