# New ports collection makefile for:	spellcast
# Version required:			1.1
# Date created:				28 June 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

DISTNAME=	spellcast-1.1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SUNSITE} \
		http://www.macula.net/lightside/
MASTER_SITE_SUBDIR=	games/multiplayer

MAINTAINER=	ports@FreeBSD.org

USE_X_PREFIX=	yes
MAN6=		spellcast.6

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/spellcast ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/spellcast.6 ${PREFIX}/man/man6
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/spellcast
.for file in README.1 README.2 spelllist.ps
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/spellcast
.endfor
.endif

.include <bsd.port.mk>
