PORTNAME=	hits
DISTVERSION=	0.5.1
CATEGORIES=	biology python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Utilities for processing high-throughput sequencing experiments
WWW=		https://github.com/jeffhussmann/hits

LICENSE=	GPLv3

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}biopython>=1.72:biology/py-biopython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}bokeh>0:www/py-bokeh@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ipython>=7.8.0:devel/ipython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ipywidgets>=7.4.2:devel/py-ipywidgets@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=3.0.2:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.15.4:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>=0.23.4:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=5.3.0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pysam>=0.15.1:biology/py-pysam@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=3.13:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}s3fs>=0:filesystems/py-s3fs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.2.1:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}seaborn>=0.11.0:math/py-seaborn@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}statsmodels>=0.12.1:math/py-statsmodels@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 cython autoplist pytest

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
PYTEST_ARGS=	-p no:ruff

do-test:
	@cd ${WRKDIR} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest ${PYTEST_ARGS} ${WRKSRC}/hits/test

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/hits/*.so

# tests as of 0.5.1: 11 passed, 1 skipped in 3.87s

.include <bsd.port.mk>
