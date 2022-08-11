PORTNAME=	qpageview
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.2
CATEGORIES=	graphics python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	m.ne@gmx.net
COMMENT=	Page-based viewer widget for Qt5/PyQt5

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python-poppler-qt5>=0:graphics/py-python-poppler-qt5@${PY_FLAVOR}

USES=		pyqt:5 python:3.6+ qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	frescobaldi
USE_PYQT=	pyqt5
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	CUPS

CUPS_DESC=	Use print/py-pycups for printing

CUPS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pycups>0:print/py-pycups@${PY_FLAVOR}

.include <bsd.port.mk>
