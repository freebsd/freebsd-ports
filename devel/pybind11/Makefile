PORTNAME=	pybind11
DISTVERSIONPREFIX=	v
DISTVERSION=	2.13.3
CATEGORIES=	devel python

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Seamless interoperability between C++11 and Python (cmake part)
WWW=		https://pybind11.readthedocs.io/en/stable/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing compiler:c++11-lang python:build

USE_GITHUB=	yes
GH_ACCOUNT=	pybind

CMAKE_OFF=	PYBIND11_TEST

CMAKE_TESTING_ON=	PYBIND11_TEST # 6 tests are known to fail: https://github.com/pybind/pybind11/issues/4580
CMAKE_TESTING_TARGET=	pytest

NO_ARCH=	yes

.include <bsd.port.mk>
