# New ports collection makefile for:	py-astLib
# Date created:		23 March, 2009
# Whom:			Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	astLib
PORTVERSION=	0.4.0
CATEGORIES=	astro python
MASTER_SITES=	SF
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A set of python astonomy modules

BUILD_DEPENDS=	${PYNUMPY} \
		${PKGNAMEPREFIX}scipy>=0.7.0:${PORTSDIR}/science/py-scipy \
		${PKGNAMEPREFIX}imaging>=1.1.6:${PORTSDIR}/graphics/py-imaging \
		${PKGNAMEPREFIX}pyfits>=1.1:${PORTSDIR}/astro/py-pyfits \
		${PKGNAMEPREFIX}matplotlib>=0.98:${PORTSDIR}/math/py-matplotlib
RUN_DEPENDS=	${PYNUMPY} \
		${PKGNAMEPREFIX}scipy>=0.7.0:${PORTSDIR}/science/py-scipy \
		${PKGNAMEPREFIX}imaging>=1.1.6:${PORTSDIR}/graphics/py-imaging \
		${PKGNAMEPREFIX}pyfits>=1.1:${PORTSDIR}/astro/py-pyfits \
		${PKGNAMEPREFIX}matplotlib>=0.98:${PORTSDIR}/math/py-matplotlib

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

.include <bsd.port.mk>
