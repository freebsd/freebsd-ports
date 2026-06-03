PORTNAME=	pybind11
DISTVERSIONPREFIX=	v
DISTVERSION=	3.0.4
CATEGORIES=	devel python

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Seamless interoperability between C++11 and Python (cmake part)
WWW=		https://pybind11.readthedocs.io/en/stable/ \
		https://github.com/pybind/pybind11

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	pytest:devel/py-pytest@${PY_FLAVOR}

USES=		cmake:testing compiler:c++11-lang python:build

USE_GITHUB=	yes
GH_ACCOUNT=	pybind

CMAKE_OFF=	PYBIND11_TEST
CMAKE_ARGS=	-Dprefix_for_pc_file=${PREFIX}

CMAKE_TESTING_ON=	PYBIND11_TEST # 6 tests are known to fail: https://github.com/pybind/pybind11/issues/4580
CMAKE_TESTING_TARGET=	pytest

NO_ARCH=	yes

# tests as of 3.0.4: 1291 passed, 27 skipped, 3 xfailed, 1 xpassed in 22.92s

.include <bsd.port.mk>
