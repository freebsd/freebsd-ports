PORTNAME=	openapi-core
PORTVERSION=	0.19.4
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	openapi_core-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Client-side and server-side support for the OpenAPI Specification v3
WWW=		https://openapi-core.readthedocs.io/en/latest/ \
		https://github.com/python-openapi/openapi-core

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=1.0.0:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}isodate>=0:devel/py-isodate@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonschema>=4.18.0<5:devel/py-jsonschema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonschema-path>=0.3.1<0.4:devel/py-jsonschema-path@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonschema-spec>=0.2.3<0.3:devel/py-jsonschema-spec@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}more-itertools>=0:devel/py-more-itertools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openapi-schema-validator>=0.6.0<0.7:devel/py-openapi-schema-validator@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openapi-spec-validator>=0.7.1<0.8:devel/py-openapi-spec-validator@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}parse>=0:textproc/py-parse@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}werkzeug>=0:www/py-werkzeug@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	AIOHTTP DJANGO FALCON FASTAPI FLASK REQUESTS STARLETTE
AIOHTTP_DESC=	Async http support
DJANGO_DESC=	Django support
FASTAPI_DESC=	FastAPI support
FALCON_DESC=	Falcon support
FLASK_DESC=	Flask support
REQUESTS_DESC=	Requests support
STARLETTE_DESC=	Starlette support

AIOHTTP_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiohttp>=3.0:www/py-aiohttp@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}multidict>=6.0.4<7:www/py-multidict@${PY_FLAVOR}
DJANGO_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django42>=3.0:www/py-django42@${PY_FLAVOR}
FALCON_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}falcon>=3.0:www/py-falcon@${PY_FLAVOR}
FASTAPI_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}fastapi>=0.111<0.113:www/py-fastapi@${PY_FLAVOR}
FLASK_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flask>=0:www/py-flask@${PY_FLAVOR}
REQUESTS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR}
STARLETTE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aioitertools>=0.11.0<0.12:devel/py-aioitertools@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}starlette>=0.26.1<0.39.0:www/py-starlette@${PY_FLAVOR}

.include <bsd.port.mk>
