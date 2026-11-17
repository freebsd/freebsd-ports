PORTNAME=	pyfaidx
DISTVERSION=	0.9.2.2
CATEGORIES=	biology python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Efficient pythonic random access to fasta subsequences
WWW=		https://github.com/mdshw5/pyfaidx

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=45:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=6.2:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}biopython>0:biology/py-biopython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>0:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 concurrent autoplist pytest

NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/tests
TEST_ARGS=	--disable-plugin-autoload
PYTEST_IGNORED_TESTS=	test_read_back_index # uses a Linux-only locale name

pre-test: # the tests need data files that are downloaded from NCBI and GitHub
	@cd ${WRKSRC}/tests/data && ${SETENV} ${PYTHON_CMD} download_gene_fasta.py

# tests as of 0.9.2.2: 289 passed, 8 skipped, 1 deselected, 31 xfailed in 10.12s (FastaVariant tests are skipped: PyVCF3 isn't packaged)

.include <bsd.port.mk>
