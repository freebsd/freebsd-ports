# New ports collection makefile for:	omni-bot
# Date created:				7 May 2006
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	omni-bot
PORTVERSION=	0.820
CATEGORIES=	games linux
MASTER_SITES=	http://www.omni-bot.com/forum/downloads/
PKGNAMEPREFIX=	linux-enemyterritory-
DISTNAME=	Omni-bot_0.82_ET_Linux

MAINTAINER=	barbara.xxx1975@libero.it
COMMENT=	Omni-Bot is a bot for Enemy Territory

RUN_DEPENDS=	et:${PORTSDIR}/games/linux-enemyterritory

USE_ZIP=	yes
USE_LINUX=	yes
NO_WRKSUBDIR=	yes

DATADIR=	${PREFIX}/lib/enemyterritory/${PORTNAME}
DOCSDIR=	${PREFIX}/share/doc/enemyterritory-${PORTNAME}

do-build:
.for f in et etded
	@(${ECHO_CMD} "#!/bin/sh"; \
	${ECHO_CMD} 'exec ${PREFIX}/bin/${f} +set fs_game ${PORTNAME} +set omnibot_path "${DATADIR}" "$$@"') > \
		${WRKSRC}/${f}-${PORTNAME}
.endfor

do-install:
.for f in et etded
	${INSTALL_SCRIPT} ${WRKSRC}/${f}-${PORTNAME} ${PREFIX}/bin
.endfor
	${MKDIR} ${DATADIR}
	${MV} ${WRKSRC}/omni-bot/et/user/omni-bot.cfg \
		${WRKSRC}/omni-bot/et/user/omni-bot.cfg.sample
	${CP} -R ${WRKSRC}/omni-bot/* ${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/omnibot/qagame.mp.i386.so ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/omnibot/omnibot_et.pk3 ${DATADIR}

post-install:
	@if [ ! -f ${DATADIR}/et/user/omni-bot.cfg ]; then \
		${CP} -p ${DATADIR}/et/user/omni-bot.cfg.sample \
			${DATADIR}/et/user/omni-bot.cfg ; \
	fi

.include <bsd.port.mk>
