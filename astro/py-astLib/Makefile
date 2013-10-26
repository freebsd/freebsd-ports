# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	astLib
PORTVERSION=	0.6.1
PORTREVISION=	2
CATEGORIES=	astro python
MASTER_SITES=	SF
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Astronomy modules for Python

BUILD_DEPENDS=	${PYNUMPY} \
		${PKGNAMEPREFIX}scipy>=0.7.0:${PORTSDIR}/science/py-scipy \
		${PKGNAMEPREFIX}imaging>=1.1.6:${PORTSDIR}/graphics/py-imaging \
		${PKGNAMEPREFIX}pyfits>=1.1:${PORTSDIR}/astro/py-pyfits \
		${PKGNAMEPREFIX}matplotlib>=0.98:${PORTSDIR}/math/py-matplotlib
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

.include <bsd.port.mk>
