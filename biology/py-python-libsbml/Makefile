PORTNAME=	python-libsbml
DISTVERSION=	5.21.1
CATEGORIES=	biology python
#MASTER_SITES=	PYPI # no tarballs on PYPI
MASTER_SITES=	https://github.com/sbmlteam/python-libsbml/releases/download/v${DISTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	LibSBML Python API
WWW=		https://sbml.org/Main_Page

LICENSE=	LGPL21

BUILD_DEPENDS=	cmake:devel/cmake-core \
		swig:devel/swig

USES=		python
USE_PYTHON=	autoplist distutils pytest # autoplist produces incomplete plist, missing files are in pkg-plist. Reported to the upstream author fbergman@caltech.edu on 2021-08-17

WRKSRC=		${WRKDIR}/python_libsbml-${DISTVERSION}

TEST_WRKSRC=	${WRKSRC}/libsbml_source/src/bindings/python

MAKE_ENV=	CMAKE_BUILD_PARALLEL_LEVEL=${MAKE_JOBS_NUMBER}

do-test:
	cd ${TEST_WRKSRC} && ${PYTHON_CMD} test.py -p ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/libsbml/_libsbml*.so

# tests as of 5.21.1: Ran 1819 tests in 0.078s

.include <bsd.port.mk>
