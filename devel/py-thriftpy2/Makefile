PORTNAME=	thriftpy2
PORTVERSION=	0.6.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Pure python implementation of Apache Thrift
WWW=		https://thriftpy2.readthedocs.io/en/latest/ \
		https://github.com/Thriftpy/thriftpy2

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61:devel/py-setuptools@${PY_FLAVOR} \
		${PY_TOMLI} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ply>=3.4<4.0:devel/py-ply@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.15<2:devel/py-six@${PY_FLAVOR}

USES=		dos2unix python
USE_PYTHON=	autoplist concurrent cython pep517

OPTIONS_DEFINE=	AIOHTTP
AIOHTTP_DESC=	Asynchronous HTTP support

AIOHTTP_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiohttp>=3.8.0<4.0.0:www/py-aiohttp@${PY_FLAVOR}

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
