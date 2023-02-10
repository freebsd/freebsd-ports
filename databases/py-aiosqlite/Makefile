PORTNAME=	aiosqlite
PORTVERSION=	0.17.0
CATEGORIES=	databases python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	romain@FreeBSD.org
COMMENT=	AsyncIO bridge to the standard sqlite3 module for Python 3.5+
WWW=		https://pypi.python.org/pypi/aiosqlite

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR}

USES=		python:3.5+
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
