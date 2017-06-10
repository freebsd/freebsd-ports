# Created by: Ben Woods <woodsb02@FreeBSD.org>
# $FreeBSD$

MASTERDIR=	${.CURDIR}/../py-pip

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py3-pytest \
		${PYTHON_PKGNAMEPREFIX}pytest-capturelog>0:devel/py3-pytest-capturelog \
		${PYTHON_PKGNAMEPREFIX}pytest-timeout>0:devel/py3-pytest-timeout \
		${PYTHON_PKGNAMEPREFIX}pytest-xdist>0:devel/py3-pytest-xdist \
		${PYTHON_PKGNAMEPREFIX}virtualenv>=1.10:devel/py3-virtualenv \
		${PYTHON_PKGNAMEPREFIX}scripttest>=1.3:devel/py3-scripttest \
		${PYTHON_PKGNAMEPREFIX}mock>0:devel/py3-mock \
		${PYTHON_PKGNAMEPREFIX}pretend>0:devel/py3-pretend \
		${PYTHON_PKGNAMEPREFIX}freezegun>0:devel/py3-freezegun \
		git>0:devel/git \
		bzr>0:devel/bzr

DOCS_BUILD_DEPENDS=	sphinx-build:textproc/py3-sphinx

USES=		python:3.3+ shebangfix

.include "${MASTERDIR}/Makefile"
