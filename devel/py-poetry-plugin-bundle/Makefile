PORTNAME=	poetry-plugin-bundle
PORTVERSION=	1.8.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI \
		https://github.com/python-poetry/poetry-plugin-bundle/releases/download/${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	poetry_plugin_bundle-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Poetry plugin to bundle projects into various formats
WWW=		https://python-poetry.org/ \
		https://github.com/python-poetry/poetry-plugin-bundle

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=2.0:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry>=2.1.0<3.0.0:devel/py-poetry@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}coverage>=7.2.0:devel/py-coverage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-mock>=3.6.1:devel/py-pytest-mock@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest

BINARY_ALIAS=	python=${PYTHON_CMD}
NO_ARCH=	yes
TEST_ENV=	PYTHONPATH=${STAGEDIR}${PYTHON_SITELIBDIR}

.include <bsd.port.mk>
