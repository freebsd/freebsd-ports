# Created by: Kubilay Kocak <koobs@FreeBSD.org>

PORTNAME=	doit
PORTVERSION=	0.31.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Task management and automation tool

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cloudpickle>0:devel/py-cloudpickle@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=2.8.0:devel/py-pytest@${PY_FLAVOR}

USES=		python:3.4+
USE_PYTHON=	distutils autoplist concurrent

NO_ARCH=	yes

# Doesn't support pytest > 4 yet
# https://github.com/pydoit/doit/issues/275

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} -m pytest

.include <bsd.port.mk>
