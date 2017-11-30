# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	RO
PORTVERSION=	3.6.9
CATEGORIES=	astro python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Package of Python astronomical utilities

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/numpy/core/numeric.py:math/py-numpy@${FLAVOR}
RUN_DEPENDS:=	${BUILD_DEPENDS}

OPTIONS_DEFINE=		MATPLOTLIB PYFITS PYGAME
OPTIONS_DEFAULT=	PYFITS

MATPLOTLIB_DESC=	Add support for Matplotlib
PYFITS_DESC=		Add Support for PyFITS
PYGAME_DESC=		Add Support for PyGame

USES=		python
USE_PYTHON=	autoplist distutils

MATPLOTLIB_RUN_DEPENDS=	${PKGNAMEPREFIX}matplotlib>=0.98:math/py-matplotlib@${FLAVOR}
PYFITS_RUN_DEPENDS=	${PKGNAMEPREFIX}pyfits>=1.1:astro/py-pyfits@${FLAVOR}
PYGAME_RUN_DEPENDS=	${PKGNAMEPREFIX}game>=1.8.1:devel/py-game@${FLAVOR}

.include <bsd.port.mk>
