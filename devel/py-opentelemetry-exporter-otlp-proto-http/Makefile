PORTNAME=	opentelemetry-exporter-otlp-proto-http
PORTVERSION=	1.35.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	opentelemetry_exporter_otlp_proto_http-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	OpenTelemetry Collector Protobuf over HTTP Exporter
WWW=		https://github.com/open-telemetry/opentelemetry-python/tree/main/exporter/opentelemetry-exporter-otlp-proto-http \
		https://github.com/open-telemetry/opentelemetry-python \
		https://opentelemetry.io/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}googleapis-common-protos>=1.52<2:devel/py-googleapis-common-protos@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}opentelemetry-api>=1.15<2:devel/py-opentelemetry-api@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}opentelemetry-exporter-otlp-proto-common>=${PORTVERSION}<${PORTVERSION}_99:devel/py-opentelemetry-exporter-otlp-proto-common@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}opentelemetry-proto>=${PORTVERSION}<${PORTVERSION}_99:devel/py-opentelemetry-proto@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}opentelemetry-sdk>=${PORTVERSION}<1.36:devel/py-opentelemetry-sdk@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.7<3:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.5.0:devel/py-typing-extensions@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
