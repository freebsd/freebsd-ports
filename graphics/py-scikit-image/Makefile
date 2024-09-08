PORTNAME=	scikit-image
PORTVERSION=	0.19.3
PORTREVISION=	3
DISTVERSIONPREFIX=	v
CATEGORIES=	graphics python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Image processing in Python
WWW=		https://scikit-image.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pythran>0:devel/py-pythran@${PY_FLAVOR}
RUN_DEPENDS=	${PYNUMPY} \
		${PY_PILLOW} \
		${PYTHON_PKGNAMEPREFIX}imageio>=2.4.1:graphics/py-imageio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tifffile>=2019.7.26:graphics/py-tifffile@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.4.1:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}networkx>=2.2:math/py-networkx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=1.1:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pywavelets>=1.5.0:math/py-pywavelets@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cloudpickle>=0.2.1:devel/py-cloudpickle@${PY_FLAVOR}

USES=		compiler:c++11-lang python shebangfix
USE_GITHUB=	yes
USE_PYTHON=	autoplist concurrent distutils cython cython_run

PYDISTUTILS_BUILD_TARGET=	build build_ext
PYDISTUTILS_BUILDARGS+=		saveopts
SHEBANG_FILES=	skimage/scripts/skivi

post-install:
	@${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR}/skimage -name "*.so" -exec ${STRIP_CMD} {} \;

do-test:
	@cd ${WRKSRC} && \
	${PYTHON_CMD} ${PYSETUP} build_ext -i && \
	${PYTHON_CMD} selftest.py && \
	${PYTHON_CMD} -m nose -vx Tests/test_*.py

.include <bsd.port.mk>
