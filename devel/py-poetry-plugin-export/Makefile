PORTNAME=	poetry-plugin-export
DISTVERSION=	1.6.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/g}-${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Poetry plugin to export the dependencies to various formats
WWW=		https://python-poetry.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

PY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=1.7.0:devel/py-poetry-core@${PY_FLAVOR}
BUILD_DEPENDS=	${PY_DEPENDS}
RUN_DEPENDS=	${PY_DEPENDS}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mypy>=0.971:devel/py-mypy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}poetry>=1.5.0:devel/py-poetry@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-mock>0:devel/py-pytest-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-randomly>0:devel/py-pytest-randomly@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-xdist>0:devel/py-pytest-xdist@${PY_FLAVOR}
# devel/py-poetry is a circular dependency because poetry also depends on poetry-plugin-export. devel/py-poetry was moved to TEST_DEPENDS.

USES=		python
USE_PYTHON=	pep517 concurrent autoplist pytest # 1 test fails, see https://github.com/python-poetry/poetry-plugin-export/issues/218

NO_ARCH=	yes

.include <bsd.port.mk>
