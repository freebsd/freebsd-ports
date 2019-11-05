# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	antipolix
PORTVERSION=	2.1
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	XCONTRIB/games/multiplayer
DISTNAME=	AntipoliX_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple multiplayer game for X Window System

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

NO_WRKSUBDIR=	yes
USES=		imake:noman xorg
USE_XORG=	x11

OPTIONS_DEFINE=	DOCS EXAMPLES

pre-build:
	@${TOUCH} ${WRKSRC}/client.man ${WRKSRC}/server.man

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/client ${STAGEDIR}${PREFIX}/bin/antipolix-client
	${INSTALL_PROGRAM} ${WRKSRC}/server ${STAGEDIR}${PREFIX}/bin/antipolix-server
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/.motd ${STAGEDIR}${EXAMPLESDIR}/dot.motd.sample
	${INSTALL_DATA} ${WRKSRC}/.players ${STAGEDIR}${EXAMPLESDIR}/dot.players.sample
	${INSTALL_DATA} ${WRKSRC}/.server_defaults ${STAGEDIR}${EXAMPLESDIR}/dot.server_defaults.sample
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in ANTIPOLIX_RULES CLIENT_USE COPYRIGHT SERVER_USE
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
