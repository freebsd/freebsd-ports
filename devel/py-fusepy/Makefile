# $FreeBSD$

PORTNAME=	fusepy
PORTVERSION=	2.0.4
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Simple ctypes bindings for FUSE

LICENSE=	ISCL

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}fusefs # fuse.py

NO_ARCH=	yes
USES=		fuse python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
