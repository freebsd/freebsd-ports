PORTNAME=	opentelemetry-instrumentation-tornado
PORTVERSION=	0.66b0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	opentelemetry_instrumentation_tornado-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Tornado instrumentation for OpenTelemetry
WWW=		https://github.com/open-telemetry/opentelemetry-python-contrib/tree/main/instrumentation/opentelemetry-instrumentation-tornado \
		https://github.com/open-telemetry/opentelemetry-python-contrib \
		https://opentelemetry.io/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}opentelemetry-api>=1.12<2:devel/py-opentelemetry-api@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}opentelemetry-instrumentation>=${PORTVERSION}<${PORTVERSION}_99:devel/py-opentelemetry-instrumentation@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}opentelemetry-semantic-conventions>=${PORTVERSION}<${PORTVERSION}_99:devel/py-opentelemetry-semantic-conventions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}opentelemetry-util-http>=${PORTVERSION}<${PORTVERSION}_99:devel/py-opentelemetry-util-http@${PY_FLAVOR}
 
USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	INSTRUMENTS
OPTIONS_DEFAULT=INSTRUMENTS
INSTRUMENTS_DESC=	Instrumentation library

INSTRUMENTS_RUN_DEPENDS=${PYTHON_PKGNAMEPREFIX}tornado>=5.1.1:www/py-tornado@${PY_FLAVOR}

.include <bsd.port.mk>
