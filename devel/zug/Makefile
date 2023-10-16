PORTNAME=	zug
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.1
CATEGORIES=	devel

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Transducers for C++
WWW=		https://sinusoid.es/zug/

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	arximboldi

CMAKE_ON=	DISABLE_WERROR
CMAKE_OFF=	zug_BUILD_DOCS

NO_ARCH=	yes

OPTIONS_DEFINE=	TEST

TEST_BUILD_DEPENDS=	catch>=0:devel/catch
TEST_USES=		compiler:c++17-lang pkgconfig
TEST_CMAKE_BOOL=	zug_BUILD_EXAMPLES \
			zug_BUILD_TESTS
TEST_ALL_TARGET=	install examples tests
TEST_ALL_TARGET_OFF=	install
TEST_TEST_TARGET=	test

.include <bsd.port.mk>
