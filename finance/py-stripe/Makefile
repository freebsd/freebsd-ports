# Created by: Trevor Caira <trevor@bitba.se>
# $FreeBSD$
#

PORTNAME=	stripe
DISTVERSION=	1.30.0
CATEGORIES=	finance python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Stripe Python bindings

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=0.8.8:www/py-requests
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pycurl>=7.19:ftp/py-pycurl \
		${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && ${SETENV} STRIPE_TEST_PYCURL=yes ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
