# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pytest-localserver
PORTVERSION=	0.3.5
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Py.test Plugin to test server connections locally

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest \
		${PYTHON_PKGNAMEPREFIX}werkzeug>=0.10:www/py-werkzeug
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} -m pytest

.include <bsd.port.mk>
