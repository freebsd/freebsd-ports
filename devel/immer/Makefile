PORTNAME=	immer
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.0
CATEGORIES=	devel

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Postmodern immutable and persistent data structures for C++
WWW=		https://sinusoid.es/immer/

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	arximboldi

CMAKE_ON=	DISABLE_WERROR
CMAKE_OFF=	immer_BUILD_DOCS \
		immer_BUILD_EXTRAS

NO_ARCH=	yes

OPTIONS_DEFINE=	TEST

TEST_BUILD_DEPENDS=	boehm-gc>=0:devel/boehm-gc \
			boehm-gc-threaded>=0:devel/boehm-gc-threaded \
			boost-libs>=0:devel/boost-libs \
			catch>=0:devel/catch
TEST_USES=		compiler:c++14-lang pkgconfig
TEST_CMAKE_BOOL=	immer_BUILD_EXAMPLES \
			immer_BUILD_TESTS
TEST_ALL_TARGET=	install examples tests
TEST_ALL_TARGET_OFF=	install
TEST_TEST_TARGET=	test

.include <bsd.port.mk>
