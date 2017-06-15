# Created by: antoine@FreeBSD.org
# $FreeBSD$

PORTNAME=	weakrefmethod
PORTVERSION=	1.0.3
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	WeakMethod class for storing bound methods using weak references

LICENSE=	PSFL
LICENSE_FILE=	${WRKSRC}/LICENSE

NO_ARCH=	yes
USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} >= 3400
IGNORE=		is included in python 3.4+
.endif

.include <bsd.port.post.mk>
