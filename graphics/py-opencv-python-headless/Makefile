PORTNAME=	opencv-python-headless
DISTVERSION=	4.13.0.92
PORTREVISION=	2
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
		${PYTHON_PKGNAMEPREFIX}pip>0:devel/py-pip@${PY_FLAVOR} \
		cmake:devel/cmake
LIB_DEPENDS=	libavif.so:graphics/libavif \
		libwebp.so:graphics/webp \
		libpng16.so:graphics/png \
		libtiff.so:graphics/tiff \
		libopenjp2.so:graphics/openjpeg \
		libavcodec.so:multimedia/ffmpeg \
		libopenblas.so:math/openblas

USES=		gnome gstreamer jpeg python
USE_GNOME=	glib20
USE_GSTREAMER1=	yes
USE_PYTHON=	pep517 autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	opencv
GH_PROJECT=	opencv-python
GH_TAGNAME=	92
GH_TUPLE=	opencv:opencv:b4c5ec4042f097e2a5b386b9d413ec7333d0a184:opencv/opencv \
		opencv:opencv_contrib:d99ad2a188210cc35067c2e60076eed7c2442bc3:opencv_contrib/opencv_contrib

MAKE_ENV=	ENABLE_HEADLESS=1 \
		OPENCV_PYTHON_PACKAGE_NAME=opencv-python-headless

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/opencv/modules/python

CONFLICTS_INSTALL=	opencv # opencv has the same python bindings bundled in

post-patch:
	@${PRINTF} 'opencv_version = "${DISTVERSION}"\ncontrib = False\nheadless = True\nrolling = False\nci_build = False' \
		> ${WRKSRC}/cv2/version.py

.include <bsd.port.mk>
