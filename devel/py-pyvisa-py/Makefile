PORTNAME=	pyvisa-py
PORTVERSION=	0.5.2
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PyVISA-py-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	PyVISA backend in pure Python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>=3.4.3:devel/py-setuptools_scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}typing-extensions>=0:devel/py-typing-extensions@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	SERIAL USB
SERIAL_DESC=	Access to devices via RS-232
USB_DESC=	Access to devices via USB

SERIAL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyserial>=3.0:comms/py-pyserial@${PY_FLAVOR}
USB_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyusb>=0:devel/py-pyusb@${PY_FLAVOR}

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 30800
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}importlib-metadata>=0:devel/py-importlib-metadata@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
