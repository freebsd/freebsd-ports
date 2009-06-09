# New ports collection makefile for:	seyon
# Date created:		3 October 1994
# Whom:			Michael Elbel (me)
#
# $FreeBSD$
#

PORTNAME=	seyon
PORTVERSION=	2.14b
PORTREVISION=	2
CATEGORIES=	comms
MASTER_SITES=	ftp://sipb.mit.edu/pub/seyon/
DISTNAME=	Seyon-${PORTVERSION}
EXTRACT_SUFX=	-tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A communications package for the X Window system

WRKSRC=		${WRKDIR}/seyon
USE_IMAKE=	yes
USE_XORG=	x11 xext xpm xmu xaw xt sm ice

MAN1=		seyon.1

.include <bsd.port.mk>
