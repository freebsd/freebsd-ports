# Created by: Alexandros Kosiaris <akosiaris+ports@gmail.com>
# $FreeBSD$

PORTNAME=	jira
PORTVERSION=	1.0.14
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Library to ease use of the JIRA 5 REST APIs

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-runner>0:devel/py-pytest-runner@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pbr>=1.9:devel/py-pbr@${FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=1.2.3:www/py-requests@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests-oauthlib>=0.3.3:www/py-requests-oauthlib@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tlslite>=0.4.4:security/py-tlslite@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.5.2:devel/py-six@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycrypto>=0:security/py-pycrypto@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pbr>=1.9:devel/py-pbr@${FLAVOR}
TEST_DEPENDS:=	${RUN_DEPENDS} \
		${PYTHON_PKGNAMEPREFIX}nose>0:devel/py-nose@${FLAVOR}

OPTIONS_DEFINE=		MAGIC PARALLEL SHELL TESTS
OPTIONS_DEFAULT=	MAGIC PARALLEL SHELL

MAGIC_DESC=	Enable Content-Type Auto-detection
PARALLEL_DESC=	Enable asynchronous requests
SHELL_DESC=	Enable interactive shell
TESTS_DESC=	Install test suite dependencies

MAGIC_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}filemagic>=1.6:devel/py-filemagic@${FLAVOR}
PARALLEL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}grequests>0:www/py-grequests@${FLAVOR}
SHELL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ipython>=0.13:devel/ipython@${FLAVOR}
TESTS_BUILD_DEPENDS=	${TEST_DEPENDS}

TEST_DEPENDS:=	${RUN_DEPENDS} \
		${PYTHON_PKGNAMEPREFIX}nose>0:devel/py-nose@${FLAVOR}

USES=		python:2.7
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
