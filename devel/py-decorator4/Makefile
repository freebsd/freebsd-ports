PORTNAME=	decorator
PORTVERSION=	4.4.2
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	4

MAINTAINER=	ygy@FreeBSD.org
COMMENT=	Decorators for Humans

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

DEPRECATED=	Legacy version, use devel/py-decorator instead
EXPIRATION_DATE=2021-12-31

USES=		python:3.6+
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
