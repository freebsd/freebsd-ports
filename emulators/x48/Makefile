# New ports collection makefile for:    x48
# Version required:  0.4.0   
# Date created:         Thu Oct 24 13:10:59 CDT 1996
# Whom:                 erich@FreeBSD.org
#
# $Id$
#

DISTNAME=	x48-0.4.0
CATEGORIES+=	emulators
MASTER_SITES=	ftp://sunsite.unc.edu/pub/Linux/system/Emulators/

MAINTAINER=	erich@FreeBSD.org

USE_IMAKE=	yes
NO_INSTALL_MANPAGES=	yes

post-install:
	mkdir -p ${PREFIX}/share/x48
	cp ${WRKSRC}/README ${PREFIX}/share/x48/README-x48
	cp ${WRKSRC}/doc/CARDS.doc ${WRKSRC}/doc/ROMDump.doc ${PREFIX}/share/x48

.include <bsd.port.mk>
