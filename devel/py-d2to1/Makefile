# Created by: Kubilay Kocak <koobs@FreeBSD.org>

PORTNAME=	d2to1
DISTVERSION=	0.2.12.post1
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Distutils2-like setup.cfg files with setuptools setup.py

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose>0:devel/py-nose@${PY_FLAVOR}

USES=		python:3.6+
USE_GITHUB=	yes
USE_PYTHON=	distutils autoplist

GH_ACCOUNT=	embray

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
