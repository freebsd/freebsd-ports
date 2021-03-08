# $FreeBSD$

PORTNAME=	nanovna-saver
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.8
PORTREVISION=	1
CATEGORIES=	comms hamradio

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Multiplatform tool to save Touchstone files from the NanoVNA

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

PY_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyserial>0:comms/py-pyserial@${PY_FLAVOR}
BUILD_DEPENDS=	${PY_DEPENDS}
RUN_DEPENDS=	${PY_DEPENDS}

USES=		python:3.3+ pyqt:5
USE_PYTHON=	distutils autoplist noflavors
USE_PYQT=	core_run gui_run widgets_run

USE_GITHUB=	yes
GH_ACCOUNT=	mihtjel

NO_ARCH=	yes

post-extract:
	${CP} ${FILESDIR}/Sysctl.py ${WRKSRC}/NanoVNASaver/Hardware/

.include <bsd.port.mk>
