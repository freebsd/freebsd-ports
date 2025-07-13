PORTNAME=	azure-core
PORTVERSION=	1.35.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	azure_core-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Microsoft Azure Core Library for Python
WWW=		https://github.com/Azure/azure-sdk-for-python/tree/main/sdk/core/azure-core \
		https://github.com/Azure/azure-sdk-for-python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=2.21.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.11.0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.6.0:devel/py-typing-extensions@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	AIO TRACING
OPTIONS_DEFAULT=AIO TRACING
AIO_DESC=	Async transport support
TRACING_DESC=	OpenTelemetry tracing support

AIO_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiohttp>=3.0:www/py-aiohttp@${PY_FLAVOR}
TRACING_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}opentelemetry-api>=1.26<2:devel/py-opentelemetry-api@${PY_FLAVOR}

.include <bsd.port.mk>
