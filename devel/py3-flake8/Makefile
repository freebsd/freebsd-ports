# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

MASTERDIR=	${.CURDIR}/../py-flake8

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-runner>=0:devel/py3-pytest-runner
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mccabe>=0.5.0:devel/py3-mccabe \
		${PYTHON_PKGNAMEPREFIX}pycodestyle>=2.0.0:devel/py3-pycodestyle \
		${PYTHON_PKGNAMEPREFIX}pyflakes>=0.8.1:devel/py3-pyflakes

USES=		python:3

.include "${MASTERDIR}/Makefile"
