PORTNAME=	fusepy
PORTVERSION=	3.0.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple ctypes bindings for FUSE
WWW=		https://pypi.org/project/fusepy/

LICENSE=	ISCL

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}fusefs # fuse.py

NO_ARCH=	yes
USES=		fuse python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
