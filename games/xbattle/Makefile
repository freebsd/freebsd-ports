# New ports collection makefile for:	xbattle
# Date created:         6 Apr 97
# Whom:                 Pedro Giffuni
#
# $FreeBSD$
#

PORTNAME=	xbattle
PORTVERSION=	5.4.1
CATEGORIES=	games
MASTER_SITES=	ftp://cns-ftp.bu.edu/pub/xbattle/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A concurrent multi-player battle strategy game

USE_IMAKE=	yes
MAN1=		xbattle.1

post-install:
	$(MKDIR) $(PREFIX)/share/xbattle
	$(CP) -R $(WRKSRC)/xbos $(PREFIX)/share/xbattle/
	$(CP) -R $(WRKSRC)/xbts $(PREFIX)/share/xbattle/
	$(CP) -R $(WRKSRC)/xbas $(PREFIX)/share/xbattle/
	@${CHMOD} 755 ${PREFIX}/share/xbattle
	@${CHMOD} 755 ${PREFIX}/share/xbattle/xbas
	@${CHMOD} 644 ${PREFIX}/share/xbattle/xbas/*
	@${CHMOD} 755 ${PREFIX}/share/xbattle/xbos
	@${CHMOD} 644 ${PREFIX}/share/xbattle/xbos/*
	@${CHMOD} 755 ${PREFIX}/share/xbattle/xbts
	@${CHMOD} 644 ${PREFIX}/share/xbattle/xbts/*
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/tutorial* ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
