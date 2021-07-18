# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	graphene-sqlalchemy
PORTVERSION=	2.3.0
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Graphene SQLAlchemy integration

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}graphene>=2.1.3<3:devel/py-graphene@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}promise>=2.3:devel/py-promise@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.10.0<2:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy14>=1.2<2:databases/py-sqlalchemy14@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
