# New ports collection makefile for:	dore
# Version required:	6.0
# Date created:		10 February 1995
# Whom:			jkh
#
# $Id: Makefile,v 1.2 1995/04/01 12:45:49 jkh Exp $
#

DISTNAME=	pdore-6.0
CATEGORIES+=	graphics
MASTER_SITES=   ftp://freefall.cdrom.com/pub/FreeBSD/LOCAL_PORTS/
EXTRACT_SUFX=	.tar.Z

USE_GMAKE=	yes
USE_X11=	yes
WRKDIR=		${.CURDIR}/work/dore
NO_WRKSUBDIR=	yes
MAKEFILE=	mk.stdx
MAKE_FLAGS=	DORE_LOC=${WRKDIR}/.. CFLAGS=-O2 MAKEFLAGS=m -f
ALL_TARGET=

.include <bsd.port.mk>
