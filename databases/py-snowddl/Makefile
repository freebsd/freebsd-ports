PORTNAME=	snowddl
DISTVERSION=	0.58.2
CATEGORIES=	databases python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	pat@patmaddox.com
COMMENT=	Object management automation tool for Snowflake
WWW=		https://docs.snowddl.com/

LICENSE=	APACHE20

BUILD_DEPENDS=	${PY_DEPENDS} \
		${PY_SETUPTOOLS} \
		wheel-${PYTHON_VER}:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PY_DEPENDS}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

PY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}jsonschema>=4.18<5:devel/py-jsonschema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>=2.4<3:devel/py-pydantic2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=6.0<7:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}snowflake-connector-python>=3.0:databases/py-snowflake-connector-python@${PY_FLAVOR}

.include <bsd.port.mk>
