PORTNAME=	flask-pymongo
DISTVERSION=	2.3.0
PORTREVISION=	1
CATEGORIES=	databases python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Flask-PyMongo-${PORTVERSION}

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	PyMongo support for Flask applications
WWW=		https://flask-pymongo.readthedocs.io/en/latest/ \
		https://pypi.org/project/Flask-PyMongo/

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}vcversioner>0:devel/py-vcversioner@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flask>=1.0:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pymongo>=3.11:databases/py-pymongo@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
