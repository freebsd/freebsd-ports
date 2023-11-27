PORTNAME=	pyvisa
PORTVERSION=	1.14.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI \
		https://github.com/pyvisa/pyvisa/releases/download/${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PyVISA-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python VISA bindings for GPIB, RS232, TCPIP and USB instruments
WWW=		https://github.com/pyvisa/pyvisa

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61.2:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools_scm>=3.4.3:devel/py-setuptools_scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}typing-extensions>=0:devel/py-typing-extensions@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
