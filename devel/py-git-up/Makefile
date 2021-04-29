PORTNAME=	git-up
DISTVERSION=	1.4.5
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ygy@FreeBSD.org
COMMENT=	Python implementation of 'git up'

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>=6.0.0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}colorama>=0.3.7:devel/py-colorama@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gitpython>=2.1.1:devel/py-gitpython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.10.0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}termcolor>=1.1.0:devel/py-termcolor@${PY_FLAVOR}

NO_ARCH=	yes
USES=		dos2unix python:3.6+ zip
USE_PYTHON=	autoplist concurrent distutils

.include <bsd.port.mk>
