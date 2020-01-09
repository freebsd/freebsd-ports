# $FreeBSD$

PORTNAME=	nanovna-saver
PORTVERSION=	0.2.1
CATEGORIES=	comms hamradio

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Multiplatform tool to save Touchstone files from the NanoVNA

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}scipy>=0.13.2:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}serial>0:comms/py-serial@${PY_FLAVOR}
RUN_DEPENDS=	${BUILD_DEPENDS}

USES=		python:3.3+ pyqt:5 qt:5
USE_PYTHON=	distutils autoplist noflavors
USE_PYQT=	core_run gui_run widgets_run
QT5_USE=	core gui widgets

NO_ARCH=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	mihtjel
GH_TAGNAME=	47e95d1

.include <bsd.port.mk>
