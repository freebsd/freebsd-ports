PORTNAME=	audioread
PORTVERSION=	3.1.0
CATEGORIES=	audio python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Multi-library, cross-platform audio decoding
WWW=		https://github.com/beetbox/audioread

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=0:devel/py-poetry-core@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest

NO_ARCH=	yes

OPTIONS_MULTI=	BACKEND
OPTIONS_MULTI_BACKEND=	FFMPEG MAD
OPTIONS_DEFAULT=MAD
FFMPEG_DESC=	Use ffmpeg as backend
MAD_DESC=	Use pymad as backend

FFMPEG_RUN_DEPENDS=	ffmpeg:multimedia/ffmpeg
MAD_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pymad>=0.11.3<0.12.0:audio/py-pymad@${PY_FLAVOR}

.include <bsd.port.mk>
