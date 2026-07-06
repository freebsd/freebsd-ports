PORTNAME=	immer
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.1
CATEGORIES=	devel

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Postmodern immutable and persistent data structures for C++
WWW=		https://sinusoid.es/immer/

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	boost-libs>=0:devel/boost-libs \
		libfmt>=0:devel/libfmt

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
			catch2>=0:devel/catch2 \
			libfmt>=0:devel/libfmt
TEST_USES=		compiler:c++14-lang pkgconfig
TEST_CMAKE_BOOL=	immer_BUILD_EXAMPLES \
			immer_BUILD_TESTS
TEST_ALL_TARGET=	install examples tests
TEST_ALL_TARGET_OFF=	install
TEST_TEST_TARGET=	test

post-patch:
	@${REINPLACE_CMD} -E -e 's|(project\(.*VERSION )[0-9.]+|\1${DISTVERSION}|' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
