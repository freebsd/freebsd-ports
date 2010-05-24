# New ports collection makefile for:	py-ctypes
# Date created:		12 May 2003
# Whom:			Hye-Shik Chang <perky@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ctypes
PORTVERSION=	1.0.1
CATEGORIES=	devel python
MASTER_SITES=	SF
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	gcooper@FreeBSD.org
COMMENT=	Python module allowing to create and manipulate C data types

USE_PYTHON=	yes
USE_PYDISTUTILS=yes

ONLY_FOR_ARCHS=	i386 amd64 alpha powerpc sparc64

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} >= 250
IGNORE=	ctypes ships with Python 2.5.x
.endif

.include <bsd.port.post.mk>
