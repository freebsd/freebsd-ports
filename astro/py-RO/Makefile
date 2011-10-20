# New ports collection makefile for:	py-RO
# Date created:				Dec 26, 2010
# Whom:					Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	RO
PORTVERSION=	2.9.3
CATEGORIES=	astro python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Package of Python astronomical utilities

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/numpy/core/numeric.py:${PORTSDIR}/math/py-numpy
RUN_DEPENDS=	${BUILD_DEPENDS}

OPTIONS=	MATPLOTLIB "Add support for Matplotlib" Off \
		PYFITS     "Add Support for PyFITS" On \
		PYGAME     "Add Support for PyGame" Off

USE_PYTHON=	yes
USE_PYDISTUTILS=easy_install

.include <bsd.port.pre.mk>

.if defined(WITH_MATPLOTLIB)
RUN_DEPENDS+=	${PKGNAMEPREFIX}matplotlib>=0.98:${PORTSDIR}/math/py-matplotlib
.endif

.if !defined(WITHOUT_PYFITS)
RUN_DEPENDS+=	${PKGNAMEPREFIX}pyfits>=1.1:${PORTSDIR}/astro/py-pyfits
.endif

.if defined(WITH_PYGAME)
RUN_DEPENDS+=	${PKGNAMEPREFIX}game>=1.8.1:${PORTSDIR}/devel/py-game
.endif

.include <bsd.port.post.mk>
