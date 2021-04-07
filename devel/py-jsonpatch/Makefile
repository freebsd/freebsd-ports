PORTNAME=	jsonpatch
DISTVERSION=	1.21
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	harm@weites.com
COMMENT=	Apply JSON-Patches (RFC 6902)

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}jsonpointer>0:devel/py-jsonpointer@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils
NO_ARCH=	yes

do-test: build
	@cd ${WRKSRC} && ${PYTHON_CMD} tests.py
	@cd ${WRKSRC} && ${PYTHON_CMD} ext_tests.py

.include <bsd.port.mk>
