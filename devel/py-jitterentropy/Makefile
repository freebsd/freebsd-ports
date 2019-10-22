# $FreeBSD$

PORTNAME=	jitterentropy
PORTVERSION=	0.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Use libjitterentropy to get random bytes

LIB_DEPENDS=	libjitterentropy.so:devel/libjitterentropy

USES=		python:3.6+
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
