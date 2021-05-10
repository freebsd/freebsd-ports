PORTNAME=	hid
DISTVERSION=	1.0.4
CATEGORIES=	comms python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Ctypes bindings to comms/hidapi

LICENSE=	MIT

RUN_DEPENDS=	hidapi>0:comms/hidapi

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
