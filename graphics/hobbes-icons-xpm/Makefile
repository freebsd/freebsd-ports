# New ports collection makefile for:	hobbes-icons.3000
# Version required:	3000
# Date created:		19 October 1996
# Whom:			pgs
#
# $Id: Makefile,v 1.2 1997/02/16 10:57:01 asami Exp $
#

DISTNAME=	hobbes-icons-xpm3
PKGNAME=	hobbes-icons-xpm3-1.0
CATEGORIES=	graphics
MASTER_SITES=   ftp://ftp.x.org/R5contrib/  \
		ftp://ftp.duke.edu/pub/X11/R5contrib/  \
		ftp://ftp.sunet.se/pub/X11/R5contrib/  \
		ftp://ftp.pacbell.com/X11/R5contrib/

MAINTAINER=	pgiffuni@fps.biblos.unal.edu.co

USE_X11=	yes
NO_BUILD=	yes

# Where it will be installed (will have to change PLIST if you change this
LIBDIR=         ${PREFIX}/lib/X11/xpm3

do-install:
# Very dirty, but it works...
	-${RM} ${WRKSRC}/README
	-${RM} ${WRKSRC}/readem.shar
	${MKDIR} ${PREFIX}/lib/X11/xpm3
	${CP} -R ${WRKSRC}/* ${LIBDIR}
	chown -R ${BINOWN}.${BINGRP} ${LIBDIR}

.include <bsd.port.mk>
