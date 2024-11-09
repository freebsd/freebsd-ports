PORTNAME=	blosc
PORTVERSION=	1.11.2
CATEGORIES=	archivers python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Blosc data compressor
WWW=		https://www.blosc.org/python-blosc/python-blosc.html \
		https://github.com/Blosc/python-blosc

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}py-cpuinfo>=0:sysutils/py-py-cpuinfo@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-build>=0:devel/py-scikit-build@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
LIB_DEPENDS=	libblosc.so:archivers/c-blosc

USES=		cmake:indirect python
USE_PYTHON=	autoplist concurrent pep517

MAKE_ENV=	USE_SYSTEM_BLOSC=1

post-patch:
# Clean up bundled libraries
	@${RM} -r ${WRKSRC}/blosc/c-blosc/

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
