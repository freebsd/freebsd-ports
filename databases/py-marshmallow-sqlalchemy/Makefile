# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	marshmallow-sqlalchemy
PORTVERSION=	0.23.1
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	SQLAlchemy integration with the marshmallow serialization library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}marshmallow>=2.15.2:devel/py-marshmallow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy12>=1.2.0:databases/py-sqlalchemy12@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-lazy-fixture>=0:devel/py-pytest-lazy-fixture@${PY_FLAVOR} \

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

do-test:
	cd ${WRKSRC} && ${SETENV} PYTHONPATH=${WRKSRC}/build/lib ${PYTHON_CMD} -m pytest -rs -v

.include <bsd.port.mk>
