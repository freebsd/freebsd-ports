# ex:ts=8
# Ports collection makefile for:  UPS
# Date created:			  Mon Feb 03, 1997
# Whom:				  David O'Brien (obrien@FreeBSD.org)
#
# $FreeBSD$
#

PORTNAME=	ups
PORTVERSION=	3.35.b13
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_XCONTRIB}  \
		http://www.concerto.demon.co.uk/UPS/src/  \
		ftp://unix.hensa.ac.uk/pub/misc/unix/ups/
MASTER_SITE_SUBDIR= utilities
DISTNAME=	ups-3.35-beta13

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	Source level C debugger that runs under X11

BROKEN=		"Does not build"

GNU_CONFIGURE=	yes
USE_XLIB=	yes
USE_GMAKE=	yes
ALL_TARGET=	ups
MAN1=		ups.1

#It will build for either a.out or ELF depending on your 'objformat'.
#To explicitly build for a format do :
#	./configure --with-elf
#	make
#or
#	./configure --with-aout
#	make

post-install:
	@${MKDIR} ${PREFIX}/share/doc/ups
	@${INSTALL_MAN} ${WRKSRC}/FAQ ${WRKSRC}/README ${WRKSRC}/Ups \
		${PREFIX}/share/doc/ups
	@${INSTALL_DATA} ${WRKSRC}/Ups ${X11BASE}/lib/X11/app-defaults

.include <bsd.port.mk>
