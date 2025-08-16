PORTNAME=	strawberry-graphql
DISTVERSION=	0.278.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}dj51-
DISTNAME=	strawberry_graphql-${DISTVERSION}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Library for creating GraphQL APIs
WWW=		https://github.com/strawberry-graphql/strawberry

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=1.6:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}graphql-core>=3.2.0<3.4.0:devel/py-graphql-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lia-web>=0.2.1:www/py-lia-web@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=23:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dateutil>=2.7.0:devel/py-python-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.5.0:devel/py-typing-extensions@${PY_FLAVOR}

USES=		python:3.10+
USE_PYTHON=	autoplist concurrent pep517

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}*${PORTNAME}

NO_ARCH=	yes

OPTIONS_DEFINE=		AIOHTTP ASGI CHANNELS CLI DEBUG DEBUG-SERVER DJANGO \
			FASTAPI FLASK OPENTELEMETRY PYDANTIC

AIOHTTP_DESC=		Basic AIOHTTP integration
ASGI_DESC=		Basic ASGI integration
CHANNELS_DESC=		Support for Django Channels
CLI_DESC=		Support for CLI commands
DEBUG-SERVER_DESC=	Enable debug server
DEBUG_DESC=		Generate verbose debug information
DJANGO_DESC=		Basic Django integration
FASTAPI_DESC=		Support for FastAPI in conjunction with GraphQLRouter
FLASK_DESC=		Basic Flask integration
OPENTELEMETRY_DESC=	Generate Open Telemetry compatible tracing information
PYDANTIC_DESC=		Support for Pydantic models

AIOHTTP_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}aiohttp>=3.7.4<4:www/py-aiohttp@${PY_FLAVOR}
ASGI_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}multipart>=0.0.7:devel/py-multipart@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}starlette>=0.18.0:www/py-starlette@${PY_FLAVOR}
CHANNELS_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}asgiref>=3.2<4:www/py-asgiref@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}dj51-channels>=3.0.5:www/py-dj51-channels@${PY_FLAVOR}
CLI_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}libcst>0:devel/py-libcst@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}pygments>=2.3<3:textproc/py-pygments@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}rich>=12.0.0:textproc/py-rich@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}typer>=0.7.0:devel/py-typer@${PY_FLAVOR}
DEBUG-SERVER_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}libcst>0:devel/py-libcst@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}multipart>=0.0.7:devel/py-multipart@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}pygments>=2.3<3:textproc/py-pygments@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}rich>=12.0.0:textproc/py-rich@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}starlette>=0.18.0:www/py-starlette@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}typer>=0.7.0:devel/py-typer@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}uvicorn>=0.11.6:www/py-uvicorn@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}websockets>=15.0.1<16:devel/py-websockets@${PY_FLAVOR}
DEBUG_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}libcst>0:devel/py-libcst@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}rich>=12.0.0:textproc/py-rich@${PY_FLAVOR}
# NB: www/py-channels (via CHANNELS) options depends on www/py-djangoXX, which
# should be taken into account when creating a port for a specific Django version.
DJANGO_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}asgiref>=3.2:www/py-asgiref@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}django51>=3.2:www/py-django51@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}pytest-django>0:devel/py-pytest-django@${PY_FLAVOR}
FASTAPI_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}fastapi>=0.62.5:www/py-fastapi@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}multipart>=0.0.7:devel/py-multipart@${PY_FLAVOR}
FLASK_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}flask>=1.1:www/py-flask@${PY_FLAVOR}
OPENTELEMETRY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}opentelemetry-api<2:devel/py-opentelemetry-api@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}opentelemetry-sdk<2:devel/py-opentelemetry-sdk@${PY_FLAVOR}
# NB: Switch to devel/py-pydantic once www/py-fastapi uses it
PYDANTIC_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}pydantic2>1.6.1:devel/py-pydantic2@${PY_FLAVOR}

.include <bsd.port.mk>
