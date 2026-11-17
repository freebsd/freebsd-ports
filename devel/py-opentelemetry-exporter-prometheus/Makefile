PORTNAME=	opentelemetry-exporter-prometheus
DISTVERSION=	0.66b2
CATEGORIES=	devel python
MASTER_SITES=	PYPI # this doesn't work somehow
#MASTER_SITES=	https://files.pythonhosted.org/packages/97/b3/f778f705289ea5f1c54589ae4494d318c9cede052f18ca33979fda0ef016/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/g}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Prometheus Metric Exporter for OpenTelemetry
WWW=		https://github.com/open-telemetry/opentelemetry-python/tree/main/exporter/opentelemetry-exporter-prometheus

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}opentelemetry-api>=1.12:devel/py-opentelemetry-api@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}opentelemetry-sdk>=1.45.2:devel/py-opentelemetry-sdk@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}prometheus-client>=0.5.0:net-mgmt/py-prometheus-client@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}opentelemetry-test-utils>=0.66b2:devel/py-opentelemetry-test-utils@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest

NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_ARGS=	--disable-plugin-autoload

# tests as of 0.66b2: 38 passed in 0.10s

.include <bsd.port.mk>
