# $FreeBSD$

PORTNAME=	aiosqlite
PORTVERSION=	0.11.0
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	romain@FreeBSD.org
COMMENT=	AsyncIO bridge to the standard sqlite3 module for Python 3.5+

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR}

USES=		python:3.5+
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
