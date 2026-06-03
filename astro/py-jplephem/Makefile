PORTNAME=	jplephem
PORTVERSION=	2.24
PORTREVISION=	2
CATEGORIES=	astro python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Python version of NASA DE4xx ephemerides
WWW=		https://github.com/brandon-rhodes/python-jplephem

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR}

#USE_GITHUB=	yes
#GH_ACCOUNT=	brandon-rhodes
#GH_PROJECT=	python-jplephem

USES=		python
USE_PYTHON=	distutils
NO_ARCH=	yes

.include <bsd.port.mk>
