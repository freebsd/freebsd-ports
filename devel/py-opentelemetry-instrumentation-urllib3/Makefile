PORTNAME=	opentelemetry-instrumentation-urllib3
PORTVERSION=	0.56b0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	opentelemetry_instrumentation_urllib3-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	OpenTelemetry urllib3 instrumentation
WWW=		https://github.com/open-telemetry/opentelemetry-python-contrib/tree/main/instrumentation/opentelemetry-instrumentation-urllib3 \
		https://github.com/open-telemetry/opentelemetry-python-contrib \
		https://opentelemetry.io/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}opentelemetry-api>=1.12<2:devel/py-opentelemetry-api@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}opentelemetry-instrumentation>=${PORTVERSION}<${PORTVERSION}_99:devel/py-opentelemetry-instrumentation@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}opentelemetry-semantic-conventions>=${PORTVERSION}<${PORTVERSION}_99:devel/py-opentelemetry-semantic-conventions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}opentelemetry-util-http>=${PORTVERSION}<${PORTVERSION}_99:devel/py-opentelemetry-util-http@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wrapt>=1.0.0<2.0.0:devel/py-wrapt@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	INSTRUMENTS
OPTIONS_DEFAULT=INSTRUMENTS
INSTRUMENTS_DESC=	Instrumentation library

INSTRUMENTS_RUN_DEPENDS=${PYTHON_PKGNAMEPREFIX}urllib3>=1.0.0,1<3.0.0,1:net/py-urllib3@${PY_FLAVOR}

.include <bsd.port.mk>
