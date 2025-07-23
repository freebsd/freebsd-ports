PORTNAME=	opentelemetry-instrumentation-wsgi
PORTVERSION=	0.56b0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	opentelemetry_instrumentation_wsgi-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	WSGI Middleware for OpenTelemetry
WWW=		https://github.com/open-telemetry/opentelemetry-python-contrib/tree/main/instrumentation/opentelemetry-instrumentation-wsgi \
		https://github.com/open-telemetry/opentelemetry-python-contrib \
		https://opentelemetry.io/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}opentelemetry-api>=1.12<2:devel/py-opentelemetry-api@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}opentelemetry-instrumentation>=${PORTVERSION}<${PORTVERSION}_99:devel/py-opentelemetry-instrumentation@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}opentelemetry-instrumentation-asgi>=${PORTVERSION}<${PORTVERSION}_99:devel/py-opentelemetry-instrumentation-asgi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}opentelemetry-semantic-conventions>=${PORTVERSION}<${PORTVERSION}_99:devel/py-opentelemetry-semantic-conventions@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	INSTRUMENTS
OPTIONS_DEFAULT=INSTRUMENTS
INSTRUMENTS_DESC=	Instrumentation library

INSTRUMENTS_RUN_DEPENDS=${PYTHON_PKGNAMEPREFIX}fastapi>=0.92<1:www/py-fastapi@${PY_FLAVOR}

.include <bsd.port.mk>
