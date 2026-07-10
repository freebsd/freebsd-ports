PORTNAME=	schemachange
DISTVERSION=	4.3.3
CATEGORIES=	databases python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	pat@patmaddox.com
COMMENT=	Database Change Management tool for Snowflake
WWW=		https://github.com/Snowflake-Labs/schemachange

LICENSE=	APACHE20

BUILD_DEPENDS=	${PY_DEPENDS} \
		${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}

RUN_DEPENDS=	${PY_DEPENDS}

TEST_DEPENDS=	${PY_DEPENDS} \
		${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR}

USES=		python:3.10+
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

PY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Jinja2>=3.0<4:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=6.0<7:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}snowflake-connector-python>=3.0<5:databases/py-snowflake-connector-python@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}structlog>=24.1.0<26:devel/py-structlog@${PY_FLAVOR}

do-test:
	@(cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest)

.include <bsd.port.mk>
