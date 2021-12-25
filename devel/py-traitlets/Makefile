# Created by: Yuri Victorovich <yuri@rawbw.com>

PORTNAME=	traitlets
PORTVERSION=	5.1.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Configuration system for Python applications

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING.md

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ipython_genutils>0:devel/py-ipython_genutils@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR}

USES=		python:3.5+
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

do-test:
	@(cd ${TEST_WRKSRC} && py.test-${PYTHON_VER} traitlets)

.include <bsd.port.mk>
