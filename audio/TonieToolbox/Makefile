PORTNAME=	TonieToolbox
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.0a2
CATEGORIES=	audio sysutils python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	TonieBox content management tool
WWW=		https://github.com/TonieToolbox/TonieToolbox

LICENSE=	GPL-3.0-or-later
LICENSE_FILE=	${WRKSRC}/LICENSE.md

# get from pyproject.toml
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}protobuf>=0<=6.33.0,2:devel/py-protobuf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.32.5:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mutagen>=1.47.0:audio/py-mutagen@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=25.0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>=4.67.1:misc/py-tqdm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}aiofiles>=25.1.0:devel/py-aiofiles@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}aiohttp>=3.13.2:www/py-aiohttp@${PY_FLAVOR} \
		ffmpeg:multimedia/ffmpeg

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	TonieToolbox
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
