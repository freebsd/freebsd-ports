PORTNAME=	dbt-semantic-interfaces
DISTVERSION=	0.5.1
PORTREVISION=	1
CATEGORIES=	databases python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	dbt_semantic_interfaces-${PORTVERSION}

MAINTAINER=	pat@patmaddox.com
COMMENT=	Shared semantic layer definitions that dbt-core and MetricFlow use
WWW=		https://github.com/dbt-labs/dbt-semantic-interfaces

LICENSE=	APACHE20

BUILD_DEPENDS=	hatch:devel/py-hatch@${PY_FLAVOR} \
		hatchling:devel/py-hatchling@${PY_FLAVOR}

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pydantic>=1.10:devel/py-pydantic@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonschema>=4,<5:devel/py-jsonschema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=6,<7:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}more-itertools>=8,<11:devel/py-more-itertools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=3.1.3,<4:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>=7,<9:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dateutil>=2,<3:devel/py-python-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}importlib-metadata>=6:devel/py-importlib-metadata@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.4,<5:devel/py-typing-extensions@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
