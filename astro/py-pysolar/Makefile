PORTNAME=	pysolar
DISTVERSION=	0.13
CATEGORIES=	astro science python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Simulate solar irradiation at any point on Earth
WWW=		https://pysolar.org/ \
		https://github.com/pingswept/pysolar

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYNUMPY}

USES=		python
USE_PYTHON=	distutils autoplist pytest

NO_ARCH=	yes

# tests as of 0.13: 84 passed, 343 warnings, 1 error in 14.47s

.include <bsd.port.mk>
