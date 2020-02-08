# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	geoalchemy
PORTVERSION=	0.7.2
PORTREVISION=	4
CATEGORIES=	databases geography python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	GeoAlchemy-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Using SQLAlchemy with Spatial Databases

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlalchemy12>=0.6.1:databases/py-sqlalchemy12@${PY_FLAVOR}

USES=		python:2.7
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
