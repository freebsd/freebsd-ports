# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	aipy
PORTVERSION=	2.1.8
CATEGORIES=	astro python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Astronomical Interferometry in PYthon

BUILD_DEPENDS=	${PYNUMPY} \
		${PYTHON_SITELIBDIR}/ephem/__init__.py:astro/pyephem@${FLAVOR} \
		${PKGNAMEPREFIX}pyfits>=1.1:astro/py-pyfits@${FLAVOR} \
		${PKGNAMEPREFIX}matplotlib>=0.98:math/py-matplotlib@${FLAVOR}
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		python:2.7
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
