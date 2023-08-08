PORTNAME=	hid
DISTVERSION=	1.0.4
CATEGORIES=	comms python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Ctypes bindings to comms/hidapi
WWW=		https://github.com/apmorton/pyhidapi

LICENSE=	MIT

RUN_DEPENDS=	hidapi>0:comms/hidapi

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
