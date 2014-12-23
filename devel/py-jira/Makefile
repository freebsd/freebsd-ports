# Created by: Alexandros Kosiaris <akosiaris+ports@gmail.com>
# $FreeBSD$

PORTNAME=	jira
PORTVERSION=	0.32
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	akosiaris+ports@gmail.com
COMMENT=	Library to ease use of the JIRA 5 REST APIs

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=1.2.3:${PORTSDIR}/www/py-requests \
		${PYTHON_PKGNAMEPREFIX}requests-oauthlib>=0.3.3:${PORTSDIR}/www/py-requests-oauthlib \
		${PYTHON_PKGNAMEPREFIX}tlslite>=0.4.4:${PORTSDIR}/security/py-tlslite \
		${PYTHON_PKGNAMEPREFIX}six>=1.5.2:${PORTSDIR}/devel/py-six \
		${PYTHON_PKGNAMEPREFIX}pycrypto>=0:${PORTSDIR}/security/py-pycrypto
TEST_DEPENDS:=	${RUN_DEPENDS} \
		${PYTHON_PKGNAMEPREFIX}nose>0:${PORTSDIR}/devel/py-nose

OPTIONS_DEFINE=		MAGIC PARALLEL SHELL TESTS
OPTIONS_DEFAULT=	MAGIC PARALLEL

MAGIC_DESC=	Enable Content-Type Auto-detection
PARALLEL_DESC=	Enable asynchronous requests
SHELL_DESC=	Enable interactive shell
TESTS_DESC=	Install test suite dependencies

MAGIC_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}filemagic>=1.6:${PORTSDIR}/devel/py-filemagic
PARALLEL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}grequests>0:${PORTSDIR}/www/py-grequests
SHELL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ipython>=0.13:${PORTSDIR}/devel/ipython
TESTS_BUILD_DEPENDS=	${TEST_DEPENDS}

TEST_DEPENDS:=	${RUN_DEPENDS} \
		${PYTHON_PKGNAMEPREFIX}nose>0:${PORTSDIR}/devel/py-nose

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
