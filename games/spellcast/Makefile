# New ports collection makefile for:	spellcast
# Date created:				28 June 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	spellcast
PORTVERSION=	1.2
CATEGORIES=	games
MASTER_SITES=	http://www.eblong.com/zarf/ftp/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multiplayer fight with spells turn based game for X Window System

USE_X_PREFIX=	yes
MAN6=		spellcast.6

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/spellcast ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/spellcast.6 ${PREFIX}/man/man6
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/spellcast
.for file in README spelllist.ps
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/spellcast
.endfor
.endif

.include <bsd.port.mk>
