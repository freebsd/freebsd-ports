# Created by: Olivier Duchateau <duchateau.olivier@gmail.com>

PORTNAME=	flask-sqlalchemy
PORTVERSION=	2.5.1
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Flask-SQLAlchemy-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Add SQLAlchemy support to your Flask application

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.rst

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Flask>=0.10:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy12>=0.8:databases/py-sqlalchemy12@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
