# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	sgp4
PORTVERSION=	2.17
CATEGORIES=	astro python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Python version of the SGP4 satellite position library

LICENSE=	MIT

USE_GITHUB=	yes
GH_ACCOUNT=	brandon-rhodes
GH_PROJECT=	python-sgp4

USES=		python:3.7+ shebangfix
USE_PYTHON=	distutils
SHEBANG_FILES=	bin/print_attributes.py
.if !defined(WITH_DEBUG)
LDFLAGS+=	-s
.endif

.include <bsd.port.mk>
