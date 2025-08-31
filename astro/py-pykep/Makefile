PORTNAME=	pykep
DISTVERSIONPREFIX=	v
DISTVERSION=	2.6.2
PORTREVISION=	6
CATEGORIES=	astro python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python binding for pykep, library for astrodynamics research
WWW=		https://github.com/esa/pykep

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libboost_serialization.so:devel/boost-libs \
		libkeplerian_toolbox.so:astro/pykep \
		${PY_BOOST}
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygmo2>0:science/py-pygmo2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR}

USES=		cmake compiler:c++11-lang python
USE_PYTHON=	flavors

CMAKE_OFF=	PYKEP_BUILD_KEP_TOOLBOX PYKEP_BUILD_TESTS
CMAKE_ON=	PYKEP_BUILD_PYKEP

USE_GITHUB=	yes
GH_ACCOUNT=	esa

.include <bsd.port.mk>
