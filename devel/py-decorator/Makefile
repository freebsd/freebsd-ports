# Created by: Denis Shaposhnikov <dsh@vlink.ru>

PORTNAME=	decorator
PORTVERSION=	5.0.7
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ygy@FreeBSD.org
COMMENT=	Decorators for Humans

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
