PORTNAME=	qpageview
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.1
CATEGORIES=	graphics python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	m.ne@gmx.net
COMMENT=	Page-based viewer widget for Qt5/PyQt5
WWW=		https://qpageview.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}

USES=		pyqt:6 python qt:6
USE_GITHUB=	yes
GH_ACCOUNT=	frescobaldi
USE_PYQT=	pyqt6
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	CUPS

CUPS_DESC=	Use print/py-pycups for printing

CUPS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pycups>0:print/py-pycups@${PY_FLAVOR}

.include <bsd.port.mk>
