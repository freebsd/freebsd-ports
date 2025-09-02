PORTNAME=	opentelemetry-semantic-conventions
PORTVERSION=	0.57b0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	opentelemetry_semantic_conventions-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	OpenTelemetry Semantic Conventions
WWW=		https://github.com/open-telemetry/opentelemetry-python/tree/main/opentelemetry-semantic-conventions \
		https://github.com/open-telemetry/opentelemetry-python \
		https://opentelemetry.io/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}opentelemetry-api>=1.36.${PORTVERSION:C|.*b||}<1.36.${PORTVERSION:C|.*b||}_99:devel/py-opentelemetry-api@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.5.0:devel/py-typing-extensions@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
