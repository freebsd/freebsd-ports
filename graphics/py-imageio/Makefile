PORTNAME=	imageio
PORTVERSION=	2.20.0
CATEGORIES=	graphics python
MASTER_SITES=	CHEESESHOP \
		https://github.com/imageio/imageio/releases/download/v${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python library for reading and writing image, video formats

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfreeimage.so:graphics/freeimage
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=0,1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=8.3.2:graphics/py-pillow@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	FFMPEG FITS PYAV TIFFFILE
OPTIONS_DEFAULT=FFMPEG
FFMPEG_DESC=	Read/Write video using FFmpeg
FITS_DESC=	Read FITS files
PYAV_DESC=	Read/Write Videos (and images)
TIFFFILE_DESC=	Read/Write TIFF files

FFMPEG_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}imageio-ffmpeg>=0:graphics/py-imageio-ffmpeg@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}psutil>=0:sysutils/py-psutil@${PY_FLAVOR}
FITS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}astropy>=0,2:astro/py-astropy@${PY_FLAVOR}
PYAV_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}av>=0:multimedia/py-av@${PY_FLAVOR}
TIFFFILE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tifffile>=0:graphics/py-tifffile@${PY_FLAVOR}

.include <bsd.port.mk>
