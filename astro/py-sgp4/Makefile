PORTNAME=	sgp4
PORTVERSION=	2.21
CATEGORIES=	astro python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Python version of the SGP4 satellite position library

LICENSE=	MIT

#USE_GITHUB=	yes
#GH_ACCOUNT=	brandon-rhodes
#GH_PROJECT=	python-sgp4

USES=		python:3.7+
USE_PYTHON=	distutils
.if !defined(WITH_DEBUG)
LDFLAGS+=	-s
.endif

.include <bsd.port.mk>
