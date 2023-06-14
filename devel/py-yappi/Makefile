PORTNAME=	yappi
PORTVERSION=	1.4.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Yet Another Python Profiler
WWW=		https://github.com/sumerc/yappi

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gevent>=20.6.2:devel/py-gevent@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils unittest

TEST_ARGS=	discover -s tests
TEST_ENV=	PYTHONPATH=${STAGEDIR}${PYTHON_SITELIBDIR}

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
