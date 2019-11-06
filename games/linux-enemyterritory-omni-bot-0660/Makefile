# Created by: alepulver
# $FreeBSD$

PORTNAME=	omni-bot
PORTVERSION=	0.660
PORTREVISION=	1
CATEGORIES=	games linux
MASTER_SITES=	http://googledrive.com/host/0BzZDKd40GAICUkZTaDJQQ2FKRTg/
PKGNAMEPREFIX=	linux-enemyterritory-
DISTNAME=	${PORTNAME}-${PORTVERSION:S/0$//}

MAINTAINER=	bar@FreeBSD.org
COMMENT=	Omni-Bot is a bot for Enemy Territory

BROKEN=		unfetchable

RUN_DEPENDS=	et:games/linux-enemyterritory

VERSTR=	${PORTVERSION:C/([0-9])\.([0-9]+)/\1\2/}
PKGNAMESUFFIX=	-${VERSTR}
PLIST_SUB=	VERSTR="${VERSTR}"

USES=		linux zip
NO_WRKSUBDIR=	yes

DATADIR=	${PREFIX}/lib/enemyterritory/${PORTNAME}-${VERSTR}
DOCSDIR=	${PREFIX}/share/doc/enemyterritory-${PORTNAME}-${VERSTR}

OPTIONS_DEFINE=	DOCS

do-build:
.for f in et etded
	@(${ECHO_CMD} "#!/bin/sh"; \
	${ECHO_CMD} 'exec ${PREFIX}/bin/${f} +set fs_game ${PORTNAME} +set omnibot_path "${DATADIR}" "$$@"') > \
		${WRKSRC}/${f}-${PORTNAME}
.endfor

do-install:
.for f in et etded
	${MV} ${WRKSRC}/${f}-${PORTNAME} ${WRKSRC}/${f}-${PORTNAME}-${VERSTR}
	${INSTALL_SCRIPT} ${WRKSRC}/${f}-${PORTNAME}-${VERSTR} \
		${STAGEDIR}${PREFIX}/bin
.endfor
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/omni-bot/omnibot_et.so ${STAGEDIR}${DATADIR}
	cd ${WRKSRC}/omni-bot && ${CP} -R et global_scripts ${STAGEDIR}${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/omnibot/qagame.mp.i386.so ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/omnibot/omnibot_et.pk3 ${STAGEDIR}${DATADIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.   for f in *.txt omni-bot/*.txt
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.   endfor
	${CP} -R ${WRKSRC}/omni-bot/docs ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
