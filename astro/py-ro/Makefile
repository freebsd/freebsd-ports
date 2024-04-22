PORTNAME=	ro
PORTVERSION=	3.6.9
PORTREVISION=	6
CATEGORIES=	astro python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	RO-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Package of Python astronomical utilities
WWW=		https://staff.washington.edu/rowen/ROPackage/Overview.html \
		https://github.com/ApachePointObservatory/RO

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/docs/License.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=0,1:math/py-numpy@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

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
