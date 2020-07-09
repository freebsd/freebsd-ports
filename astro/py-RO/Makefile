# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	RO
PORTVERSION=	3.6.9
PORTREVISION=	4
CATEGORIES=	astro python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Package of Python astronomical utilities

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/docs/License.txt

RUN_DEPENDS=	${PYNUMPY}

USES=		python:3.5+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	ASTROPY MATPLOTLIB PYGAME
OPTIONS_DEFAULT=ASTROPY
ASTROPY_DESC=	Add Support for Astropy
MATPLOTLIB_DESC=Add support for Matplotlib
PYGAME_DESC=	Add Support for PyGame

ASTROPY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}astropy>=0:astro/py-astropy@${PY_FLAVOR}
MATPLOTLIB_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}matplotlib>=0.98:math/py-matplotlib@${PY_FLAVOR}
PYGAME_RUN_DEPENDS=	${PYGAME}

.include <bsd.port.mk>
