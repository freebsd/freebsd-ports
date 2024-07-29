PORTNAME=	cymbal
DISTVERSION=	1.0.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@nicandneal.net
COMMENT=	Easily add functionality missing from libclang Python bindings
WWW=		https://github.com/CadQuery/cymbal

LICENSE=	MIT

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}unittest2>0:devel/py-unittest2@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes
TEST_TARGET=	test

do-test:
	cd ${WRKSRC} && ${PYTHON_CMD} -m unittest2 discover

.include <bsd.port.mk>
