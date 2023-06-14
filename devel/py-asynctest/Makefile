PORTNAME=	asynctest
PORTVERSION=	0.13.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Enhance unittest for testing asyncio libraries
WWW=		https://github.com/Martiusweb/asynctest

LICENSE=	APACHE20

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mock>=0:devel/py-mock@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils unittest

NO_ARCH=	yes
TEST_ARGS=	discover -s test

.include <bsd.port.mk>
