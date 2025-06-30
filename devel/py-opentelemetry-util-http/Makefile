PORTNAME=	opentelemetry-util-http
PORTVERSION=	0.55b1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	opentelemetry_util_http-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Web util for OpenTelemetry
WWW=		https://github.com/open-telemetry/opentelemetry-python-contrib/tree/main/util/opentelemetry-util-http \
		https://github.com/open-telemetry/opentelemetry-python-contrib \
		https://opentelemetry.io/

LICENSE=	APACHE20

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
