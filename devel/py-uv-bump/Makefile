PORTNAME=	uv-bump
DISTVERSION=	0.4.0
CATEGORIES=	devel python
#MASTER_SITES=	PYPI # no tests
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	UV: Bump pyproject.toml dependency minimum versions to latest feasible
WWW=		https://github.com/zundertj/uv-bump

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}uv-build>0:devel/py-uv-build@${PY_FLAVOR}
RUN_DEPENDS=	uv:devel/uv
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mypy>=1.18.2:devel/py-mypy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>=7.0.0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ruff>=0.13.2:devel/py-ruff@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist concurrent pytest

USE_GITHUB=	yes
GH_ACCOUNT=	zundertj

NO_ARCH=	yes

# tests as of 0.3.1: 8 functional tests passed (test_cli: 2/2, test_main: 6/6), 100% coverage, ~25s execution time

.include <bsd.port.mk>
