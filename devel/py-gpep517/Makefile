PORTNAME=	gpep517
DISTVERSION=	13
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Python package builder and installer for non-pip-centric world
WWW=		https://github.com/projg2/gpep517

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}installer>=0.5:devel/py-installer@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>=3.2:devel/py-flit-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pdm-pep517>0:devel/py-pdm-pep517@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}poetry-core>0:devel/py-poetry-core@${PY_FLAVOR} \
		${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	allflavors autoplist concurrent pep517 pytest

PEP517_BUILD_DEPEND=	${PYTHON_PKGNAMEPREFIX}flit-core>=3.2:devel/py-flit-core@${PY_FLAVOR}
PEP517_BUILD_CMD=	${PYTHON_CMD} -m flit_core.wheel

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 31100
BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}tomli>=1.2.3:textproc/py-tomli@${PY_FLAVOR}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}tomli>=1.2.3:textproc/py-tomli@${PY_FLAVOR}
.endif

post-patch:
	@${REINPLACE_CMD} '/requires-python/d' ${WRKSRC}/pyproject.toml

pre-test:
.for i in flit_core hatchling pdm.pep517 poetry.core setuptools-legacy setuptools
	@${LN} -s ${TEST_WRKSRC}/test/test-pkg/testpkg \
		${TEST_WRKSRC}/test/integration/${i}/testpkg
.endfor

post-test:
.for i in flit_core hatchling pdm.pep517 poetry.core setuptools-legacy setuptools
	@${RM} ${TEST_WRKSRC}/test/integration/${i}/testpkg
.endfor

.include <bsd.port.post.mk>
