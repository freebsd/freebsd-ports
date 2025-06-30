PORTNAME=	opentelemetry-distro
PORTVERSION=	0.55b1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	opentelemetry_distro-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	OpenTelemetry Python Distro
WWW=		https://github.com/open-telemetry/opentelemetry-python-contrib/tree/main/opentelemetry-distro \
		https://github.com/open-telemetry/opentelemetry-python-contrib \
		https://opentelemetry.io/

LICENSE=	APACHE20

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}opentelemetry-api>=1.12<2:devel/py-opentelemetry-api@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}opentelemetry-instrumentation>=${PORTVERSION}<${PORTVERSION}_99:devel/py-opentelemetry-instrumentation@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}opentelemetry-sdk>=1.13<2:devel/py-opentelemetry-sdk@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	OTLP
OPTIONS_DEFAULT=OTLP
OTLP_DESC=	OpenTelemetry Protocol support

OTLP_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}opentelemetry-exporter-otlp>=1.34.1:devel/py-opentelemetry-exporter-otlp@${PY_FLAVOR}

.include <bsd.port.mk>
