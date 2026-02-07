PORTNAME=	pytest-enabler
PORTVERSION=	3.4.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pytest_enabler-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Enable installed pytest plugins
WWW=		https://github.com/jaraco/pytest-enabler

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=3.4.1:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}jaraco.context>=0:devel/py-jaraco.context@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jaraco.functools>=0:devel/py-jaraco.functools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}toml>=0:textproc/py-toml@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-checkdocs>=2.4:devel/py-pytest-checkdocs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>=0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-mypy>=0:devel/py-pytest-mypy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-ruff>=0.2.1:devel/py-pytest-ruff@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}types-toml>=0:devel/py-types-toml@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 31200
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}importlib-resources>=5.10:devel/py-importlib-resources@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
