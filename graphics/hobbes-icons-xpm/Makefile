# New ports collection makefile for:	hobbes-icons.3000
# Version required:	3000
# Date created:		19 October 1996
# Whom:			pgs
#
# $Id$
#

DISTNAME=	hobbes-icons-xpm
PKGNAME=	hobbes-icons-xpm-1.0
CATEGORIES=	graphics
MASTER_SITES=   ftp://ftp.x.org/R5contrib/  \
		ftp://ftp.duke.edu/pub/X11/R5contrib/  \
		ftp://ftp.informatik.uni-bonn.de/pub/X11/contrib/  \
		ftp://ftp.sunet.se/pub/X11/R5contrib/  \
		ftp://ftp.pacbell.com/X11/R5contrib/

MAINTAINER=	pgiffuni@fps.biblos.unal.edu.co

USE_X11=	yes
NO_BUILD=	yes

# Where it will be installed (will have to change PLIST if you change this
LIBDIR=         ${PREFIX}/lib/X11/xpm3

do-install:
# Very dirty, but it works...
	rm ${WRKSRC)/Makefile
	rm ${WRKSRC)/README
	rm ${WRKSRC)/readem.shar
	${MKDIR} ${PREFIX}/lib/X11/xpm3
	${CP} -R ${WRKSRC}/* ${LIBDIR}
	chown -R ${BINOWN}.${BINGRP}


.include <bsd.port.mk>
