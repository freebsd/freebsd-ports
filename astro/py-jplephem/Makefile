PORTNAME=	jplephem
PORTVERSION=	2.23
CATEGORIES=	astro python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Python version of NASA DE4xx ephemerides
WWW=		https://github.com/brandon-rhodes/python-jplephem

LICENSE=	MIT

BUILD_DEPENDS=	${PYNUMPY}
RUN_DEPENDS=	${PYNUMPY}

#USE_GITHUB=	yes
#GH_ACCOUNT=	brandon-rhodes
#GH_PROJECT=	python-jplephem

USES=		python
USE_PYTHON=	distutils
NO_ARCH=	yes

.include <bsd.port.mk>
