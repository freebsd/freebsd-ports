# Created by: Ben Woods <woodsb02@FreeBSD.org>
# $FreeBSD$

MASTERDIR=	${.CURDIR}/../py-pytest-xdist

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>=0:devel/py3-setuptools_scm
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}execnet>=1.1:sysutils/py3-execnet \
		${PYTHON_PKGNAMEPREFIX}pytest>=2.4.2:devel/py3-pytest \
		${PYTHON_PKGNAMEPREFIX}py>=1.4.22:devel/py3-py
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=2.5.1:devel/py3-pytest \
		${PYTHON_PKGNAMEPREFIX}pexpect>0:misc/py3-pexpect

USES=	python:3.3+

.include "${MASTERDIR}/Makefile"
