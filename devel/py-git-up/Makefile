# $FreeBSD$

PORTNAME=	git-up
DISTVERSION=	1.4.5
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	che@bein.link
COMMENT=	Python implementation of 'git up'

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>=6.0.0:devel/py-click \
		${PYTHON_PKGNAMEPREFIX}colorama>=0.3.7:devel/py-colorama \
		${PYTHON_PKGNAMEPREFIX}GitPython>=2.1.1:devel/py-gitpython \
		${PYTHON_PKGNAMEPREFIX}six>=1.10.0:devel/py-six \
		${PYTHON_PKGNAMEPREFIX}termcolor>=1.1.0:devel/py-termcolor

NO_ARCH=	yes
USES=		dos2unix python zip
USE_PYTHON=	autoplist concurrent distutils

.include <bsd.port.mk>
