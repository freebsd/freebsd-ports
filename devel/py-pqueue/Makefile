# Ports collection Makefile for:	py-pqueue
# Date created:				24 October 2001
# Whom:					Hye-Shik Chang <perky@fallin.lv>
#
# $FreeBSD$
#

PORTNAME=	pqueue
PORTVERSION=	0.2
CATEGORIES=	devel python
MASTER_SITES=	http://www.csse.monash.edu.au/hons/projects/1999/Andrew.Snare/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PQueue-${PORTVERSION}

MAINTAINER=	perky@FreeBSD.org
COMMENT=	Fibonacci-Heap based Priority-Queue Extension for Python

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/pqueuemodule.so
USE_BZIP2=	yes
USE_PYTHON=	yes
GNU_CONFIGURE=	yes
ALL_TARGET=	default

WRKSRC=		${WRKDIR}/PQueue

.include <bsd.port.mk>
