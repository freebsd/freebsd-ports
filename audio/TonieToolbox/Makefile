PORTNAME=	TonieToolbox
DISTVERSION=	0.6.5
CATEGORIES=	audio sysutils python
MASTER_SITES=	https://github.com/Quentendo64/${PORTNAME}/archive/refs/tags/v${DISTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	TonieBox content management tool
WWW=		https://github.com/Quentendo64/TonieToolbox

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE.md

# get from setup.py
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}protobuf>=0<=6.33.0,1:devel/py-protobuf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.32.5:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mutagen>=1.47.0:audio/py-mutagen@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=25.0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>=4.67.1:misc/py-tqdm@${PY_FLAVOR} \
		ffmpeg:multimedia/ffmpeg \
		opusenc:audio/opus-tools

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
