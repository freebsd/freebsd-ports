PORTNAME=	pyrodigal
DISTVERSION=	3.6.3
CATEGORIES=	biology python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python binding for Prodigal, an ORF finder for genomes and metagenomes
WWW=		https://pyrodigal.readthedocs.io/en/stable/ \
		https://github.com/althonos/pyrodigal

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}scikit-build-core>0:devel/py-scikit-build-core@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}archspec>0:devel/py-archspec@${PY_FLAVOR}

USES=		cmake:indirect python
USE_PYTHON=	autoplist concurrent cython pep517 pytest

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

xpost-build:
	@cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} setup.py build_ext --inplace

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/pyrodigal/lib${PYTHON_TAG}.so

do-test: # as of 3.6.3 this doesn't work: https://github.com/althonos/pyrodigal/issues/63
	@cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m unittest discover -vv

.include <bsd.port.mk>
