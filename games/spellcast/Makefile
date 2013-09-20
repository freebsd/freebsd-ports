# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	spellcast
PORTVERSION=	1.2
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://www.eblong.com/zarf/ftp/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multiplayer fight with spells turn based game for X Window System

USE_XORG=	x11
MAN6=		spellcast.6
PLIST_FILES=	bin/spellcast
PORTDOCS=	README spelllist.ps

CFLAGS+=	-Wno-return-type

OPTIONS_DEFINE=	DOCS

NO_STAGE=	yes
.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/spellcast ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/spellcast.6 ${PREFIX}/man/man6
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

.include <bsd.port.mk>
