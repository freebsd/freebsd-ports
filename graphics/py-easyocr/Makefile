PORTNAME=	easyocr
DISTVERSIONPREFIX=	v
DISTVERSION=	1.7.2
CATEGORIES=	graphics python
#MASTER_SITES=	PYPI # no tarball
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	End-to-end multi-lingual Optical Character Recognition (OCR) solution
WWW=		https://github.com/jaidedai/easyocr

LICENSE=	GPLv3

USES=		python
USE_PYTHON=	distutils autoplist pytest

RUN_DEPENDS=	${PYNUMPY} \
		opencv>0:graphics/opencv \
		${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyclipper>0:math/py-pyclipper@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-bidi>0:textproc/py-python-bidi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytorch>0:misc/py-pytorch@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>0:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-image>=0:graphics/py-scikit-image@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}shapely>0:devel/py-shapely@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}torchvision>=0.5:misc/py-torchvision@${PY_FLAVOR} \

USE_GITHUB=	yes
GH_ACCOUNT=	jaidedai

WRKSRC=		${WRKDIR}/EasyOCR-${DISTVERSION}

NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

.include <bsd.port.mk>
