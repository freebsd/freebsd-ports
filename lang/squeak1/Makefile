# New ports collection makefile for:   squeak
# Version required:    1.18
# Date created:        25 April 1997
# Whom:                jesse
#
# $Id$
#

DISTNAME=      Squeak-1.18
PKGNAME=       squeak-1.18
CATEGORIES=    lang
MASTER_SITES=  ftp://ftp.cs.uni-magdeburg.de/pub/fbsd/

MAINTAINER=    jesse@cs.uni-magdeburg.de

WRKSRC=         $(WRKDIR)/Squeak-1.18/src

do-install:
	${INSTALL_PROGRAM} $(WRKSRC)/SqueakVM $(PREFIX)/bin
	${MKDIR} $(PREFIX)/share/squeak 
	${INSTALL_DATA} $(WRKSRC)/../image/SqueakV1.sources $(PREFIX)/share/squeak
	${INSTALL_DATA} $(WRKSRC)/../image/Squeak1.18.image $(PREFIX)/share/squeak
	${INSTALL_DATA} $(WRKSRC)/../image/Squeak1.18.changes $(PREFIX)/share/squeak

.include <bsd.port.mk>
