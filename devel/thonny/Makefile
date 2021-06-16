PORTNAME=	thonny
PORTVERSION=	3.3.10
CATEGORIES=	devel education python
MASTER_SITES=	CHEESESHOP
PKGNAMESUFFIX=	${PYTHON_PKGNAMESUFFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Python IDE for beginners

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	pylint:devel/pylint \
		${PYTHON_PKGNAMEPREFIX}jedi>=0.13:devel/py-jedi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}astroid>=1.4.9:devel/py-astroid@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docutils>=0.14:textproc/py-docutils@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mypy>=0.670:devel/py-mypy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyserial>=3.4:comms/py-pyserial@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}send2trash>=1.5:deskutils/py-send2trash@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}asttokens>=1.1:devel/py-asttokens@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tkinter>0:x11-toolkits/py-tkinter@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
