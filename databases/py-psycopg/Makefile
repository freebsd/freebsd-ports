# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	psycopg
PORTVERSION=	3.0.9
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	PostgreSQL database adapter for Python

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		pgsql python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	C POOL
OPTIONS_DEFAULT=C POOL
C_DESC=		C extension support
POOL_DESC=	Connection pool support

C_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}psycopg-c>=${PORTVERSION}:databases/py-psycopg-c@${PY_FLAVOR}
POOL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psycopg-pool>=0:databases/py-psycopg-pool@${PY_FLAVOR}

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 30800
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}typing-extensions>=3.10:devel/py-typing-extensions@${PY_FLAVOR}
.endif

.if ${PYTHON_REL} < 30900
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}backports.zoneinfo>=0.2.0:devel/py-backports.zoneinfo@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
