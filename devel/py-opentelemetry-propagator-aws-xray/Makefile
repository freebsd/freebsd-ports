PORTNAME=	opentelemetry-propagator-aws-xray
PORTVERSION=	1.0.2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	opentelemetry_propagator_aws_xray-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	AWS X-Ray Propagator for OpenTelemetry
WWW=		https://github.com/open-telemetry/opentelemetry-python-contrib/tree/main/propagator/opentelemetry-propagator-aws-xray \
		https://github.com/open-telemetry/opentelemetry-python-contrib \
		https://opentelemetry.io/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}opentelemetry-api>=1.12<2:devel/py-opentelemetry-api@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
