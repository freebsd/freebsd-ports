# New ports collection makefile for:	antipolix
# Date created:			2 December 1998
# Whom:				Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	antipolix
PORTVERSION=	2.1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	games/multiplayer
DISTNAME=	AntipoliX_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple multiplayer game for X Window System

NO_WRKSUBDIR=	yes
USE_IMAKE=	yes
NO_INSTALL_MANPAGES=	yes

pre-build:
	@${TOUCH} ${WRKSRC}/client.man ${WRKSRC}/server.man

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/client ${PREFIX}/bin/antipolix-client
	${INSTALL_PROGRAM} ${WRKSRC}/server ${PREFIX}/bin/antipolix-server
	@${MKDIR} ${PREFIX}/share/examples/antipolix
	${INSTALL_DATA} ${WRKSRC}/.motd ${PREFIX}/share/examples/antipolix/dot.motd.sample
	${INSTALL_DATA} ${WRKSRC}/.players ${PREFIX}/share/examples/antipolix/dot.players.sample
	${INSTALL_DATA} ${WRKSRC}/.server_defaults ${PREFIX}/share/examples/antipolix/dot.server_defaults.sample
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/antipolix
.for file in ANTIPOLIX_RULES CLIENT_USE COPYRIGHT SERVER_USE
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/antipolix
.endfor
.endif

.include <bsd.port.mk>
