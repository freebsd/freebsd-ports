# ex:ts=8
# Ports collection makefile for:  UPS
# Version required:     	  3.32
# Date created:			  Mon Feb 03, 1997
# Whom:				  David O'Brien (obrien@FreeBSD.org)
#
# $Id: Makefile,v 1.8 1998/11/18 10:16:47 obrien Exp $
#

DISTNAME=	ups-3.33
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_XCONTRIB}  \
		ftp://unix.hensa.ac.uk/pub/misc/unix/ups/  \
		http://www.concerto.demon.co.uk/UPS/
MASTER_SITE_SUBDIR= utilities

PATCHFILES=	ide-333-patch-16nov98.txt
PATCH_SITES=	http://www.concerto.demon.co.uk/UPS/

MAINTAINER=     obrien@FreeBSD.org

BROKEN_ELF=	yes
USE_GMAKE=	yes
ALL_TARGET=	ups
MAN1=		ups.1

post-install:
	@${INSTALL_DATA} ${WRKSRC}/Ups ${X11BASE}/lib/X11/app-defaults

.include <bsd.port.mk>
