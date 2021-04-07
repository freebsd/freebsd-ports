PORTNAME=	txredisapi
DISTVERSION=	1.4.7
PORTREVISION=	1
CATEGORIES=	databases python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@skyforge.at
COMMENT=	Non-blocking redis client for python

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

# Keep the RUN_DEPENDS layout similar to the master/synapse/python_dependencies.py file
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}twisted>=0:devel/py-twisted@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mock>=2.0:devel/py-mock@${PY_FLAVOR} \
		redis-server:databases/redis

USES=		python:3.6+
USE_GITHUB=	yes
USE_PYTHON=	autoplist distutils

GH_ACCOUNT=	IlyaSkriblovsky

NO_ARCH=	yes

do-test:
	cd ${WRKSRC} && PYTHONPATH="." trial-${PYTHON_VER} tests

.include <bsd.port.mk>
