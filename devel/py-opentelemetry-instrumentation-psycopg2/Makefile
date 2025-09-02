PORTNAME=	opentelemetry-instrumentation-psycopg2
PORTVERSION=	0.57b0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	opentelemetry_instrumentation_psycopg2-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	OpenTelemetry psycopg2 instrumentation
WWW=		https://github.com/open-telemetry/opentelemetry-python-contrib/tree/main/instrumentation/opentelemetry-instrumentation-psycopg2 \
		https://github.com/open-telemetry/opentelemetry-python-contrib \
		https://opentelemetry.io/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}opentelemetry-api>=1.12<2:devel/py-opentelemetry-api@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}opentelemetry-instrumentation>=${PORTVERSION}<${PORTVERSION}_99:devel/py-opentelemetry-instrumentation@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}opentelemetry-instrumentation-dbapi>=${PORTVERSION}<${PORTVERSION}_99:devel/py-opentelemetry-instrumentation-dbapi@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	INSTRUMENTS
OPTIONS_DEFAULT=INSTRUMENTS
INSTRUMENTS_DESC=	Instrumentation library

INSTRUMENTS_RUN_DEPENDS=${PYTHON_PKGNAMEPREFIX}psycopg2>=2.7.3.1:databases/py-psycopg2@${PY_FLAVOR}

.include <bsd.port.mk>
