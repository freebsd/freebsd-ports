# $FreeBSD$

PORTNAME=	pyte
PORTVERSION=	0.5.2
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Simple VTXXX-compatible terminal emulator

LICENSE=	LGPL3

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-runner>0:devel/py-pytest-runner
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}wcwidth>0:devel/py-wcwidth

NO_ARCH=	yes
USE_PYTHON=	autoplist concurrent distutils
USES=		python

.include <bsd.port.mk>
