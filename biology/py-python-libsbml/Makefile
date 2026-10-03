PORTNAME=	python-libsbml
DISTVERSION=	5.21.2
PORTREVISION=	1
CATEGORIES=	biology python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:C/[-_.]/_/g}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	LibSBML Python API
WWW=		https://sbml.org/Main_Page

LICENSE=	LGPL21

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR} \
		cmake:devel/cmake-core \
		swig:devel/swig

USES=		python
USE_PYTHON=	autoplist pep517 unittest

TEST_WRKSRC=	${WRKSRC}/libsbml_source/src/bindings/python

MAKE_ENV=	CMAKE_BUILD_PARALLEL_LEVEL=${MAKE_JOBS_NUMBER}

do-test:
	cd ${TEST_WRKSRC} && ${PYTHON_CMD} test.py -p ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/libsbml/_libsbml*.so

# tests as of 5.21.2: Ran 1819 tests in 0.078s

.include <bsd.port.mk>
