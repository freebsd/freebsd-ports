PORTNAME=	ftxui
DISTVERSIONPREFIX=	v
DISTVERSION=	4.1.1
CATEGORIES=	devel science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ Functional Terminal User Interface library
WWW=		https://github.com/ArthurSonzogni/FTXUI

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	benchmark>0:devel/benchmark \
		googletest>0:devel/googletest

USES=		cmake:testing compiler:c++20-lang
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	ArthurSonzogni
GH_PROJECT=	FTXUI

CMAKE_OFF=	FTXUI_BUILD_DOCS FTXUI_BUILD_EXAMPLES FTXUI_BUILD_TESTS
CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_TESTING_ON=	FTXUI_BUILD_TESTS

.include <bsd.port.mk>
