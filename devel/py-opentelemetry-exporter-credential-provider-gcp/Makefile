PORTNAME=	opentelemetry-exporter-credential-provider-gcp
PORTVERSION=	0.60b0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	opentelemetry_exporter_credential_provider_gcp-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	GCP OTLP Exporter Credential Provider for OpenTelemetry
WWW=		https://github.com/open-telemetry/opentelemetry-python-contrib/tree/main/exporter/opentelemetry-exporter-credential-provider-gcp \
		https://github.com/open-telemetry/opentelemetry-python-contrib \
		https://opentelemetry.io/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}google-auth>=2.25:security/py-google-auth@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}grpcio>=1.67.0:devel/py-grpcio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.7:www/py-requests@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
