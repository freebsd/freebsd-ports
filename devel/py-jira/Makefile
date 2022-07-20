PORTNAME=	jira
PORTVERSION=	2.0.0
PORTREVISION=	4
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Library to ease use of the JIRA 5 REST APIs

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=1.9:devel/py-pbr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-runner>0:devel/py-pytest-runner@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sphinx>=1.6.5,1:textproc/py-sphinx@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=1.9:devel/py-pbr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests-oauthlib>=0.3.3:www/py-requests-oauthlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=1.2.3:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.5.2:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tlslite>=0.4.4:security/py-tlslite@${PY_FLAVOR}
TEST_DEPENDS:=	${PYTHON_PKGNAMEPREFIX}nose>0:devel/py-nose@${PY_FLAVOR} \
		${RUN_DEPENDS}

USES=		python:3.5+
USE_PYTHON=	autoplist distutils

OPTIONS_DEFINE=		MAGIC PARALLEL SHELL TESTS
OPTIONS_DEFAULT=	MAGIC PARALLEL SHELL

MAGIC_DESC=	Enable Content-Type Auto-detection
PARALLEL_DESC=	Enable asynchronous requests
SHELL_DESC=	Enable interactive shell
TESTS_DESC=	Install test suite dependencies

MAGIC_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}filemagic>=1.6:devel/py-filemagic@${PY_FLAVOR}
PARALLEL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}grequests>0:www/py-grequests@${PY_FLAVOR}
SHELL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ipython>=0.13:devel/ipython@${PY_FLAVOR}
TESTS_BUILD_DEPENDS=	${TEST_DEPENDS}

TEST_DEPENDS:=	${PYTHON_PKGNAMEPREFIX}nose>0:devel/py-nose@${PY_FLAVOR} \
		${RUN_DEPENDS}

.include <bsd.port.mk>
