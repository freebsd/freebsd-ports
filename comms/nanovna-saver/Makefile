PORTNAME=	nanovna-saver
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.3
PORTREVISION=	1
CATEGORIES=	comms hamradio

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Multiplatform tool to save Touchstone files from the NanoVNA
WWW=		https://github.com/NanoVNA-Saver/nanovna-saver

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

PY_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyserial>0:comms/py-pyserial@${PY_FLAVOR}
BUILD_DEPENDS=	${PY_DEPENDS}
RUN_DEPENDS=	${PY_DEPENDS}

USES=		python pyqt:5
USE_PYTHON=	distutils autoplist noflavors

USE_GITHUB=	yes
GH_ACCOUNT=	NanoVNA-Saver

NO_ARCH=	yes

post-extract:
	${CP} ${FILESDIR}/Sysctl.py ${WRKSRC}/NanoVNASaver/Hardware/

.include <bsd.port.mk>
