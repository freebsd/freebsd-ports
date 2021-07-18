PORTNAME=	phx-class-registry
DISTVERSION=	3.0.5
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	PopularMoment@protonmail.com
COMMENT=	Factory+Registry pattern for Python classes

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>=1.13:devel/py-six@${PY_FLAVOR}

TEST_DEPENDS=   ${PYTHON_PKGNAMEPREFIX}nose>0:devel/py-nose@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist concurrent

NO_ARCH=	yes

do-test:
	@cd ${WRKSRC}/ && ${PYTHON_CMD} setup.py test

.include <bsd.port.mk>
