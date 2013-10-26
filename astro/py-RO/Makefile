# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	RO
PORTVERSION=	3.2.0
PORTREVISION=	1
CATEGORIES=	astro python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Package of Python astronomical utilities

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/numpy/core/numeric.py:${PORTSDIR}/math/py-numpy
RUN_DEPENDS:=	${BUILD_DEPENDS}

OPTIONS_DEFINE=		MATPLOTLIB PYFITS PYGAME
OPTIONS_DEFAULT=	PYFITS

MATPLOTLIB_DESC=	Add support for Matplotlib
PYFITS_DESC=		Add Support for PyFITS
PYGAME_DESC=		Add Support for PyGame

NO_STAGE=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=easy_install

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MMATPLOTLIB}
RUN_DEPENDS+=	${PKGNAMEPREFIX}matplotlib>=0.98:${PORTSDIR}/math/py-matplotlib
.endif

.if ${PORT_OPTIONS:MPYFITS}
RUN_DEPENDS+=	${PKGNAMEPREFIX}pyfits>=1.1:${PORTSDIR}/astro/py-pyfits
.endif

.if ${PORT_OPTIONS:MPYGAME}
RUN_DEPENDS+=	${PKGNAMEPREFIX}game>=1.8.1:${PORTSDIR}/devel/py-game
.endif

.include <bsd.port.post.mk>
