# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	aipy
PORTVERSION=	2.1.0
PORTREVISION=	1
CATEGORIES=	astro python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Astronomical Interferometry in PYthon

BUILD_DEPENDS=	${PYNUMPY} \
		${PYTHON_SITELIBDIR}/ephem/__init__.py:${PORTSDIR}/astro/pyephem \
		${PKGNAMEPREFIX}pyfits>=1.1:${PORTSDIR}/astro/py-pyfits \
		${PKGNAMEPREFIX}matplotlib>=0.98:${PORTSDIR}/math/py-matplotlib
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

.include <bsd.port.mk>
