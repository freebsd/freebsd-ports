# $FreeBSD$

PORTNAME=	pyvisa
PORTVERSION=	1.9.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PyVISA-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python VISA bindings for GPIB, RS232, TCPIP and USB instruments

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PY_ENUM34} \
		${PYTHON_PKGNAMEPREFIX}pyvisa-py>=0:devel/py-pyvisa-py@${FLAVOR}

USES=		python
USE_LOCALE=	en_US.UTF-8
USE_PYTHON=	autoplist concurrent distutils
NO_ARCH=	yes

.include <bsd.port.mk>
