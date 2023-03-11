PORTNAME=	cxxplot
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.2
CATEGORIES=	graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ 2D plotting library
WWW=		https://github.com/USNavalResearchLaboratory/cxxplot

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/license.txt

# XXX Drop after FreeBSD 12.3 EOL around 2023-03-31
.if exists(/usr/include/c++/v1) && !exists(/usr/include/c++/v1/concepts)
BROKEN_FreeBSD_12=	build error: 'concepts' file not found
.endif

USES=		cmake:testing compiler:c++20-lang gl qt:6
USE_QT=		base tools:build
USE_GL=		gl opengl

USE_GITHUB=	yes
GH_ACCOUNT=	USNavalResearchLaboratory

CMAKE_ON=		BUILD_SHARED_LIBS
CMAKE_TESTING_TARGET=

post-test: # 'make test' opens a lot of windows
.for name in 01_test 02_test 03_test 04_test 05_test 06_test_csv 07_test_image
	@${ECHO} "==> Running the test ${name}"
	@${TEST_WRKSRC}/tests/${name}/libcxxplot_${name:C/test_.*/test/}
.endfor

.include <bsd.port.mk>
