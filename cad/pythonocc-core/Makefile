PORTNAME=	pythonocc-core
DISTVERSION=	8.0.0.a
CATEGORIES=	cad python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	philippehay71@gmail.com
COMMENT=	3D modeling based on the OpenCascade Technology modeling kernel
WWW=		https://github.com/tpaviot/pythonocc-core

LICENSE=	LGPL3

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.17:math/py-numpy@${PY_FLAVOR} \
		${LOCALBASE}/include/rapidjson/reader.h:devel/rapidjson \
		swig:devel/swig \
		${PYTHON_PKGNAMEPREFIX}qt5-pyqt>0:devel/py-qt5-pyqt@${PY_FLAVOR}
LIB_DEPENDS=	libTKernel.so:cad/opencascade
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.17:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}svgwrite>0:graphics/py-svgwrite@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy-stl>0:math/py-numpy-stl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}qt5-pyqt>0:devel/py-qt5-pyqt@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}black>0:devel/py-black@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}twisted>0:devel/py-twisted@${PY_FLAVOR}

USES=		cmake compiler:c++17-lang gl pytest python
USE_GL=		opengl
USE_PYTHON=	cython

USE_GITHUB=	yes
GH_ACCOUNT=	tpaviot
GH_PROJECT=	pythonocc-core
GH_TAGNAME=	fe54be6549db400da0d59caeed7af1d04e92a9ab

.include <bsd.port.mk>
