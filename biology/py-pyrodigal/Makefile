PORTNAME=	pyrodigal
DISTVERSION=	2.2.0
CATEGORIES=	biology python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python binding for Prodigal, an ORF finder for genomes and metagenomes
WWW=		https://github.com/althonos/pyrodigal

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}archspec>0:devel/py-archspec@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils cython concurrent autoplist pytest

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

post-build:
	@cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} setup.py build_ext --inplace

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/pyrodigal/_pyrodigal${PYTHON_EXT_SUFFIX}.so

do-test:
	@cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m unittest discover -vv

.include <bsd.port.mk>
