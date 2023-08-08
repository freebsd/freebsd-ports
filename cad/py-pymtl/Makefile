PORTNAME=	pymtl
DISTVERSION=	3.1.15
CATEGORIES=	cad python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	${PORTVERSION:R:R}
DISTNAME=	${PORTNAME}${PORTVERSION:R:R}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python-based hardware generation, simulation, verification framework
WWW=		https://github.com/pymtl/pymtl3

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	\
		${PYTHON_PKGNAMEPREFIX}cffi>0:devel/py-cffi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}greenlet>0:devel/py-greenlet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hypothesis>=4.18.1:devel/py-hypothesis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}py>0:devel/py-py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}graphviz>0:graphics/py-graphviz@${PY_FLAVOR} \
		verilator:cad/verilator \
		yosys:cad/yosys

USES=		python
USE_PYTHON=	autoplist distutils pytest # 94 tests fail, see https://github.com/pymtl/pymtl3/issues/247

BINARY_ALIAS=	g++=${CXX}

NO_ARCH=	yes

.include <bsd.port.mk>
