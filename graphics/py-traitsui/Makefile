PORTNAME=	traitsui
DISTVERSION=	8.0.0
CATEGORIES=	graphics python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Enthought traits-capable user interfaces
WWW=		https://docs.enthought.com/traitsui/

LICENSE=	BSD3CLAUSE EPL LGPL21
LICENSE_COMB=	multi
LICENSE_FILE_BSD3CLAUSE=	${WRKSRC}/LICENSE.txt
LICENSE_FILE_EPL=	${WRKSRC}/image_LICENSE_Eclipse.txt
LICENSE_FILE_LGPL21=	${WRKSRC}/image_LICENSE_Nuvola.txt
# See ${WRKSRC}/image_LICENSE.txt for per file license information

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyface>=8.0.0:devel/py-pyface@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}traits>=6.2.0:devel/py-traits@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

OPTIONS_DEFINE=		PYSIDE QT5 WXPYTHON
OPTIONS_DEFAULT=	QT5

PYSIDE_DESC=	PySide backend
WXPYTHON_DESC=	wxPython backend

PYSIDE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyside2>=0:devel/pyside2@${PY_FLAVOR}
QT5_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pygments>=0:textproc/py-pygments@${PY_FLAVOR}
QT5_USES=		pyqt:5
QT5_USE=		PYQT=pyqt5:run
WXPYTHON_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}wxPython42>0:x11-toolkits/py-wxPython4@${PY_FLAVOR}

.include <bsd.port.mk>
