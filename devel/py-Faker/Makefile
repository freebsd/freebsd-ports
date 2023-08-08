PORTNAME=	Faker
DISTVERSION=	15.1.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	alfred@FreeBSD.org
COMMENT=	Python package that generates fake data for you
WWW=		https://github.com/joke2k/faker

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dateutil>=2.4:devel/py-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=3.10.0.1:devel/py-typing-extensions@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}freezegun>0:devel/py-freezegun@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}random2>0:math/py-random2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}validators>0:devel/py-validators@${PY_FLAVOR}

USES=		pytest python
USE_PYTHON=	autoplist concurrent distutils

CONFLICTS_INSTALL=	rubygem-faker

NO_ARCH=	yes

.include <bsd.port.mk>
