# ex:ts=8
# Ports collection makefile for:  UPS
# Version required:     	  3.32
# Date created:			  Mon Feb 03, 1997
# Whom:				  David O'Brien (obrien@FreeBSD.org)
#
# $Id: Makefile,v 1.9 1999/02/04 18:53:38 obrien Exp $
#

DISTNAME=	ups-3.33-03
PKGNAME=	ups-3.33.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_XCONTRIB}  \
		ftp://unix.hensa.ac.uk/pub/misc/unix/ups/  \
		http://www.concerto.demon.co.uk/UPS/
MASTER_SITE_SUBDIR= utilities

#PATCHFILES=	ide-333-patch-16nov98.txt
#PATCH_SITES=	http://www.concerto.demon.co.uk/UPS/

MAINTAINER=     obrien@FreeBSD.org

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
ALL_TARGET=	ups
MAN1=		ups.1

post-install:
	@${MKDIR} ${PREFIX}/share/doc/ups
	@${INSTALL_MAN} ${WRKSRC}/FAQ ${WRKSRC}/README ${WRKSRC}/Ups \
		${PREFIX}/share/doc/ups
	@${INSTALL_DATA} ${WRKSRC}/Ups ${X11BASE}/lib/X11/app-defaults

.include <bsd.port.mk>
