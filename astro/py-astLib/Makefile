# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	astLib
PORTVERSION=	0.7.0
PORTREVISION=	1
CATEGORIES=	astro python
MASTER_SITES=	SF
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Astronomy modules for Python

LICENSE=	LGPL21

BUILD_DEPENDS=	${PYNUMPY} \
		${PKGNAMEPREFIX}scipy>=0.7.0:${PORTSDIR}/science/py-scipy \
		${PKGNAMEPREFIX}imaging>=1.1.6:${PORTSDIR}/graphics/py-imaging \
		${PKGNAMEPREFIX}pyfits>=1.1:${PORTSDIR}/astro/py-pyfits \
		${PKGNAMEPREFIX}matplotlib>=0.98:${PORTSDIR}/math/py-matplotlib
RUN_DEPENDS:=	${BUILD_DEPENDS}

PORTSCOUT=	skipv:0.15,0.17,0.17.1 # incorrect versioning upstream

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

.include <bsd.port.mk>
