PORTNAME=	jsonschema
DISTVERSION=	4.25.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	JSON Schema validation for Python
WWW=		https://github.com/Julian/jsonschema

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatch-fancy-pypi-readme>=0:devel/py-hatch-fancy-pypi-readme@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatch-vcs>=0:devel/py-hatch-vcs@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}attrs>=22.2.0:devel/py-attrs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonschema-specifications>=2023.03.6:devel/py-jsonschema-specifications@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}referencing>=0.28.4:devel/py-referencing@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rpds-py>=0.7.1:devel/py-rpds-py@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pip>=0:devel/py-pip@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest

TEST_ENV=	PYTHONPATH=${STAGEDIR}${PYTHON_SITELIBDIR}

CONFLICTS_INSTALL=	py*-jsonschema3 # bin/jsonschema

NO_ARCH=	yes

.include <bsd.port.mk>
