PORTNAME=	PyOpenGL-accelerate
PORTVERSION=	3.1.7
CATEGORIES=	graphics python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	OpenGL acceleration code for PyOpenGL
WWW=		https://pyopengl.sourceforge.net/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/license.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=0,1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=42.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=0,1:math/py-numpy@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent cython pep517

CFLAGS=		-Wno-int-conversion

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
