PORTNAME=	opentelemetry-instrumentation-django
PORTVERSION=	0.55b1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	opentelemetry_instrumentation_django-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	OpenTelemetry Instrumentation for Django
WWW=		https://github.com/open-telemetry/opentelemetry-python-contrib/tree/main/instrumentation/opentelemetry-instrumentation-django \
		https://github.com/open-telemetry/opentelemetry-python-contrib \
		https://opentelemetry.io/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}opentelemetry-api>=1.12<2:devel/py-opentelemetry-api@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}opentelemetry-instrumentation>=${PORTVERSION}<${PORTVERSION}_99:devel/py-opentelemetry-instrumentation@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}opentelemetry-instrumentation-wsgi>=${PORTVERSION}<${PORTVERSION}_99:devel/py-opentelemetry-instrumentation-wsgi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}opentelemetry-semantic-conventions>=${PORTVERSION}<${PORTVERSION}_99:devel/py-opentelemetry-semantic-conventions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}opentelemetry-util-http>=${PORTVERSION}<${PORTVERSION}_99:devel/py-opentelemetry-util-http@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	ASGI INSTRUMENTS
OPTIONS_DEFAULT=ASGI INSTRUMENTS
ASGI_DESC=		Asynchronous Server Gateway Interface support
INSTRUMENTS_DESC=	Instrumentation library

ASGI_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}opentelemetry-instrumentation-asgi>=${PORTVERSION}<${PORTVERSION}_99:devel/py-opentelemetry-instrumentation-asgi@${PY_FLAVOR}
INSTRUMENTS_RUN_DEPENDS=${PYTHON_PKGNAMEPREFIX}django42>=1.10:www/py-django42@${PY_FLAVOR}

.include <bsd.port.mk>
