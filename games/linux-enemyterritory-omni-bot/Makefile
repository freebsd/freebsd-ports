# Created by: alepulver
# $FreeBSD$

PORTNAME=	omni-bot
PORTVERSION=	0.831
CATEGORIES=	games linux
MASTER_SITES=	http://googledrive.com/host/0BzZDKd40GAICUkZTaDJQQ2FKRTg/
PKGNAMEPREFIX=	linux-enemyterritory-
DISTFILES=	omni-bot_0_831_ET_linux.zip \
			omni-bot_0_83_ET_waypoint_mod.zip

MAINTAINER=	bar@FreeBSD.org
COMMENT=	Omni-Bot is a bot for Enemy Territory

BROKEN=		unfetchable

RUN_DEPENDS=	et:games/linux-enemyterritory

USES=		linux zip
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
	${INSTALL_SCRIPT} ${WRKSRC}/${f}-${PORTNAME} ${STAGEDIR}${PREFIX}/bin
.endfor
	${MKDIR} ${STAGEDIR}${DATADIR}
	${MV} ${WRKSRC}/omni-bot/et/user/omni-bot.cfg \
		${WRKSRC}/omni-bot/et/user/omni-bot.cfg.sample
	${CP} -R ${WRKSRC}/omni-bot/* ${STAGEDIR}${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/omnibot/qagame.mp.i386.so ${STAGEDIR}${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/omnibot/ui.mp.i386.so ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/omnibot/omnibot_et.pk3 ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
