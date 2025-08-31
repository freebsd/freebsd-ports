PORTNAME=	matplotlib-cpp
PORTVERSION=	g20210422
PORTREVISION=	2
CATEGORIES=	graphics devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Header-only C++ plotting library built on the popular matplotlib
WWW=		https://github.com/lava/matplotlib-cpp

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR} \
		${PYNUMPY}

USES=		cmake:testing compiler:c++17-lang python

USE_GITHUB=	yes
GH_ACCOUNT=	lava
GH_TAGNAME=	ef0383f

CMAKE_TESTING_ON=	FREEBSD_BUILD_EXAMPLES
CMAKE_TESTING_TARGET=	${ALL_TARGET}

NO_ARCH=	yes

PLIST_FILES=	include/matplotlibcpp.h \
		lib/matplotlib_cpp/cmake/matplotlib_cppConfig.cmake \
		lib/matplotlib_cpp/cmake/matplotlib_cppTargets.cmake

.include <bsd.port.mk>
