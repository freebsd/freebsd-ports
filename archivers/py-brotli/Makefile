PORTNAME=	brotli
PORTVERSION=	1.2.0
CATEGORIES=	archivers python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Generic-purpose lossless compression algorithm
WWW=		https://github.com/google/brotli

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	brotli>=${PORTVERSION},1<${PORTVERSION}_99,1:archivers/brotli \
		${PYTHON_PKGNAMEPREFIX}pkgconfig>=0:devel/py-pkgconfig@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
LIB_DEPENDS=	libbrotlicommon.so:archivers/brotli

USES=		cpe python
USE_PYTHON=	autoplist concurrent pep517

MAKE_ENV=	USE_SYSTEM_BROTLI=1

CPE_VENDOR=	google

post-patch:
	@${REINPLACE_CMD} -e 's|%%PORTVERSION%%|${PORTVERSION}|' ${WRKSRC}/setup.py
# Clean up bundled libraries
	@${RM} -r ${WRKSRC}/c/

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
