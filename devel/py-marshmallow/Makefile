# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	marshmallow
PORTVERSION=	3.5.2
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Simplified object serialization for Python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dateutil>=2.7.0:devel/py-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}simplejson>=0:devel/py-simplejson@${PY_FLAVOR}

USES=		python:3.5+
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
