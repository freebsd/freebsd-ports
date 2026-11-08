PORTNAME=	lensfunpy
DISTVERSIONPREFIX=	v
DISTVERSION=	1.18.0
CATEGORIES=	graphics python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Lens distortion correction for Python, a wrapper for lensfun
WWW=		https://github.com/letmaik/lensfunpy

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=2.0.0,1:math/py-numpy@${PY_FLAVOR} \
		${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
LIB_DEPENDS=	liblensfun.so:graphics/lensfun
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.26.0,1:math/py-numpy@${PY_FLAVOR}

USES=		pkgconfig python
USE_PYTHON=	autoplist concurrent cython pep517 pytest

USE_GITHUB=	yes
GH_ACCOUNT=	letmaik

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/test
TEST_ARGS=	--disable-plugin-autoload

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

# tests as of 1.18.0: 7 passed in 1.82s

.include <bsd.port.mk>
