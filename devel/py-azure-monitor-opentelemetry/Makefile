PORTNAME=	azure-monitor-opentelemetry
PORTVERSION=	1.8.8
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	azure_monitor_opentelemetry-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Microsoft Azure Monitor Opentelemetry Distro Client Library for Python
WWW=		https://github.com/Azure/azure-sdk-for-python/tree/main/sdk/monitor/azure-monitor-opentelemetry \
		https://github.com/Azure/azure-sdk-for-python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}azure-core>=1.28.0<2.0.0:devel/py-azure-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-core-tracing-opentelemetry>=1.0.0b11<1.1:devel/py-azure-core-tracing-opentelemetry@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-monitor-opentelemetry-exporter>=1.0.0b52<1.1:devel/py-azure-monitor-opentelemetry-exporter@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}opentelemetry-instrumentation-django>=0.61b0:devel/py-opentelemetry-instrumentation-django@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}opentelemetry-instrumentation-fastapi>=0.61b0:devel/py-opentelemetry-instrumentation-fastapi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}opentelemetry-instrumentation-flask>=0.61b0:devel/py-opentelemetry-instrumentation-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}opentelemetry-instrumentation-psycopg2>=0.61b0:devel/py-opentelemetry-instrumentation-psycopg2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}opentelemetry-instrumentation-requests>=0.61b0:devel/py-opentelemetry-instrumentation-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}opentelemetry-instrumentation-urllib>=0.61b0:devel/py-opentelemetry-instrumentation-urllib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}opentelemetry-instrumentation-urllib3>=0.61b0:devel/py-opentelemetry-instrumentation-urllib3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}opentelemetry-resource-detector-azure>=0.1.5<1.0.0:devel/py-opentelemetry-resource-detector-azure@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}opentelemetry-sdk>=1.40:devel/py-opentelemetry-sdk@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
