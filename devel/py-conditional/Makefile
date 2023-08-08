PORTNAME=	conditional
PORTVERSION=	1.3
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Conditionally enter a context manager
WWW=		https://pypi.org/project/conditional/

LICENSE=	BSD2CLAUSE

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flexmock>=0.10.5:devel/py-flexmock@${PY_FLAVOR}

USES=		python zip
USE_PYTHON=	distutils autoplist

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
