# ex:ts=8
# Ports collection makefile for:  UPS
# Version required:     	  3.32
# Date created:			  Mon Feb 03, 1997
# Whom:				  David O'Brien (obrien@FreeBSD.org)
#
# $Id: Makefile,v 1.2 1998/06/24 07:31:06 obrien Exp $
#

DISTNAME=	ups-3.32
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR= utilities

MAINTAINER=     obrien@FreeBSD.org

OSVERSION!=	sysctl -n kern.osreldate
.if ${OSVERSION} >= 300000
BROKEN=	"During build: Libvar_addrs[0] is not constant"
.endif

ALL_TARGET=	ups ups
MAN1=		ups.1

.include <bsd.port.mk>
