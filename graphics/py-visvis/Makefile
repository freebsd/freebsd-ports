PORTNAME=	visvis
PORTVERSION=	1.15.0
PORTREVISION=	5
CATEGORIES=	graphics python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rhurlin@FreeBSD.org
COMMENT=	Object oriented approach to visualization of 1D to 4D data
WWW=		https://github.com/almarklein/visvis

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfltk.so:x11-toolkits/fltk
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>=3.2.0<4:devel/py-flit-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}imageio>=0:graphics/py-imageio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}PyOpenGL>=0:graphics/py-PyOpenGL@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flake8>=5.0:devel/py-flake8@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hypothesis>=0:devel/py-hypothesis@${PY_FLAVOR}

USES=		gl python shebangfix
USE_GL=		gl
USE_PYTHON=	autoplist pep517 pytest
USE_WX=		3.0+

SHEBANG_FILES=	examples/*.py

NO_ARCH=	yes

OPTIONS_DEFINE=	PYQT PYSIDE
OPTIONS_DEFAULT=PYQT

PYQT_DESC=	Qt 6 backend via PyQt
PYQT_USES=	pyqt:6
PYQT_USE=	PYQT=pyqt6:run

PYSIDE_DESC=		Qt 6 backend via PySide
PYSIDE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyside6>=0:devel/pyside6@${PY_FLAVOR}

.include <bsd.port.mk>
