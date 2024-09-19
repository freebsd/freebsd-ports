PORTNAME=	duckdb_engine
DISTVERSION=	0.11.2
CATEGORIES=	databases python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	pat@patmaddox.com
COMMENT=	SQLAlchemy driver for DuckDB
WWW=		https://github.com/Mause/duckdb_engine

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}duckdb>=0.4.0:databases/py-duckdb@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy20>0:databases/py-sqlalchemy20@${PY_FLAVOR}

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry>0:devel/py-poetry@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

.include <bsd.port.mk>
