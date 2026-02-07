PORTNAME=	soxr
DISTVERSION=	0.5.0
CATEGORIES=	audio python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	High quality, one-dimensional sample-rate conversion library
WWW=		https://github.com/dofuuz/python-soxr

LICENSE=	LGPL21 BSD3CLAUSE
LICENSE_COMB=	multi

BROKEN_i386=	fails to compile: ...requires target feature 'sse', but would be inlined into function 'h8' that is compiled without support for 'sse'

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		cmake:devel/cmake-core \
		${PYTHON_PKGNAMEPREFIX}nanobind>0:devel/py-nanobind@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-build-core>=0.9.0:devel/py-scikit-build-core@${PY_FLAVOR} \
		${PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYNUMPY}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

xpost-install:
	# strip binary
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/soxr/cysoxr${PYTHON_TAG}.so
	# correct version as a workaround for https://github.com/dofuuz/python-soxr/issues/21
	@${REINPLACE_CMD} -i '' -e 's|^version |__version__ |' ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/soxr/_version.py

.include <bsd.port.mk>
