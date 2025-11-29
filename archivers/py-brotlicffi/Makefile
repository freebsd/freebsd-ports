PORTNAME=	brotlicffi
PORTVERSION=	1.2.0.0
CATEGORIES=	archivers python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python CFFI bindings to the Brotli library
WWW=		https://github.com/python-hyper/brotlicffi

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>=1.17.0:devel/py-cffi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
LIB_DEPENDS=	libbrotlienc.so:archivers/brotli
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>=1.17.0:devel/py-cffi@${PY_FLAVOR}

USES=		localbase python
USE_PYTHON=	autoplist concurrent pep517

MAKE_ENV=	USE_SHARED_BROTLI=1

post-patch:
# Clean up bundled libraries
	@${RM} -r ${WRKSRC}/libbrotli/

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
