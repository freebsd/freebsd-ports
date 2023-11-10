PORTNAME=	lager
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.1
CATEGORIES=	devel

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Redux for C++
WWW=		https://sinusoid.es/lager/

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	boost-libs>=0:devel/boost-libs \
		immer>=0:devel/immer \
		zug>=0:devel/zug

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	arximboldi

CMAKE_ON=	DISABLE_WERROR
CMAKE_OFF=	lager_BUILD_DOCS \
		lager_BUILD_EXAMPLES

NO_ARCH=	yes

OPTIONS_DEFINE=	TEST

TEST_BUILD_DEPENDS=	boost-libs>=0:devel/boost-libs \
			catch>=0:devel/catch \
			cereal>=0:devel/cereal \
			immer>=0:devel/immer \
			sdl2>=0:devel/sdl20 \
			sdl2_ttf>=0:graphics/sdl2_ttf \
			zug>=0:devel/zug
TEST_USES=		compiler:c++20-lang pkgconfig qt:5
TEST_USE=		QT=buildtools:build,concurrent:build,core:build,declarative:build,qmake:build
TEST_CMAKE_BOOL=	lager_BUILD_TESTS
TEST_ALL_TARGET=	install tests
TEST_ALL_TARGET_OFF=	install
TEST_TEST_TARGET=	test

.include <bsd.port.mk>
