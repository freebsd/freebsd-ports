PORTNAME=	sgp4
PORTVERSION=	2.25
CATEGORIES=	astro python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Python version of the SGP4 satellite position library
WWW=		https://github.com/brandon-rhodes/python-sgp4

LICENSE=	MIT

#USE_GITHUB=	yes
#GH_ACCOUNT=	brandon-rhodes
#GH_PROJECT=	python-sgp4

USES=		python
USE_PYTHON=	distutils
.if !defined(WITH_DEBUG)
LDFLAGS+=	-s
.endif

.include <bsd.port.mk>
