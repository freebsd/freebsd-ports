PORTNAME=	moderngl-window
DISTVERSION=	3.1.0
PORTREVISION=	1
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
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}moderngl<6:graphics/py-moderngl@${PY_FLAVOR} \
		${PYNUMPY} \
		${PY_PILLOW} \
		${PYTHON_PKGNAMEPREFIX}pyglet>=2.0.0:graphics/py-pyglet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyglm>=2.7.0:graphics/py-pyglm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyrr>=0.10.3,<1:math/py-pyrr@${PY_FLAVOR}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}PyWavefront>0:misc/py-PyWavefront@${PY_FLAVOR} # optional
#RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}trimesh>0:devel/py-trimesh@${PY_FLAVOR} # optional, causes conflicts due to pyglet1 vs. pyglet

USES=		python
USE_PYTHON=	pep517 autoplist pytest # some tests fail due to missing trimesh

USE_GITHUB=	yes
GH_ACCOUNT=	moderngl

NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

# tests as of 3.1.0: 1 failed, 61 passed, 58 errors in 12.83s

.include <bsd.port.mk>
