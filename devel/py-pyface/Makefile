# Created by: Vladimir Chukharev
# $FreeBSD$

PORTNAME=	pyface
PORTVERSION=	6.1.2
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	Vladimir.Chukharev@gmail.com
COMMENT=	Enthought traits-capable windowing framework

LICENSE=	BSD3CLAUSE LGPL21 EPL LGPL3
LICENSE_COMB=	multi
LICENSE_FILE_LGPL21=	${WRKSRC}/image_LICENSE_Nuvola.txt
LICENSE_FILE_EPL=	${WRKSRC}/image_LICENSE_Eclipse.txt
LICENSE_FILE_LGPL3=	${WRKSRC}/image_LICENSE_OOo.txt
#See file ${WRKSRC}/image_LICENSE.txt for files with non BSD3CLAUSE licenses

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}traits>0:devel/py-traits@${PY_FLAVOR}
# The requirements are defined in pyface/__init__.py

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nose>0:devel/py-nose@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>0:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>0:textproc/py-pygments@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

# Note: The port also supports the wxPython toolkit, but this still has to be
# tested.
OPTIONS_DEFINE=		QT5
OPTIONS_DEFAULT=	QT5

QT5_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pygments>0:textproc/py-pygments@${PY_FLAVOR}
QT5_USES=		pyqt:5
QT5_USE=		PYQT=core_run,gui_run,network_test,opengl_test,printsupport_run,svg_run,test_test,webkit_test,webkitwidgets_test,widgets_run

# These tests were extracted from etstool.py and adapted to the ports test framework
# Note: The occurences of "qt4" aren't typos
do-test-QT5-on:
	@cd ${WRKSRC} && ${SETENV} ETS_TOOLKIT=qt4 QT_API=pyqt5 \
		${PYTHON_CMD} -m nose -v pyface

.include <bsd.port.mk>
