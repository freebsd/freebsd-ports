# Created by: Yuri Victorovich
# $FreeBSD$

PORTNAME=	opuslib
PORTVERSION=	1.1.0
CATEGORIES=	audio python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@rawbw.com
COMMENT=	Python bindings to the libopus, IETF low-delay audio codec

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${LOCALBASE}/lib/libopus.so:audio/opus

USES=		python:2.7
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

.include <bsd.port.mk>
