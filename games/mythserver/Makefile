# New ports collection makefile for:    Bungie.net MythII Metaserver
# Date created:				Sat Feb  9 16:00:13 CET 2002
# Whom:				Miguel Mendez <flynn@energyhq.homeip.net>
#
# $FreeBSD$
#

PORTNAME=	mythserver
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://projectmagma.net/files/os/
DISTNAME=	metaserver2open

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Bungie.net MythII Metaserver Open Source

USE_ZIP=	yes
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/metaserver2open/spaghetti

pre-everything::
		@${ECHO_CMD} "#############################################"
		@${ECHO_CMD} "                 IMPORTANT!"
		@${ECHO_CMD} "    Please: Edit and modify environment.h"
		@${ECHO_CMD} "        located at ${WRKSRC}/utils/"
		@${ECHO_CMD} "         after running make patch but"
		@${ECHO_CMD} "         before compiling this port."
		@${ECHO_CMD} "#############################################"

do-install:
		@${INSTALL_PROGRAM} ${WRKSRC}/bin/game_search_server_new ${PREFIX}/bin
		@${INSTALL_PROGRAM} ${WRKSRC}/bin/roomd_new ${PREFIX}/bin
		@${INSTALL_PROGRAM} ${WRKSRC}/bin/userd_new ${PREFIX}/bin
		@${MKDIR} ${PREFIX}/share/${PORTNAME}/db
		@${MKDIR} ${PREFIX}/share/${PORTNAME}/log
		@${INSTALL_DATA} ${WRKSRC}/motd ${PREFIX}/share/${PORTNAME}/
		@${TOUCH} ${PREFIX}/share/${PORTNAME}/db/orders.dat
		@${TOUCH} ${PREFIX}/share/${PORTNAME}/db/users.dat

.include <bsd.port.mk>
