# ex:ts=8
# Ports collection makefile for:  UPS
# Version required:     	  3.32
# Date created:			  Mon Feb 03, 1997
# Whom:				  David O'Brien (obrien@FreeBSD.org)
#
# $Id: Makefile,v 1.3 1998/08/17 11:22:36 jseger Exp $
#

DISTNAME=	ups-3.32
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR= utilities

MAINTAINER=     obrien@FreeBSD.org

OSVERSION!=	sysctl -n kern.osreldate
.if ${OSVERSION} >= 300000
BROKEN=	"During build: Libvar_addrs[0] is not constant"
.else
BROKEN=	"xc_builtins.c cannot find X11/Xlib.h"
.endif

ALL_TARGET=	ups ups
MAN1=		ups.1

.include <bsd.port.mk>
