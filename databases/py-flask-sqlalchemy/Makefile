PORTNAME=	flask-sqlalchemy
PORTVERSION=	3.0.3
PORTREVISION=	2
CATEGORIES=	databases python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Flask-SQLAlchemy-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Add SQLAlchemy support to your Flask application
WWW=		https://github.com/pallets-eco/flask-sqlalchemy

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.rst

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pdm-pep517>=1.0.0:devel/py-pdm-pep517@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flask>=2.2:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy14>=1.4.18:databases/py-sqlalchemy14@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes
TEST_ENV=	PYTHONPATH=${STAGEDIR}${PYTHON_SITELIBDIR}

.include <bsd.port.mk>
