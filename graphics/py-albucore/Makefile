PORTNAME=	albucore
DISTVERSION=	0.3.5
CATEGORIES=	graphics python
#MASTER_SITES=	PYPI # no tests
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	High-performance image processing library
WWW=		https://github.com/albumentations-team/albucore

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numkong>=7.8.7:devel/py-numkong@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.24.4:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}opencv-python-headless>=5.0.0.93:graphics/py-opencv-python-headless@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytorch>=2.14.1:misc/py-pytorch@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}stringzilla>=5.3.2:devel/py-stringzilla@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hypothesis>=6.155.2:devel/py-hypothesis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=25.0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>=4.1.0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-mock>0:devel/py-pytest-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ruff>0:devel/py-ruff@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	albumentations-team

NO_ARCH=	yes

# importing torch fails with 'No space available for static Thread Local Storage' unless libc10 is preloaded
TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} \
		LD_PRELOAD=${PYTHON_SITELIBDIR}/torch/lib/libc10.so
# float16 arithmetic is not supported by OpenCV on FreeBSD/aarch64 (cv2 'func' assertions), cv2.resize of
# 4-channel uint8 images crashes with SIGTRAP (fractional_uint8_xy_scale), exp denormal and benchmark tooling tests fail
TEST_ARGS=	--disable-plugin-autoload -m 'not slow' \
		-k 'not float16 and not half and not fractional_uint8_xy_scale and not incomplete_output and not operand_workloads and not accepts_opencv_distribution and not special_values'

# tests as of 0.3.5: 5366 passed, 2 skipped, 2579 deselected, 98 warnings in 23.66s

.include <bsd.port.mk>
