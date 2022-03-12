# Created by: Kubilay Kocak <koobs@FreeBSD.org>

PORTNAME=	pytrie
PORTVERSION=	0.4.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PyTrie-${PORTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Pure Python implementation of the trie data structure

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sortedcontainers>0:devel/py-sortedcontainers@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
