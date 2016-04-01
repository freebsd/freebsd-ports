# Created by: Yi-Jheng Lin <yzlin@cs.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	fabric
PORTVERSION=	1.10.2
PORTEPOCH=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:C/f/F/}-${DISTVERSION}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Simple, Pythonic remote execution and deployment

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}paramiko>=1.10:security/py-paramiko
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose>0:devel/py-nose \
		${PYTHON_PKGNAMEPREFIX}fudge>0:devel/py-fudge \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=0.6:devel/py-Jinja2

USES=		python:2.7
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
