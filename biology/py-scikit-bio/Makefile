PORTNAME=	scikit-bio
DISTVERSION=	0.6.3
PORTREVISION=	1
CATEGORIES=	biology education python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Data structures, algorithms, educational resources for bioinformatics
WWW=		http://scikit-bio.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BROKEN_aarch64=	fails to build: invalid conversion between vector type '__m64' (vector of 1 'long long' value) and integer type 'int' of different size, see https://github.com/biocore/scikit-bio/issues/1816
.if !exists(/usr/include/omp.h)
BROKEN=		requires OpenMP support that is missing on this architecture
.endif

BUILD_DEPENDS=	${PYNUMPY} \
		${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}biom-format>0:biology/py-biom-format@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}decorator>=3.4.2:devel/py-decorator@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}h5py>=3.6.0:science/py-h5py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hdmedians>=0.14.1:math/py-hdmedians@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ipython>=3.2.0:devel/ipython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=1.4.3:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}natsort>=4.0.3:devel/py-natsort@${PY_FLAVOR} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}pandas>=1.5.0:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.20.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-learn>=0.19.1:science/py-scikit-learn@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.9.0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}statsmodels>=0.14.0:math/py-statsmodels@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 cython autoplist pytest

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}ddtrace # lib/python3.8/site-packages/benchmarks/__init__.py

.include <bsd.port.options.mk>

.if ${ARCH} == i386
CFLAGS+=	-msse2 # workaround for https://github.com/biocore/scikit-bio/issues/1727
CXXFLAGS+=	-msse2
.endif

post-install:
	@${STRIP_CMD} \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/skbio/*/*${PYTHON_TAG}.so \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/skbio/*/*/*${PYTHON_TAG}.so

do-test: # tests fail to run in a regular way, see https://github.com/biocore/scikit-bio/issues/1846
	@cd ${STAGEDIR}${PYTHON_SITELIBDIR} && \
		${SETENV} ${TEST_ENV} pytest .

# tests as of 0.6.3: 2792 passed, 30 skipped, 56 warnings in 250.28s (0:04:10)

.include <bsd.port.mk>
