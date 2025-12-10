PORTNAME=	TonieToolbox
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.5
PORTREVISION=	1
CATEGORIES=	audio sysutils python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	TonieBox content management tool
WWW=		https://github.com/TonieToolbox/TonieToolbox \
		https://github.com/Quentendo64/TonieToolbox

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE.md

# get from pyproject.toml
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}protobuf>=0<=6.33.1,2:devel/py-protobuf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.32.5:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mutagen>=1.47.0:audio/py-mutagen@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=25.0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>=4.67.1:misc/py-tqdm@${PY_FLAVOR} \
		ffmpeg:multimedia/ffmpeg \
		opusenc:audio/opus-tools

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	Quentendo64
# Latest alpha version moved to another project, keep it here for later, we currently not use it, as it is marked to required python 3.12
#GH_ACCOUNT=	TonieToolbox
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
