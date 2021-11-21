# Created by: Dryice Liu <dryice@dryice.name>

PORTNAME=	nose
PORTVERSION=	1.3.7
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Discovery-based unittest extension

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/lgpl.txt

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

do-test:
# Extra tests for python 3, added in by setup3lib.py
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} build_tests
	@cd ${WRKSRC} && ${PYTHON_CMD} selftest.py

.include <bsd.port.mk>
