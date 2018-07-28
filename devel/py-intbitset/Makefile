# $FreeBSD$

PORTNAME=	intbitset
DISTVERSION=	2.3.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	freebsd_ports@k-worx.org
COMMENT=	C-based extension implementing fast integer bit sets

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose>=0:devel/py-nose@${PY_FLAVOR}

USES=		python
USE_PYTHON=	cython distutils autoplist

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
