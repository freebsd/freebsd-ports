# ex:ts=8
# Ports collection makefile for:  UPS
# Date created:			  Mon Feb 03, 1997
# Whom:				  David O'Brien (obrien@FreeBSD.org)
#
# $FreeBSD$
#

DISTNAME=	ups-3.34beta
PKGNAME=	ups-3.34b
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_XCONTRIB}  \
		ftp://unix.hensa.ac.uk/pub/misc/unix/ups/  \
		http://www.concerto.demon.co.uk/UPS/
MASTER_SITE_SUBDIR= utilities

MAINTAINER=	obrien@FreeBSD.org

GNU_CONFIGURE=	yes
USE_XLIB=	yes
USE_GMAKE=	yes
ALL_TARGET=	ups
MAN1=		ups.1

post-install:
	@${MKDIR} ${PREFIX}/share/doc/ups
	@${INSTALL_MAN} ${WRKSRC}/FAQ ${WRKSRC}/README ${WRKSRC}/Ups \
		${PREFIX}/share/doc/ups
	@${INSTALL_DATA} ${WRKSRC}/Ups ${X11BASE}/lib/X11/app-defaults

.include <bsd.port.mk>
