# New ports collection makefile for:    x48
# Version required:  0.4.0   
# Date created:         Thu Oct 24 13:10:59 CDT 1996
# Whom:                 erich@FreeBSD.org
#
# $Id: Makefile,v 1.1.1.1 1996/10/24 20:41:37 erich Exp $
#

DISTNAME=	x48-0.4.0
CATEGORIES=	emulators
MASTER_SITES=	ftp://sunsite.unc.edu/pub/Linux/system/Emulators/

MAINTAINER=	erich@FreeBSD.org

USE_IMAKE=	yes
NO_INSTALL_MANPAGES=	yes

post-install:
	${MKDIR} ${PREFIX}/share/x48
	${CP} ${WRKSRC}/README ${PREFIX}/share/x48/README-x48
	${CP} ${WRKSRC}/doc/CARDS.doc ${WRKSRC}/doc/ROMDump.doc ${PREFIX}/share/x48

.include <bsd.port.mk>
