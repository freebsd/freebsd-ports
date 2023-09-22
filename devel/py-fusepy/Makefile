PORTNAME=	fusepy
PORTVERSION=	3.0.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Simple ctypes bindings for FUSE
WWW=		https://github.com/fusepy/fusepy

LICENSE=	ISCL

USES=		fuse python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}fusefs # fuse.py

.include <bsd.port.mk>
