# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rauth
PORTVERSION=	0.7.2
CATEGORIES=	devel www python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Python library for OAuth 1.0/a, 2.0, and Ofly consumers

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=1.2.3:www/py-requests
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose>=1.2.1:devel/py-nose \
		${PYTHON_PKGNAMEPREFIX}mock>=1.0.1:devel/py-mock \
		${PYTHON_PKGNAMEPREFIX}pycrypto>=2.5:security/py-pycrypto

USES=		python
USE_GITHUB=	yes
USE_PYTHON=	distutils autoplist

GH_ACCOUNT=	litl

NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
