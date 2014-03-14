# Created by: Pedro Giffuni
# $FreeBSD$

PORTNAME=	xbattle
PORTVERSION=	5.4.1
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GENTOO}
MASTER_SITE_SUBDIR=	distfiles

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Concurrent multi-player battle strategy game

DEPRECATED=	Unmaintained since 2001
EXPIRATION_DATE=	2014-04-12
USES=		imake
USE_XORG=	x11 xext
MAN1=		xbattle.1

CFLAGS+=	-Wno-return-type

NO_STAGE=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

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
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/tutorial* ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
