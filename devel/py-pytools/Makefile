PORTNAME=	pytools
PORTVERSION=	2026.1
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Collection of tools for Python
WWW=		https://pypi.org/project/pytools/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}platformdirs>=2.2:devel/py-platformdirs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}siphash24>=1.6:security/py-siphash24@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.5:devel/py-typing-extensions@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}attrs>0:devel/py-attrs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}frozendict>0:devel/py-frozendict@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}immutabledict>0:devel/py-immutabledict@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}immutables>0:devel/py-immutables@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mako>0:textproc/py-mako@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>0:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyrsistent>0:devel/py-pyrsistent@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ruff>0:devel/py-ruff@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest

NO_ARCH=	yes

OPTIONS_DEFINE=	NUMPY

NUMPY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>0:math/py-numpy@${PY_FLAVOR}

.include <bsd.port.mk>
