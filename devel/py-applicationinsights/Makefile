# $FreeBSD$

PORTNAME=	applicationinsights
DISTVERSION=	0.11.7
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dbn@FreeBSD.org
COMMENT=	Applications Insights SDK for Python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

do-test:
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test)

.include <bsd.port.mk>
