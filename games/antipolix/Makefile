# New ports collection makefile for:	antipolix
# Version required:		2.1
# Date created:			2 December 1998
# Whom:				Andrey Zakhvatov
#
# $FreeBSD$
#

DISTNAME=		AntipoliX_2.1
PKGNAME=		antipolix-2.1
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	games/multiplayer

MAINTAINER=	ports@FreeBSD.org

WRKSRC=		${WRKDIR}
USE_IMAKE=	yes

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/client ${PREFIX}/bin/antipolix-client
	@ ${INSTALL_PROGRAM} ${WRKSRC}/server ${PREFIX}/bin/antipolix-server
	@ ${MKDIR} ${PREFIX}/share/examples/antipolix
	@ ${INSTALL_DATA} ${WRKSRC}/.motd ${PREFIX}/share/examples/antipolix/dot.motd.sample
	@ ${INSTALL_DATA} ${WRKSRC}/.players ${PREFIX}/share/examples/antipolix/dot.players.sample
	@ ${INSTALL_DATA} ${WRKSRC}/.server_defaults ${PREFIX}/share/examples/antipolix/dot.server_defaults.sample

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/antipolix
.for file in ANTIPOLIX_RULES CLIENT_USE COPYRIGHT SERVER_USE
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/antipolix
.endfor
.endif

.include <bsd.port.mk>
