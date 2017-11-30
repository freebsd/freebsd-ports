# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	redis
PORTVERSION=	2.10.6
CATEGORIES=	databases python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Python client for Redis key-value store

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	redis-server:databases/redis

OPTIONS_DEFINE=	HIREDIS

HIREDIS_DESC=	High performance response parser (via hiredis)

HIREDIS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hiredis>0:databases/py-hiredis@${FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist concurrent

USE_GITHUB=	yes
GH_ACCOUNT=	andymccurdy
GH_PROJECT=	${PORTNAME}-py

NO_ARCH=	yes

# Needs redis-server to be running
do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
