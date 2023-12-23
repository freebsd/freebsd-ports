PORTNAME=	apispec
DISTVERSION=	6.3.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	meka@tilda.center
COMMENT=	Pluggable API specification generator
WWW=		https://github.com/marshmallow-code/apispec

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}prance>0:devel/py-prance@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}marshmallow>0:devel/py-marshmallow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=3.10:devel/py-yaml@${PY_FLAVOR}

# tests_require = prance[osv]>=0.11
TEST_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}openapi-spec-validator>0:devel/py-openapi-spec-validator@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}prance>=0.11:devel/py-prance@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils pytest

TEST_ENV=	PYTHONPATH=${WRKSRC}/src

PYTEST_BROKEN_TESTS=	test_openapi_tools_validate_v2 \
			test_openapi_tools_validate_v3

NO_ARCH=	yes

.include <bsd.port.mk>
