PORTNAME=	oxyde
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.1
CATEGORIES=	databases python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	meka@tilda.center
COMMENT=	High-performance async Python ORM with Rust core
WWW=		https://oxyde.fatalyst.dev/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}msgpack>=1.0:devel/py-msgpack@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oxyde-core>=0.5.0<0.6.0:databases/py-oxyde-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>=2.0:devel/py-pydantic2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typer>=0.24:devel/py-typer@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=9.0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-asyncio>=1.0:devel/py-pytest-asyncio@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	mr-fatalyst
USE_PYTHON=	autoplist concurrent pep517 pytest

BUILD_WRKSRC=	${WRKSRC}/python
INSTALL_WRKSRC=	${WRKSRC}/python
TEST_WRKSRC=	${WRKSRC}/python

NO_ARCH=	yes

.include <bsd.port.mk>
