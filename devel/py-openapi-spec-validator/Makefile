PORTNAME=	openapi-spec-validator
PORTVERSION=	0.7.2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	openapi_spec_validator-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Validator for OpenAPI 2.0 and 3.0.0 specification
WWW=		https://github.com/python-openapi/openapi-spec-validator

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=1.0.0:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}jsonschema>=4.18.0<5:devel/py-jsonschema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonschema-path>=0.3.1<0.4:devel/py-jsonschema-path@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lazy-object-proxy>=1.7.1<2:devel/py-lazy-object-proxy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openapi-schema-validator>=0.6.0<0.7:devel/py-openapi-schema-validator@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mock>=0:devel/py-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>=0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-flake8>=0:devel/py-pytest-flake8@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tox>=0:devel/py-tox@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	REQUESTS
REQUESTS_DESC=	Requests support

REQUESTS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR}

.include <bsd.port.mk>
