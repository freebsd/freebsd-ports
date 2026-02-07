PORTNAME=	flask-sqlalchemy
PORTVERSION=	3.1.1
CATEGORIES=	databases python
MASTER_SITES=	PYPI \
		https://github.com/pallets-eco/flask-sqlalchemy/releases/download/${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	flask_sqlalchemy-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Add SQLAlchemy support to your Flask application
WWW=		https://flask-sqlalchemy.palletsprojects.com/en/3.1.x/ \
		https://github.com/pallets-eco/flask-sqlalchemy

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.rst

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>=0<4:devel/py-flit-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flask>=2.2.5:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy20>=2.0.16:databases/py-sqlalchemy20@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest

NO_ARCH=	yes
TEST_ENV=	PYTHONPATH=${STAGEDIR}${PYTHON_SITELIBDIR}

.include <bsd.port.mk>
