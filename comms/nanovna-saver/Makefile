# $FreeBSD$

PORTNAME=	nanovna-saver
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.2
CATEGORIES=	comms hamradio

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Multiplatform tool to save Touchstone files from the NanoVNA

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

PY_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}serial>0:comms/py-serial@${PY_FLAVOR}
BUILD_DEPENDS=	${PY_DEPENDS}
RUN_DEPENDS=	${PY_DEPENDS}

USES=		python:3.3+ pyqt:5 qt:5
USE_PYTHON=	distutils autoplist noflavors
USE_PYQT=	core_run gui_run widgets_run
QT5_USE=	core gui widgets

USE_GITHUB=	yes
GH_ACCOUNT=	mihtjel

NO_ARCH=	yes

.include <bsd.port.mk>
