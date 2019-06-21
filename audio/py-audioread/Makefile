# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	audioread
PORTVERSION=	2.1.8
CATEGORIES=	audio python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Multi-library, cross-platform audio decoding

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-runner>=0:devel/py-pytest-runner@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_MULTI=	BACKEND
OPTIONS_MULTI_BACKEND=	FFMPEG PYMAD
OPTIONS_DEFAULT=PYMAD
FFMPEG_DESC=	Use ffmpeg as backend
PYMAD_DESC=	Use pymad as backend

FFMPEG_RUN_DEPENDS=	ffmpeg:multimedia/ffmpeg
PYMAD_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pymad>=0:audio/py-pymad@${PY_FLAVOR}

.include <bsd.port.mk>
