# Created by: Grzegorz Blach <gblach@FreeBSD.org>
# $FreeBSD$

PORTNAME=	efl
PORTVERSION=	1.20.0
PORTREVISION=	2
CATEGORIES=	devel python enlightenment
MASTER_SITES=	http://download.enlightenment.org/rel/bindings/python/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-efl-${PORTVERSION}

MAINTAINER=	enlightenment@FreeBSD.org
COMMENT=	Python bindings for EFL and Elementary

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	multi

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbus>=0.83:devel/py-dbus@${PY_FLAVOR}
LIB_DEPENDS=	libefl.so:devel/efl
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbus>=0.83:devel/py-dbus@${PY_FLAVOR}

DIST_SUBDIR=	enlightenment
USES=		pkgconfig python:-3.6 tar:xz
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
