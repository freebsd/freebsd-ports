# ex:ts=8
# Ports collection makefile for:  UPS
# Version required:     	  3.32
# Date created:			  Mon Feb 03, 1997
# Whom:				  David O'Brien (obrien@FreeBSD.org)
#
# $Id: Makefile,v 1.6 1998/11/11 05:37:17 asami Exp $
#

DISTNAME=	ups-3.33
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_XCONTRIB}  \
		ftp://unix.hensa.ac.uk/pub/misc/unix/ups/  \
		http://www.concerto.demon.co.uk/UPS/
MASTER_SITE_SUBDIR= utilities

PATCHFILES=	ide-333-patch-06oct98.txt.mod
PATCH_SITES=	http://www.concerto.demon.co.uk/UPS/  \
		http://www.freebsd.org/~obrien/

MAINTAINER=     obrien@FreeBSD.org

BROKEN_ELF=	yes
USE_GMAKE=	yes
ALL_TARGET=	ups
MAN1=		ups.1

.include <bsd.port.mk>
