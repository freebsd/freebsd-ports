# New ports collection makefile for:   squeak
# Version required:    1.18
# Date created:        25 April 1997
# Whom:                jesse
#
# $Id: Makefile,v 1.3 1998/11/28 02:18:44 asami Exp $
#

DISTNAME=      Squeak-1.18
PKGNAME=       squeak-1.18
CATEGORIES=    lang
MASTER_SITES=  ftp://ftp.create.ucsb.edu/pub/Smalltalk/Squeak/unix/

MAINTAINER=    jesse@cs.uni-magdeburg.de

BROKEN=		upgrade

USE_XLIB=	yes
WRKSRC=         $(WRKDIR)/Squeak-1.18/src

do-install:
	${INSTALL_PROGRAM} $(WRKSRC)/SqueakVM $(PREFIX)/bin
	${MKDIR} $(PREFIX)/share/squeak 
	${INSTALL_DATA} $(WRKSRC)/../image/SqueakV1.sources $(PREFIX)/share/squeak
	${INSTALL_DATA} $(WRKSRC)/../image/Squeak1.18.image $(PREFIX)/share/squeak
	${INSTALL_DATA} $(WRKSRC)/../image/Squeak1.18.changes $(PREFIX)/share/squeak

.include <bsd.port.mk>
