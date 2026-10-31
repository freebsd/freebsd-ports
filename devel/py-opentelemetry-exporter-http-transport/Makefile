PORTNAME=	opentelemetry-exporter-http-transport
PORTVERSION=	0.66b0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	opentelemetry_exporter_http_transport-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	OpenTelemetry Exporters HTTP transport
WWW=		https://github.com/open-telemetry/opentelemetry-python/tree/main/exporter/opentelemetry-exporter-http-transport \
		https://github.com/open-telemetry/opentelemetry-python \
		https://opentelemetry.io/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}opentelemetry-api>=1.15<2:devel/py-opentelemetry-api@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	REQUESTS URLLIB3
OPTIONS_DEFAULT=URLLIB3
REQUESTS_DESC=	HTTP backend via requests
URLLIB3_DESC=	HTTP backend via urllib3

REQUESTS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=2.25<3:www/py-requests@${PY_FLAVOR}
URLLIB3_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}urllib3>=1.26,1:net/py-urllib3@${PY_FLAVOR}

.include <bsd.port.mk>
