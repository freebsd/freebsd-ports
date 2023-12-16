PORTNAME=	visvis
PORTVERSION=	1.14.0
PORTREVISION=	4
CATEGORIES=	graphics python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rhurlin@FreeBSD.org
COMMENT=	Object oriented approach to visualization of 1D to 4D data
WWW=		https://github.com/almarklein/visvis

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/license.txt

LIB_DEPENDS=	libfltk.so:x11-toolkits/fltk
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}imageio>=0:graphics/py-imageio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}PyOpenGL>=0:graphics/py-PyOpenGL@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyside2>=0:devel/pyside2@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hypothesis>=0:devel/py-hypothesis@${PY_FLAVOR}

USES=		gl python pyqt:5 pytest shebangfix
USE_GL=		gl
USE_PYQT=	pyqt5
USE_PYTHON=	autoplist distutils
USE_WX=		3.0+

SHEBANG_FILES=	examples/*.py

NO_ARCH=	yes

.include <bsd.port.mk>
