PORTNAME=	audioread
PORTVERSION=	3.0.0
CATEGORIES=	audio python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Multi-library, cross-platform audio decoding
WWW=		https://github.com/beetbox/audioread

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python
USE_PYTHON=	autoplist concurrent distutils pytest

NO_ARCH=	yes

OPTIONS_MULTI=	BACKEND
OPTIONS_MULTI_BACKEND=	FFMPEG GSTREAMER PYMAD
OPTIONS_DEFAULT=PYMAD
FFMPEG_DESC=	Use ffmpeg as backend
GSTREAMER_DESC=	Use gstreamer as backend
PYMAD_DESC=	Use pymad as backend

FFMPEG_RUN_DEPENDS=	ffmpeg:multimedia/ffmpeg
GSTREAMER_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gobject3>=0:devel/py-gobject3@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}gstreamer1>=1.0:multimedia/py-gstreamer1@${PY_FLAVOR}
PYMAD_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pymad>=0:audio/py-pymad@${PY_FLAVOR}

.include <bsd.port.mk>
