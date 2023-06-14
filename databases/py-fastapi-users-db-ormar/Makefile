PORTNAME=	fastapi-users-db-ormar
DISTVERSION=	1.0.0
CATEGORIES=	databases python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	meka@tilda.center
COMMENT=	FastAPI-Users Ormar database adapter
WWW=		https://github.com/fastapi-users/fastapi-users-db-ormar

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}fastapi-users>=6.1.2:www/py-fastapi-users@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ormar>=0.10.16:databases/py-ormar@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
