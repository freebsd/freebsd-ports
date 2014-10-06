# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	astLib
PORTVERSION=	0.7.0
PORTREVISION=	3
CATEGORIES=	astro python
MASTER_SITES=	SF
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Astronomy modules for Python

LICENSE=	LGPL21

BUILD_DEPENDS=	${PYNUMPY} \
		${PKGNAMEPREFIX}scipy>=0.7.0:${PORTSDIR}/science/py-scipy \
		${PKGNAMEPREFIX}pillow>0:${PORTSDIR}/graphics/py-pillow \
		${PKGNAMEPREFIX}pyfits>=1.1:${PORTSDIR}/astro/py-pyfits \
		${PKGNAMEPREFIX}matplotlib>=0.98:${PORTSDIR}/math/py-matplotlib
RUN_DEPENDS:=	${BUILD_DEPENDS}

PORTSCOUT=	skipv:0.15,0.17,0.17.1 # incorrect versioning upstream

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
