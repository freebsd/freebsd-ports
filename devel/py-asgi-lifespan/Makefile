PORTNAME=	asgi-lifespan
DISTVERSION=	2.0.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	meka@tilda.center
COMMENT=	Programmatic startup/shutdown of ASGI apps
WWW=		https://github.com/florimondmanca/asgi-lifespan

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sniffio>0:devel/py-sniffio@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-trio>0:devel/py-pytest-trio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}starlette>0:www/py-starlette@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}trio>0:net/py-trio@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils pytest

TEST_ENV=	PYTHONPATH=${WRKSRC}/src

NO_ARCH=	yes

.include <bsd.port.mk>
