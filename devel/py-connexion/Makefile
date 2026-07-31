PORTNAME=	connexion
DISTVERSION=	3.3.0
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Connexion: API first applications with OpenAPI/Swagger
WWW=		https://connexion.readthedocs.io/en/latest/ \
		https://github.com/spec-first/connexion

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>0:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Jinja2>=3.0.0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}asgiref>=3.4:www/py-asgiref@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httpx>=0.23:www/py-httpx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}inflection>=0.3.1:devel/py-inflection@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonschema>=4.17.3:devel/py-jsonschema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-multipart>=0.0.15:www/py-python-multipart@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.27:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}starlette>=0.35:www/py-starlette@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.6.1:devel/py-typing-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}werkzeug>=2.2.1:www/py-werkzeug@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=5.1:devel/py-pyyaml@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-asyncio>=0.18.3:devel/py-pytest-asyncio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>=2.12.1:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}a2wsgi>=1.7:www/py-a2wsgi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flask>=2.2:www/py-flask@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	spec-first
GH_TAGNAME=	3.3.0

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}:${WRKSRC}
TEST_ARGS=	-p no:aiomisc -p no:relaxed \
		--ignore=tests/api/test_bootstrap.py \
		--ignore=tests/api/test_responses.py \
		--ignore=tests/test_mock.py \
		--ignore=tests/test_mock2.py

NO_ARCH=	yes

# tests as of 3.3.0: 611 passed, 1 warning

.include <bsd.port.mk>
