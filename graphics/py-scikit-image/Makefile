# $FreeBSD$

PORTNAME=	scikit-image
PORTVERSION=	0.13.0
DISTVERSIONPREFIX=	v
CATEGORIES=	graphics python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	eric@camachat.org
COMMENT=	Image Processing SciKit (Toolbox for SciPy)

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BROKEN=		fails to configure

BUILD_DEPENDS=	${PYNUMPY} \
		${LOCALBASE}/bin/cython:lang/cython \
		${PYTHON_PKGNAMEPREFIX}six>=1.4:devel/py-six \
		${PYTHON_PKGNAMEPREFIX}scipy>=0.9:science/py-scipy \
		${PYTHON_PKGNAMEPREFIX}numpydoc>=0.6:textproc/py-numpydoc
RUN_DEPENDS=	${PYNUMPY} \
		${LOCALBASE}/bin/cython:lang/cython \
		${PYTHON_PKGNAMEPREFIX}six>=1.4:devel/py-six \
		${PYTHON_PKGNAMEPREFIX}scipy>=0.9:science/py-scipy \
		${PYTHON_PKGNAMEPREFIX}numpydoc>=0.6:textproc/py-numpydoc \
		${PYTHON_PKGNAMEPREFIX}pillow>=1.7:graphics/py-pillow \
		${PYTHON_PKGNAMEPREFIX}networkx>=1.8:math/py-networkx \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=1.1:math/py-matplotlib \
		${PYTHON_PKGNAMEPREFIX}PyWavelets>=0.4:math/py-PyWavelets

USES=		cpe python
USE_GITHUB=	yes
USE_PYTHON=	autoplist distutils

PYDISTUTILS_BUILD_TARGET=	build build_ext
PYDISTUTILS_BUILDARGS+=		saveopts

post-install:
	@${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR}/skimage -name "*.so" -exec ${STRIP_CMD} {} \;

do-test:
	@cd ${WRKSRC} && \
	${PYTHON_CMD} ${PYSETUP} build_ext -i && \
	${PYTHON_CMD} selftest.py && \
	${PYTHON_CMD} -m nose -vx Tests/test_*.py

.include <bsd.port.mk>
