PORTNAME=	imageio
PORTVERSION=	2.17.0
CATEGORIES=	graphics python
MASTER_SITES=	CHEESESHOP
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

OPTIONS_DEFINE=	FFMPEG
OPTIONS_DEFAULT=FFMPEG
FFMPEG_DESC=	Read/Write video using FFmpeg

FFMPEG_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}imageio-ffmpeg>=0:graphics/py-imageio-ffmpeg@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}psutil>=0:sysutils/py-psutil@${PY_FLAVOR}

.include <bsd.port.mk>
