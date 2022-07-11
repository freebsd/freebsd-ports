# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	flake8-black
PORTVERSION=	0.3.3
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	flake8 plugin to call black as a code style validator

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.rst

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}black>=22.1.0:devel/py-black@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flake8>=3.0.0:devel/py-flake8@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tomli>=0:textproc/py-tomli@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
