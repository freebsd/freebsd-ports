# New ports collection makefile for:	hobbes-icons-xpm3
# Version required:	1.0
# Date created:		19 October 1996
# Whom:			pgs
#
# $Id: Makefile,v 1.5 1998/02/20 18:39:48 steve Exp $
#

DISTNAME=	hobbes-icons-xpm3
PKGNAME=	hobbes-icons-xpm3-1.0
CATEGORIES=	graphics
MASTER_SITES=   ftp://ftp.x.org/R5contrib/  \
		ftp://ftp.duke.edu/pub/X11/R5contrib/  \
		ftp://ftp.sunet.se/pub/X11/R5contrib/  \
		ftp://ftp.pacbell.com/X11/R5contrib/

MAINTAINER=	giffunip@asme.org

USE_X_PREFIX=	yes
NO_BUILD=	yes

# Where it will be installed (change pkg/PLIST if you change this)
LIBDIR=		${PREFIX}/include/X11/pixmaps

do-install:
	${MKDIR} ${LIBDIR}
	${CP} -R ${WRKSRC}/* ${LIBDIR}
	chown -R ${BINOWN}:${BINGRP} ${LIBDIR}
	-${RM} ${LIBDIR}/README
	-${RM} ${LIBDIR}/readem.shar

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/hobbes-icons-xpm3
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/hobbes-icons-xpm3
	${INSTALL_SCRIPT} ${WRKSRC}/*.shar ${PREFIX}/share/doc/hobbes-icons-xpm3
.endif

.include <bsd.port.mk>
