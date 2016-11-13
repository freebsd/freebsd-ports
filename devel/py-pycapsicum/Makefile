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

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 1000000
IGNORE=	requires FreeBSD 10.0 or newer
.endif

.include <bsd.port.post.mk>
