# New ports collection makefile for:	xbattle
# Version required:     15.4.1
# Date created:         6 Apr 97
# Whom:                 Pedro Giffuni
#
# $Id: Makefile,v 1.2 1998/01/27 02:08:58 fenner Exp $
#

DISTNAME=	xbattle-5.4.1
CATEGORIES=	games
MASTER_SITES=	ftp://cns-ftp.bu.edu/pub/xbattle/

MAINTAINER=	giffunip@asme.org

USE_IMAKE=	yes

post-install:
	$(MKDIR) $(PREFIX)/etc/xbattle
	$(CP) -R $(WRKSRC)/xbos $(PREFIX)/etc/xbattle/
	$(CP) -R $(WRKSRC)/xbts $(PREFIX)/etc/xbattle/
	$(CP) -R $(WRKSRC)/xbas $(PREFIX)/etc/xbattle/
.if !defined(NOPORTDOCS)
	$(MKDIR) $(PREFIX)/share/doc/xbattle
	$(CP) $(WRKSRC)/tutorial* $(PREFIX)/share/doc/xbattle/ 
	$(CP) $(WRKSRC)/README $(PREFIX)/share/doc/xbattle/ 
.endif

.include <bsd.port.mk>
