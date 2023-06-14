PORTNAME=	cson
DISTVERSION=	0.8
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Coffescript Object Notation (CSON) parser for Python 2 and Python 3
WWW=		https://github.com/avakar/pycson

LICENSE=	MIT

RUN_DEPENDS=	${PKGNAMEPREFIX}speg>=0.3:devel/py-speg@${PY_FLAVOR}
TEST_DEPENDS=	${PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${PY_FLAVOR} \
		${PKGNAMEPREFIX}speg>=0.3:devel/py-speg@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} -m pytest test

.include <bsd.port.mk>
