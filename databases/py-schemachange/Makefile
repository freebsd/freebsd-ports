PORTNAME=	schemachange
DISTVERSION=	3.6.1
PORTREVISION=	1
CATEGORIES=	databases python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	pat@patmaddox.com
COMMENT=	Database Change Management tool for Snowflake
WWW=		https://github.com/Snowflake-Labs/schemachange

LICENSE=	APACHE20

BUILD_DEPENDS=	${PY_DEPENDS} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=40.9.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

RUN_DEPENDS=	${PY_DEPENDS}

TEST_DEPENDS=	${PY_DEPENDS} \
		${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

PY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Jinja2>=3.0,<4:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>=1.3:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=6.0,<7:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}snowflake-connector-python>=2.8,<4:databases/py-snowflake-connector-python@${PY_FLAVOR}

do-test:
	@(cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest)

.include <bsd.port.mk>
