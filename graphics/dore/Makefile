# New ports collection makefile for:	dore
# Version required:	6.0
# Date created:		10 February 1995
# Whom:			jkh
#
# $Id: Makefile,v 1.1.1.1 1994/11/20 16:00:09 torstenb Exp $
#

DISTNAME=	pdore-6.0
MASTER_SITES=   ftp://freefall.cdrom.com/pub/FreeBSD/LOCAL_PORTS/
USE_GMAKE=	yes
PREFIX=		${X11BASE}
EXTRACT_SUFX=	.tar.Z
WRKDIR=		${.CURDIR}/work/dore
MAKEFILE=	mk.stdx
MAKE_FLAGS=	DORE_LOC=${WRKDIR}/.. CFLAGS=-O2 MAKEFLAGS=m -f
ALL_TARGET=
NO_WRKSUBDIR=	yes

.include <bsd.port.mk>
