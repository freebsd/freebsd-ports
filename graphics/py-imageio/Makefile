PORTNAME=	imageio
PORTVERSION=	2.37.0
PORTREVISION=	1
CATEGORIES=	graphics python
MASTER_SITES=	PYPI \
		https://github.com/imageio/imageio/releases/download/v${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python library for reading and writing image, video formats
WWW=		https://imageio.readthedocs.io/en/stable/ \
		https://github.com/imageio/imageio

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
LIB_DEPENDS=	libfreeimage.so:graphics/freeimage
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=0,1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=8.3.2:graphics/py-pillow@${PY_FLAVOR}
TEST_DEPENDS=	opencv>=0:graphics/opencv \
		${PYTHON_PKGNAMEPREFIX}astropy>=0:astro/py-astropy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}av>=0:multimedia/py-av@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gdal>=0:graphics/py-gdal@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fsspec>=0:filesystems/py-fsspec@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>=0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tifffile>=0:graphics/py-tifffile@${PY_FLAVOR}
# filesystems/py-fsspec[github]
TEST_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR}

USES=		python:3.9+
USE_PYTHON=	autoplist concurrent pep517 pytest

NO_ARCH=	yes

OPTIONS_DEFINE=	FFMPEG FITS PILLOW_HEIF PYAV RAWPY TIFFFILE
OPTIONS_DEFAULT=FFMPEG
FFMPEG_DESC=		Read/Write video using FFmpeg
FITS_DESC=		Read FITS files
PILLOW_HEIF_DESC=	Read HEIF files
PYAV_DESC=		Read/Write video and image files
RAWPY_DESC=		Read/Write images via rawpy
TIFFFILE_DESC=		Read/Write TIFF files

FFMPEG_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}imageio-ffmpeg>=0:graphics/py-imageio-ffmpeg@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}psutil>=0:sysutils/py-psutil@${PY_FLAVOR}
FITS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}astropy>=0,2:astro/py-astropy@${PY_FLAVOR}
PILLOW_HEIF_RUN_DEPENDS=${PYTHON_PKGNAMEPREFIX}pillow-heif>=0:graphics/py-pillow-heif@${PY_FLAVOR}
PYAV_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}av>=0:multimedia/py-av@${PY_FLAVOR}
RAWPY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=0,1:math/py-numpy@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}rawpy>=0:graphics/py-rawpy@${PY_FLAVOR}
TIFFFILE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tifffile>=0:graphics/py-tifffile@${PY_FLAVOR}

.include <bsd.port.mk>
