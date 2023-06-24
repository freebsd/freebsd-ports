PORTNAME=	fury
DISTVERSION=	0.9.0
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Free Unified Rendering in Python
WWW=		https://fury.gl/latest/index.html

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

PY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiohttp>=3.8.4:www/py-aiohttp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.7.1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=8.0.1:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygltflib>=1.15.1:graphics/py-pygltflib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.4.0:science/py-scipy@${PY_FLAVOR} \
		vtk${VTK_VER:R}>0:math/vtk${VTK_VER:R}
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatch-vcs>0:devel/py-hatch-vcs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR} \
		${PY_DEPENDS}
RUN_DEPENDS=	${PY_DEPENDS}

USES=		python
USE_PYTHON=	pep517 autoplist pytest # tests fail with signal 10, see https://github.com/fury-gl/fury/issues/795

NO_ARCH=	yes

.include <../../math/vtk9/Makefile.version>
.include <bsd.port.mk>
