# Created by: Dryice Liu <dryice@dryice.name>
# $FreeBSD$

PORTNAME=	nose
PORTVERSION=	1.3.0
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Discovery-based unittest extension

LICENSE=	LGPL21

# Python3 ready
USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

regression-test: build
	@cd ${WRKSRC} && ${PYTHON_CMD} selftest.py

.include <bsd.port.mk>
