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
PKGNAMEPREFIX=	py-
DISTNAME=	PQueue-${PORTVERSION}

MAINTAINER=	perky@fallin.lv

USE_BZIP2=	yes
USE_PYTHON=	yes
GNU_CONFIGURE=	yes
ALL_TARGET=	default

PLIST_SUB=	PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR:S|^${LOCALBASE}/||g}
WRKSRC=		${WRKDIR}/PQueue

.include <bsd.port.mk>
