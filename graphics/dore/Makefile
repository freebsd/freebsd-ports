# New ports collection makefile for:	dore
# Version required:	6.0
# Date created:		10 February 1995
# Whom:			jkh
#
# $Id: Makefile,v 1.4 1996/03/07 00:21:43 asami Exp $
#

DISTNAME=	pdore-6.0
CATEGORIES=	graphics
MASTER_SITES=   ftp://freefall.freebsd.org/pub/FreeBSD/LOCAL_PORTS/
EXTRACT_SUFX=	.tar.Z

USE_GMAKE=	yes
USE_X11=	yes
WRKSRC=		${WRKDIR}/dore
EXTRACT_CMD=	mkdir -p dore; cd dore; tar
MAKEFILE=	mk.stdx
MAKE_FLAGS=	DORE_LOC=${WRKDIR} CFLAGS=-O2 MAKEFLAGS=m -f
ALL_TARGET=

.include <bsd.port.mk>
