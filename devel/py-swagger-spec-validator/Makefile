PORTNAME=	swagger-spec-validator
DISTVERSIONPREFIX=	v
DISTVERSION=	2.7.3
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Validation of Swagger specifications

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}jsonschema>0:devel/py-jsonschema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock@${PY_FLAVOR}

USES=		python:3.6+
USE_GITHUB=	yes
GH_ACCOUNT=	Yelp
GH_PROJECT=	swagger_spec_validator
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

# Skip test "test_raise_SwaggerValidationError_on_urlopen_error" as it tries
# to open network connections to non-existent URLs.
do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} -m pytest -v -rs \
		-k 'not test_raise_SwaggerValidationError_on_urlopen_error'

.include <bsd.port.mk>
