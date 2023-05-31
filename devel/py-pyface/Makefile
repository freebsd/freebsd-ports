PORTNAME=	pyface
DISTVERSION=	8.0.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Enthought traits-capable windowing framework
WWW=		https://docs.enthought.com/pyface/

LICENSE=	BSD3CLAUSE EPL LGPL21 LGPL3
LICENSE_COMB=	multi
LICENSE_FILE_EPL=	${WRKSRC}/image_LICENSE_Eclipse.txt
LICENSE_FILE_LGPL21=	${WRKSRC}/image_LICENSE_Nuvola.txt
LICENSE_FILE_LGPL3=	${WRKSRC}/image_LICENSE_OOo.txt
#See file ${WRKSRC}/image_LICENSE.txt for files with non BSD3CLAUSE licenses

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}importlib-metadata>=3.6.0:devel/py-importlib-metadata@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}importlib-resources>=1.1.0:devel/py-importlib-resources@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}traits>=6.2:devel/py-traits@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

# Note: The port also supports the wxPython toolkit, but this still has to be
# tested.
OPTIONS_DEFINE=		QT5
OPTIONS_DEFAULT=	QT5

QT5_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pygments>0:textproc/py-pygments@${PY_FLAVOR}
QT5_USES=		pyqt:5
QT5_USE=		PYQT=pyqt5:run

.include <bsd.port.mk>
