PORTNAME=	flex
DISTVERSIONPREFIX=	v
DISTVERSION=	6.14.1
PORTREVISION=	1
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Swagger schema validation
WWW=		https://github.com/pipermerriam/flex

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Upstream is inactive since 6 years

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>=3.3:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonpointer>=1.7:devel/py-jsonpointer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.4.3:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rfc3987>=1.3.4:www/py-rfc3987@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.7.3:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}strict-rfc3339>=0.7:devel/py-strict-rfc3339@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}validate_email>=1.2:mail/py-validate_email@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=3.11:devel/py-pyyaml@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}factory-boy>=2.4.1:devel/py-factory-boy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-httpbin>=0.0.3:devel/py-pytest-httpbin@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}responses>=0.5.1:devel/py-responses@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	pipermerriam
USE_PYTHON=	autoplist concurrent distutils pytest
# See following links for more details:
# https://github.com/pipermerriam/flex/issues/234
# https://github.com/pipermerriam/flex/pull/236
PYTEST_BROKEN_TESTS=	test_request_parameter_array_extraction[tsv-1\t2\t3] \
			test_werkzeug

TEST_ENV=	PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

NO_ARCH=	yes

.include <bsd.port.mk>
