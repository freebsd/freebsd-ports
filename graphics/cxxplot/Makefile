PORTNAME=	cxxplot
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.1
CATEGORIES=	graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ 2D plotting library
WWW=		https://github.com/USNavalResearchLaboratory/cxxplot

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/license.txt

USES=		cmake:testing compiler:c++20-lang gl qt:6
USE_QT=		base tools:build
USE_GL=		gl opengl

USE_GITHUB=	yes
GH_ACCOUNT=	USNavalResearchLaboratory

CMAKE_ON=		BUILD_SHARED_LIBS
CMAKE_TESTING_TARGET=

post-test: # 'make test' opens a lot of windows; 1 test fails, see https://github.com/USNavalResearchLaboratory/cxxplot/issues/10
.for name in 01_test 02_test 03_test 04_test 05_test 06_test_csv 07_test_image
	@${ECHO} "==> Running the test ${name}"
	@${TEST_WRKSRC}/tests/${name}/libcxxplot_${name:C/test_.*/test/}
.endfor

.include <bsd.port.mk>
