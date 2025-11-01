PORTNAME=	pytest-benchmark
PORTVERSION=	5.1.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	pytest fixture for benchmarking code
WWW=		https://github.com/ionelmc/pytest-benchmark

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=30.3.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}py-cpuinfo>=0:sysutils/py-py-cpuinfo@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>=8.1,1:devel/py-pytest@${PY_FLAVOR}
TEST_DEPENDS=	git:devel/git \
		hg:devel/mercurial \
		${PYTHON_PKGNAMEPREFIX}aspectlib>=0:devel/py-aspectlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}elasticsearch>=0:textproc/py-elasticsearch@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}freezegun>=0:devel/py-freezegun@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-xdist>=0,1:devel/py-pytest-xdist@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest

NO_ARCH=	yes
TEST_ENV=	PYTHONPATH=${STAGEDIR}${PYTHON_SITELIBDIR}

OPTIONS_DEFINE=	ASPECT ELASTICSEARCH
ASPECT_DESC=	Aspect support
ELASTICSEARCH_DESC=	Elasticsearch support

ASPECT_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aspectlib>=0:devel/py-aspectlib@${PY_FLAVOR}
ELASTICSEARCH_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}elasticsearch>=0:textproc/py-elasticsearch@${PY_FLAVOR}

.include <bsd.port.mk>
