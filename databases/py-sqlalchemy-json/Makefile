PORTNAME=	sqlalchemy-json
PORTVERSION=	0.6.0
CATEGORIES=	databases python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	JSON type with nested change tracking for SQLAlchemy
WWW=		https://github.com/edelooff/sqlalchemy-json

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlalchemy14>=0.7:databases/py-sqlalchemy14@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
