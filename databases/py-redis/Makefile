# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	redis
PORTVERSION=	3.5.3
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Python client for Redis key-value store

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>=2.7.0:devel/py-pytest@${PY_FLAVOR} \
		redis-server:databases/redis

USES=		python
USE_PYTHON=	distutils autoplist concurrent

OPTIONS_DEFINE=	HIREDIS

HIREDIS_DESC=	High performance response parser (via hiredis)

HIREDIS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hiredis>=0.1.3:databases/py-hiredis@${PY_FLAVOR}

NO_ARCH=	yes
CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}redis2

# Needs redis-server to be running
do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} -m pytest -v -rs

.include <bsd.port.mk>
