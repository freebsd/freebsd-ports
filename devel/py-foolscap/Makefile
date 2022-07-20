PORTNAME=	foolscap
PORTVERSION=	21.7.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	RPC protocol for Twisted Python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}openssl>=0:security/py-openssl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}twisted>=16.0.0:devel/py-twisted@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mock>=0:devel/py-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}txi2p-tahoe>=0.3.2:devel/py-txi2p-tahoe@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}txtorcon>=19.0.0:security/py-txtorcon@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils unittest

NO_ARCH=	yes
TEST_ARGS=	discover -s src
TEST_ENV=	PYTHONPATH=${STAGEDIR}${PYTHON_SITELIBDIR}

OPTIONS_DEFINE=	I2P TOR
I2P_DESC=	I2P (Invisible Internet Project) support
TOR_DESC=	Tor support

I2P_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}txi2p-tahoe>=0.3.5:devel/py-txi2p-tahoe@${PY_FLAVOR}
TOR_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}txtorcon>=19.0.0:security/py-txtorcon@${PY_FLAVOR}

.include <bsd.port.mk>
