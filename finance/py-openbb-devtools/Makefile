PORTNAME=	openbb-devtools
DISTVERSION=	2.0.1
CATEGORIES=	finance python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/g}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	OpenBB: Development tools for OpenBB packages
WWW=		https://github.com/openbq-org/OpenBB

LICENSE=	AGPLv3

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}codespell>=2.2.5:textproc/py-codespell@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httpx2>=2.0.0:www/py-httpx2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ipykernel>=6.30.1:devel/py-ipykernel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydocstyle>=6.3.0:devel/py-pydocstyle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>=9.0.3:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-asyncio>=1.3.0:devel/py-pytest-asyncio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>=4.1.0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-freezer>=0.4.9:devel/py-pytest-freezer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-order>=1.3.0:devel/py-pytest-order@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-recorder>=1.0.0:devel/py-pytest-recorder@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-subtests>=0.11.0:devel/py-pytest-subtests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ruff>=0.15:devel/py-ruff@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tox>=4.11.3:devel/py-tox@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ty>=0.0.40:devel/py-ty@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}types-python-dateutil>=2.8.19.14:devel/py-types-python-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}types-requests>=2.32:devel/py-types-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}types-toml>=0.10.8.7:devel/py-types-toml@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
