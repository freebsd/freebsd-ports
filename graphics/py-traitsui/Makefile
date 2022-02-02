# Created by: Vladimir Chukharev

PORTNAME=	traitsui
PORTVERSION=	7.1.1
PORTREVISION=	1
CATEGORIES=	graphics python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Enthought traits-capable user interfaces

LICENSE=	BSD3CLAUSE LGPL21 EPL
LICENSE_COMB=	multi
LICENSE_FILE_BSD3CLAUSE=	${WRKSRC}/LICENSE.txt
LICENSE_FILE_LGPL21=	${WRKSRC}/image_LICENSE_Nuvola.txt
LICENSE_FILE_EPL=	${WRKSRC}/image_LICENSE_Eclipse.txt
# See ${WRKSRC}/image_LICENSE.txt for per file license information

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}traits>=6.0.0:devel/py-traits@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyface>=7.1.0:devel/py-pyface@${PY_FLAVOR}
# The requirements are defined in traitsui/__init__.py

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>0:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>0:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>=0:textproc/py-pygments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}traits>0:devel/py-traits@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nose>0:devel/py-nose@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}configobj>0:devel/py-configobj@${PY_FLAVOR}
# Those requirements (except for pip + coverage) were extracted from etstool.py

USES=		python:3.7+
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

# Support for the wxPython toolkit is also available, but
# Python 3 needs wxPython 4 which isn't ported, yet. So we use only Qt5 for a
# while to make the port useful for Python 3.
OPTIONS_DEFINE=	QT5
OPTIONS_DEFAULT=QT5

QT5_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pygments>=0:textproc/py-pygments@${PY_FLAVOR}
QT5_USES=		pyqt:5
QT5_USE=		PYQT=pyqt5_run

# These tests were extracted from etstool.py and adapted to the ports test framework
do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} -m nose -v traitsui.tests

# The test "test_wrap_text_narrow_short" fails at the moment and is going to be
# fixed with the next release.
# See also: https://github.com/enthought/traitsui/issues/643
#
# Note: The occurences of "qt4" aren't typos
do-test-QT5-on:
	@cd ${WRKSRC} && ${SETENV} ETS_TOOLKIT=qt4 QT_API=pyqt5 \
		${PYTHON_CMD} -m nose -v traitsui.qt4.tests

.include <bsd.port.mk>
