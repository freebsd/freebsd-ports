# $FreeBSD$

PORTNAME=	volk
DISTVERSIONPREFIX=	v
DISTVERSION=	2.2.0
CATEGORIES=	devel comms hamradio

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	VOLK is the Vector-Optimized Library of Kernels

LICENSE=	GPLv3

LIB_DEPENDS+=	liborc-0.4.so:devel/orc
BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/mako/__init__.py:textproc/py-mako@${PY_FLAVOR}

USES=		cmake python:3.5+

USE_GITHUB=	yes
GH_ACCOUNT=	gnuradio
GH_PROJECT=	volk
GH_TAGNAME=	v2.2.0

USE_LDCONFIG=	yes

.include <bsd.port.mk>
