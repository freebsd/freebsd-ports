PORTNAME=	openapi-schema-validator
PORTVERSION=	0.9.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	openapi_schema_validator-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	OpenAPI schema validation for Python
WWW=		https://github.com/python-openapi/openapi-schema-validator

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=1.0.0:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}jsonschema>=4.19.1<5:devel/py-jsonschema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonschema-specifications>=2024.10.1:devel/py-jsonschema-specifications@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>=2.0.0<3:devel/py-pydantic2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic-settings>=2.0.0<3:devel/py-pydantic-settings@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}referencing>=0.37.0<0.38:devel/py-referencing@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rfc3339-validator>=0:devel/py-rfc3339-validator@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	ECMA_REGEX
ECMA_REGEX_DESC=ECMA regular expressions support

ECMA_REGEX_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}regress>=2025.10.1:devel/py-regress@${PY_FLAVOR}

.include <bsd.port.mk>
