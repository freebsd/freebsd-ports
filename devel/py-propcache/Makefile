PORTNAME=	propcache
PORTVERSION=	0.5.4
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Accelerated property cache
WWW=		https://propcache.aio-libs.org/en/latest/ \
		https://github.com/aio-libs/propcache

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}expandvars>0:devel/py-expandvars@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PY_TOMLI} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-benchmark>0:devel/py-pytest-benchmark@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent cython pep517 pytest

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_ARGS=	--disable-plugin-autoload -p benchmark

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

# tests as of 0.5.4: 61 passed in 4.34s

.include <bsd.port.mk>
