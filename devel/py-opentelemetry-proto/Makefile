PORTNAME=	opentelemetry-proto
PORTVERSION=	1.34.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	opentelemetry_proto-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	OpenTelemetry Python Proto
WWW=		https://github.com/open-telemetry/opentelemetry-python/tree/main/opentelemetry-proto \
		https://github.com/open-telemetry/opentelemetry-python \
		https://opentelemetry.io/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}protobuf>=5.0,1<6.0,1:devel/py-protobuf@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
