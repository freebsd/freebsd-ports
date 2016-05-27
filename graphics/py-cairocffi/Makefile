# Created by: Dave Cottlehuber <dch@skunkwerks.at>
# $FreeBSD$

PORTNAME=	cairocffi
PORTVERSION=	0.7.2
CATEGORIES=	graphics python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dch@skunkwerks.at
COMMENT=	Cairo cffi-based cairo bindings for Python

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>0:devel/py-cffi
BUILD_DEPENDS=	${RUN_DEPENDS}

USES=		python:2+
USE_PYTHON=	autoplist distutils cffi

.include <bsd.port.mk>
