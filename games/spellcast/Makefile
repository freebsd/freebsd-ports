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
PLIST_FILES=	bin/spellcast man/man6/spellcast.6.gz
PORTDOCS=	README spelllist.ps

CFLAGS+=	-Wno-return-type

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/spellcast ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/spellcast.6 ${STAGEDIR}${PREFIX}/man/man6
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
