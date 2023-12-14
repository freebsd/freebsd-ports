PORTNAME=	thonny
PORTVERSION=	4.1.4
PORTREVISION=	1
CATEGORIES=	devel education python
MASTER_SITES=	PYPI
PKGNAMESUFFIX=	${PYTHON_PKGNAMESUFFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Python IDE for beginners
WWW=		https://thonny.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	pylint:devel/pylint@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jedi>=0.18.1:devel/py-jedi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}astroid>=1.4.9:devel/py-astroid@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docutils>=0.16:textproc/py-docutils@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mypy>=0.670:devel/py-mypy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyserial>=3.4:comms/py-pyserial@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}send2trash>=1.5:deskutils/py-send2trash@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}asttokens>=2.0:devel/py-asttokens@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tkinter>0:x11-toolkits/py-tkinter@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pip>=0:devel/py-pip@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
