# $FreeBSD$

PORTNAME=	scikit-image
PORTVERSION=	0.13.1
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	graphics python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	eric@camachat.org
COMMENT=	Image Processing SciKit (Toolbox for SciPy)

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}six>=1.4:devel/py-six@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=0.9:science/py-scipy@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpydoc>=0.6:textproc/py-numpydoc@${FLAVOR}
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}six>=1.4:devel/py-six@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=0.9:science/py-scipy@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpydoc>=0.6:textproc/py-numpydoc@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=1.7:graphics/py-pillow@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}networkx>=1.8:math/py-networkx@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=1.1:math/py-matplotlib@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}PyWavelets>=0.4:math/py-PyWavelets@${FLAVOR}

USES=		cpe python:2.7
USE_GITHUB=	yes
USE_PYTHON=	autoplist distutils cython cython_run

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
