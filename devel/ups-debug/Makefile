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
MASTER_SITES=	${MASTER_SITE_XCONTRIB}  \
		ftp://unix.hensa.ac.uk/pub/misc/unix/ups/  \
		http://www.concerto.demon.co.uk/UPS/
MASTER_SITE_SUBDIR= utilities

PATCHFILES=	rga-332-patch-17jul98.txt
PATCH_SITES=	http://www.concerto.demon.co.uk/UPS/

MAINTAINER=     obrien@FreeBSD.org

OSVERSION!=	sysctl -n kern.osreldate
.if ${OSVERSION} >= 300000
BROKEN=	"During build: Libvar_addrs[0] is not constant"
.endif

USE_GMAKE=	yes
ALL_TARGET=	ups
MAN1=		ups.1

.include <bsd.port.mk>
