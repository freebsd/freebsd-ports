PORTNAME=	rapidocr
DISTVERSIONPREFIX=	v
DISTVERSION=	3.9.2
CATEGORIES=	graphics python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	OCR toolkit using PaddleOCR models with ONNX Runtime
WWW=		https://github.com/RapidAI/RapidOCR

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC:H}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=8:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}colorlog>0:devel/py-colorlog@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.19.5:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}omegaconf>0:devel/py-omegaconf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyclipper>=1.2.0:math/py-pyclipper@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>0:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}shapely>=1.7.1:devel/py-shapely@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.15.0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>0:misc/py-tqdm@${PY_FLAVOR} \
		${PYTHON_SITELIBDIR}/cv2/__init__.py:graphics/opencv
# cv2 comes from graphics/opencv rather than from
# graphics/py-opencv-python-headless, which conflicts with it: the other
# consumer in this stack, misc/py-insightface, depends on graphics/opencv

USES=		python
USE_PYTHON=	autoplist pep517

USE_GITHUB=	yes
GH_ACCOUNT=	RapidAI
GH_PROJECT=	RapidOCR

WRKSRC_SUBDIR=	python

MAKE_ENV=	SETUPTOOLS_SCM_PRETEND_VERSION=${DISTVERSION}

NO_ARCH=	yes

.include <bsd.port.mk>
