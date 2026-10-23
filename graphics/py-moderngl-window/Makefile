PORTNAME=	moderngl-window
DISTVERSION=	3.1.1
CATEGORIES=	graphics
#MASTER_SITES=	PYPI # no tests
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for ModernGL making window creation & resource loading simple
WWW=		https://github.com/moderngl/moderngl-window

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}moderngl>0:graphics/py-moderngl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR} \
		${PY_PILLOW} \
		${PYTHON_PKGNAMEPREFIX}pyglet>=2.0.0:graphics/py-pyglet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyglm>=2.7.0:graphics/py-pyglm@${PY_FLAVOR}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}PyWavefront>=1.2.0:misc/py-PyWavefront@${PY_FLAVOR} # optional
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}trimesh>=3.2.6:graphics/py-trimesh@${PY_FLAVOR} # optional
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR}

USES=		display:test python
USE_PYTHON=	pep517 autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	moderngl

NO_ARCH=	yes

TEST_ARGS=	--disable-plugin-autoload
TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

# tests as of 3.1.1: 120 passed, 1 warning in 24.70s

.include <bsd.port.mk>
