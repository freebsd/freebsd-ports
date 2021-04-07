PORTNAME=	trollius
PORTVERSION=	2.2
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Port of the Tulip project (asyncio module, PEP 3156) on Python 2

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		python:3.6+
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && \
	${PYTHON_CMD} runtests.py

.include <bsd.port.mk>
