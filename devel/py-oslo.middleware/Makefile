PORTNAME=	oslo.middleware
PORTVERSION=	8.2.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	oslo_middleware-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Oslo Middleware library
WWW=		https://docs.openstack.org/oslo.middleware/latest/ \
		https://github.com/openstack/oslo.middleware

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=6.1.1:devel/py-pbr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}bcrypt>=3.1.3:security/py-bcrypt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=2.10:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.config>=5.2.0:devel/py-oslo.config@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.context>=2.19.2:devel/py-oslo.context@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.i18n>=3.15.3:devel/py-oslo.i18n@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.utils>=3.33.0:devel/py-oslo.utils@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}statsd>=3.2.1:devel/py-statsd@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}stevedore>=5.6.0:devel/py-stevedore@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.11.0:devel/py-typing-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}webob>=1.8.0:www/py-webob@${PY_FLAVOR}

USES=		python:3.11+
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	TRACING_GRPC TRACING_HTTP
TRACING_GRPC_DESC=	OpenTelemetry HTTP tracing middleware
TRACING_HTTP_DESC=	OpenTelemetry gRPC tracing middleware

TRACING_GRPC_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}opentelemetry-exporter-otlp-proto-grpc>=1.0.0:devel/py-opentelemetry-exporter-otlp-proto-grpc@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}opentelemetry-sdk>=1.0.0:devel/py-opentelemetry-sdk@${PY_FLAVOR}
TRACING_HTTP_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}opentelemetry-exporter-otlp-proto-http>=1.0.0:devel/py-opentelemetry-exporter-otlp-proto-http@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}opentelemetry-sdk>=1.0.0:devel/py-opentelemetry-sdk@${PY_FLAVOR}

.include <bsd.port.mk>
