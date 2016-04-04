# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	circuits
PORTVERSION=	3.1.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Asynchronous Component-based Event Application Framework

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

post-extract:
	${FIND} ${WRKSRC} -type d -name __pycache__ -exec ${RM} -r {} +

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} -m pytest tests

.include <bsd.port.mk>
