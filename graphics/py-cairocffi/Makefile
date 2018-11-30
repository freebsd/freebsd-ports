# Created by: Dave Cottlehuber <dch@skunkwerks.at>
# $FreeBSD$

PORTNAME=	cairocffi
PORTVERSION=	0.8.0
PORTREVISION=	2
CATEGORIES=	graphics python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dch@skunkwerks.at
COMMENT=	Cairo cffi-based cairo bindings for Python

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>0:devel/py-cffi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xcffib>=0.5.0:x11/py-xcffib@${PY_FLAVOR}
BUILD_DEPENDS=	${RUN_DEPENDS}

USES=		python
USE_PYTHON=	distutils cffi py3kplist
USE_GNOME=	cairo

.include <bsd.port.mk>
