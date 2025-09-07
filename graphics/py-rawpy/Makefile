PORTNAME=	rawpy
PORTVERSION=	0.25.1
DISTVERSIONPREFIX=	v
CATEGORIES=	graphics python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	RAW image processing for Python, a wrapper for libraw
WWW=		https://github.com/letmaik/rawpy

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=0,1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
LIB_DEPENDS=	libraw.so:graphics/libraw
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.26.0,1:math/py-numpy@${PY_FLAVOR}

USES=		pkgconfig python
USE_PYTHON=	autoplist concurrent cython pep517

MAKE_ENV=	RAWPY_USE_SYSTEM_LIBRAW=1

USE_GITHUB=	yes
GH_ACCOUNT=	letmaik

post-patch:
# Clean up bundled libraries
	@${RM} -r ${WRKSRC}/external/

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
