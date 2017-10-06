# $FreeBSD$

PORTNAME=	skimage
PORTVERSION=	0.12.3
DISTNAME=	scikit-image
DISTVERSIONPREFIX=	v
CATEGORIES=	graphics python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Image Processing SciKit (Toolbox for SciPy)

BUILD_DEPENDS=  ${PYNUMPY} \
  ${LOCALBASE}/bin/cython:lang/cython \
  ${PYTHON_PKGNAMEPREFIX}six>=1.4:devel/py-six \
  ${PYTHON_PKGNAMEPREFIX}scipy>=0.9:science/py-scipy \
  ${PYTHON_PKGNAMEPREFIX}numpydoc>=0.6:textproc/py-numpydoc

RUN_DEPENDS=  ${BUILD_DEPENDS} \
  ${PYTHON_PKGNAMEPREFIX}pillow>=1.7:graphics/py-pillow \
  ${PYTHON_PKGNAMEPREFIX}networkx>=1.8:math/py-networkx \
  ${PYTHON_PKGNAMEPREFIX}matplotlib>=1.1:math/py-matplotlib \
  ${PYTHON_PKGNAMEPREFIX}PyWavelets>=0.4:math/py-PyWavelets

LICENSE=	BSD3CLAUSE
#LICENSE_NAME=	Modified BSD
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES?=		cpe python
USE_GITHUB=	yes
USE_PYTHON=	autoplist distutils

GH_ACCOUNT=	${DISTNAME}
GH_PROJECT=	${DISTNAME}

.include <bsd.port.pre.mk>

PYDISTUTILS_BUILD_TARGET=	build build_ext
PYDISTUTILS_BUILDARGS+=		saveopts

do-test:
	@cd ${WRKSRC} && \
	${PYTHON_CMD} ${PYSETUP} build_ext -i && \
	${PYTHON_CMD} selftest.py && \
	${PYTHON_CMD} -m nose -vx Tests/test_*.py

.include <bsd.port.post.mk>
