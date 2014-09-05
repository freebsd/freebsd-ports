# Created by: Dryice Liu <dryice@dryice.name>
# $FreeBSD$

PORTNAME=	nose
PORTVERSION=	1.3.3
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Discovery-based unittest extension

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/lgpl.txt

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.pre.mk>

regression-test: build
# Extra tests for python 3, added in by setup3lib.py
.if ${PYTHON_REL} >= 300
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} build_tests
.endif
	@cd ${WRKSRC} && ${PYTHON_CMD} selftest.py --verbose

.include <bsd.port.post.mk>
