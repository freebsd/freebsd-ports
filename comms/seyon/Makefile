# New ports collection makefile for:	seyon
# Date created:		3 October 1994
# Whom:			Michael Elbel (me)
#
# $FreeBSD$
#

PORTNAME=	seyon
PORTVERSION=	2.14b
CATEGORIES=	comms
MASTER_SITES=	ftp://sipb.mit.edu/pub/seyon/
DISTNAME=	Seyon-${PORTVERSION}
EXTRACT_SUFX=	-tar.Z

MAINTAINER=	me@FreeBSD.org
COMMENT=	A communications package for the X Window system

WRKSRC=		${WRKDIR}/seyon
USE_IMAKE=	yes

MAN1=		seyon.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500113
BROKEN=		"Does not compile on FreeBSD ${OSVERSION} (missing header)"
.endif

.include <bsd.port.post.mk>
