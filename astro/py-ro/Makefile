# Created by: Wen Heping <wenheping@gmail.com>

PORTNAME=	ro
PORTVERSION=	3.6.9
PORTREVISION=	4
CATEGORIES=	astro python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	RO-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Package of Python astronomical utilities

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/docs/License.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=0,1:math/py-numpy@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	ASTROPY MATPLOTLIB PYGAME
OPTIONS_DEFAULT=ASTROPY
ASTROPY_DESC=	Add Support for Astropy
MATPLOTLIB_DESC=Add support for Matplotlib
PYGAME_DESC=	Add Support for PyGame

ASTROPY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}astropy>=0:astro/py-astropy@${PY_FLAVOR}
MATPLOTLIB_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}matplotlib>=0.98:math/py-matplotlib@${PY_FLAVOR}
PYGAME_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}game>=0:devel/py-game@${PY_FLAVOR}

.include <bsd.port.mk>
