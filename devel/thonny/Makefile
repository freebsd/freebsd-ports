# $FreeBSD$

PORTNAME=	thonny
PORTVERSION=	3.2.5
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMESUFFIX=	${PYTHON_PKGNAMESUFFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Python IDE for beginners

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	pylint:devel/pylint \
		${PYTHON_PKGNAMEPREFIX}jedi>=0.10:devel/py-jedi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}astroid>=1.4.9:devel/py-astroid@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docutils>=0.13.1:textproc/py-docutils@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mypy>=0.470:devel/py-mypy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mypy_extensions>=0.4.0:devel/py-mypy_extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyperclip>=1.5.27:devel/py-pyperclip@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}serial>=3.2.1:comms/py-serial@${PY_FLAVOR}

USES=		python:3.5+
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
