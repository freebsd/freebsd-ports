PORTNAME=	curl-cffi
PORTVERSION=	0.14.0
CATEGORIES=	ftp python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/g}-${DISTVERSIONFULL}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	libcurl ffi bindings for Python
WWW=		https://curl-cffi.readthedocs.io/en/latest/ \
		https://github.com/lexiforest/curl_cffi

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>=1.12.0:devel/py-cffi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
LIB_DEPENDS=	libcurl-impersonate.so:ftp/curl-impersonate
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}certifi>=2024.2.2:security/py-certifi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cffi>=1.12.0:devel/py-cffi@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=8.1.1:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-asyncio>=0.23.6:devel/py-pytest-asyncio@${PY_FLAVOR}

USES=		python ssl
USE_PYTHON=	pep517 autoplist pytest

TEST_ENV=	PYTHONPATH=
TEST_WRKDIR=	${WRKSRC}/tests/unittest

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
