# Created by: alepulver
# $FreeBSD$

PORTNAME=	omni-bot
PORTVERSION=	0.660
PORTREVISION=	1
CATEGORIES=	games linux
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	alepulver
PKGNAMEPREFIX=	linux-enemyterritory-
DISTNAME=	${PORTNAME}-${PORTVERSION:S/0$//}

MAINTAINER=	bar@FreeBSD.org
COMMENT=	Omni-Bot is a bot for Enemy Territory

RUN_DEPENDS=	et:${PORTSDIR}/games/linux-enemyterritory

VERSTR=	${PORTVERSION:C/([0-9])\.([0-9]+)/\1\2/}
PKGNAMESUFFIX=	-${VERSTR}
PLIST_SUB=	VERSTR="${VERSTR}"

USE_ZIP=	yes
USE_LINUX=	yes
NO_WRKSUBDIR=	yes

DATADIR=	${PREFIX}/lib/enemyterritory/${PORTNAME}-${VERSTR}
DOCSDIR=	${PREFIX}/share/doc/enemyterritory-${PORTNAME}-${VERSTR}

.include <bsd.port.options.mk>

do-build:
.for f in et etded
	@(${ECHO_CMD} "#!/bin/sh"; \
	${ECHO_CMD} 'exec ${PREFIX}/bin/${f} +set fs_game ${PORTNAME} +set omnibot_path "${DATADIR}" "$$@"') > \
		${WRKSRC}/${f}-${PORTNAME}
.endfor

do-install:
.for f in et etded
	${MV} ${WRKSRC}/${f}-${PORTNAME} ${WRKSRC}/${f}-${PORTNAME}-${VERSTR}
	${INSTALL_SCRIPT} ${WRKSRC}/${f}-${PORTNAME}-${VERSTR} ${PREFIX}/bin
.endfor
	${MKDIR} ${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/omni-bot/omnibot_et.so ${DATADIR}
	cd ${WRKSRC}/omni-bot && ${CP} -R et global_scripts ${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/omnibot/qagame.mp.i386.so ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/omnibot/omnibot_et.pk3 ${DATADIR}
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.   for f in *.txt omni-bot/*.txt
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.   endfor
	${CP} -R ${WRKSRC}/omni-bot/docs ${DOCSDIR}
.endif

.include <bsd.port.mk>
