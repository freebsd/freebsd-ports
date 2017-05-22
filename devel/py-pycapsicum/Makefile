# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pycapsicum
PORTVERSION=	1.0
CATEGORIES=	devel security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	stillson@gmail.com
COMMENT=	Python interface to capsicum security

LICENSE=	BSD3CLAUSE

BROKEN_powerpc64=	fails to compile: _pycapsicum.c: error: 'for' loop initial declaration used outside C99 mode

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
