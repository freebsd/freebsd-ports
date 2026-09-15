PORTNAME=	opencv-python-headless
DISTVERSION=	5.0.0.93
CATEGORIES=	graphics
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Wrapper package for OpenCV python bindings
WWW=		https://github.com/opencv/opencv-python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}scikit-build>=0.14.0:devel/py-scikit-build@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>0:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pip>0:devel/py-pip@${PY_FLAVOR}
LIB_DEPENDS=	libavif.so:graphics/libavif \
		libwebp.so:graphics/webp \
		libpng16.so:graphics/png \
		libtiff.so:graphics/tiff \
		libopenjp2.so:graphics/openjpeg \
		libavcodec.so:multimedia/ffmpeg \
		libopenblas.so:math/openblas

USES=		cmake:indirect gnome gstreamer jpeg python
USE_GNOME=	glib20
USE_GSTREAMER1=	yes
USE_PYTHON=	pep517 autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	opencv
GH_PROJECT=	opencv-python
GH_TAGNAME=	93
GH_TUPLE=	opencv:opencv:0654a42e19215ef25b1d367d822f3c630447e7c7:opencv/opencv \
		opencv:opencv_contrib:a8e9acd62cabd30419dba83007f2ac0d07de5e2c:opencv_contrib/opencv_contrib \
		opencv:ade:v0.1.2e:ade \
		opencv:opencv_extra:4.14.0:opencv_extra

post-extract:
	@${MKDIR} ${WRKSRC}/opencv/3rdparty/ade
	@${MV} ${WRKSRC_ade} ${WRKSRC}/opencv/3rdparty/ade

MAKE_ENV=	ENABLE_HEADLESS=1 \
		OPENCV_PYTHON_PACKAGE_NAME=opencv-python-headless

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} \
		OPENCV_TEST_REPO_PATH=${WRKSRC}/opencv \
		OPENCV_TEST_DATA_PATH=${WRKSRC_opencv_extra}/testdata
TEST_WRKSRC=	${WRKSRC}/opencv/modules/python
TEST_ARGS=	--disable-plugin-autoload

CONFLICTS_INSTALL=	opencv # opencv has the same python bindings bundled in

post-patch:
	@${PRINTF} 'opencv_version = "${DISTVERSION}"\ncontrib = False\nheadless = True\nrolling = False\nci_build = False' \
		> ${WRKSRC}/cv2/version.py

# tests as of 5.0.0.93: 129 passed, 9 skipped, 2 warnings in 1.96s

.include <bsd.port.mk>
