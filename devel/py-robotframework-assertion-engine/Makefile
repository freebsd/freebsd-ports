PORTNAME=	robotframework-assertion-engine
PORTVERSION=	3.0.3
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	robotframework_assertion_engine-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Generic way to create meaningful and easy to use assertions for the Robot Framework libraries
WWW=		https://github.com/MarketSquare/AssertionEngine

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=1.0.0:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}robotframework>=5.0.1:devel/py-robotframework@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}robotframework-pythonlibcore>=3.0.0<5:devel/py-robotframework-pythonlibcore@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
