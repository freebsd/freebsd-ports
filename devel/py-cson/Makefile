PORTNAME=	cson
DISTVERSION=	0.8
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Coffescript Object Notation (CSON) parser for Python 2 and Python 3

LICENSE=	MIT

RUN_DEPENDS=	${PKGNAMEPREFIX}speg>=0.3:devel/py-speg@${PY_FLAVOR}
TEST_DEPENDS=	${PKGNAMEPREFIX}pytest:devel/py-pytest@${PY_FLAVOR} \
		${PKGNAMEPREFIX}speg>=0.3:devel/py-speg@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist distutils

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} -m pytest test

.include <bsd.port.mk>
