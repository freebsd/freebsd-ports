# $FreeBSD$

PORTNAME=	cookiecutter
PORTVERSION=	1.7.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Create projects from cookiecutters (project templates)

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}future>=0.15.2:devel/py-future@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}binaryornot>=0.2.0:devel/py-binaryornot@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=2.7:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>=7.0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}whichcraft>=0.4.0:devel/py-whichcraft@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}poyo>=0.1.0:devel/py-poyo@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jinja2-time>=0.1.0:devel/py-jinja2-time@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.18.0:www/py-requests@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-mock>0:devel/py-pytest-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}freezegun>0:devel/py-freezegun@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flake8>0:devel/py-flake8@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes


# pytest needs a UTF-8 environment, and it will try and write outside
# ${WRKDIR} unless told not to.  Even so, these tests have failures:
#
# cookiecutter/utils.py            50      3    94%
# cookiecutter/zipfile.py          61      2    97%

TEST_ENV=	TMPDIR=${WRKDIR} HOME=${WRKDIR} LC_ALL=en_US.UTF-8 LANG=en_US.UTF-8

do-test:
	@cd ${WRKSRC} && \
	${SETENV} ${TEST_ENV} ${LOCALBASE}/bin/pytest-${PYTHON_VER} --cov=cookiecutter tests

.include <bsd.port.mk>
