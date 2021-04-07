PORTNAME=	volk
DISTVERSIONPREFIX=	v
DISTVERSION=	2.2.1
CATEGORIES=	devel comms hamradio

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Vector-Optimized Library of Kernels

LICENSE=	GPLv3

LIB_DEPENDS=	liborc-0.4.so:devel/orc
BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/mako/__init__.py:textproc/py-mako@${PY_FLAVOR}

USES=		cmake compiler:c++11-lang python:3.5+

USE_GITHUB=	yes
GH_ACCOUNT=	gnuradio

USE_LDCONFIG=	yes

.include <bsd.port.mk>
