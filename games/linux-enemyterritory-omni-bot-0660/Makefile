# New ports collection makefile for:	omni-bot
# Date created:				7 May 2006
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	omni-bot
PORTVERSION=	0.51
CATEGORIES=	games linux
MASTER_SITES=	#
PKGNAMEPREFIX=	linux-enemyterritory-

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	Omni-Bot is a bot for Enemy Territory

RUN_DEPENDS=	et:${PORTSDIR}/games/linux-enemyterritory

ONLY_FOR_ARCHS=	i386
USE_X_PREFIX=	yes
USE_ZIP=	yes
USE_LINUX=	yes
NO_WRKSUBDIR=	yes

OPTIONS=	ETPUB "Enable ETPub support" off

DATADIR=	${PREFIX}/lib/enemyterritory
DOCSDIR=	${PREFIX}/share/doc/enemyterritory-${PORTNAME}

.include <bsd.port.pre.mk>

.if defined(WITH_ETPUB)
RUN_DEPENDS+=	et-etpub:${PORTSDIR}/games/linux-enemyterritory-etpub
PLIST_SUB+=	ETPUB=""
.else
PLIST_SUB+=	ETPUB="@comment "
.endif

pre-fetch:
	@cd ${DISTDIR} && ${FETCH_CMD:S/-A/-/} -o \
		${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} \
		'http://www.omni-bot.de/e107/request.php?175'

do-build:
.for f in et etded
	@(${ECHO} "#!/bin/sh"; \
	${ECHO} 'exec ${PREFIX}/bin/${f} +set fs_game ${PORTNAME} "$$@"') > \
		${WRKSRC}/${f}-${PORTNAME}
.endfor

do-install:
.for f in et etded
	${INSTALL_SCRIPT} ${WRKSRC}/${f}-${PORTNAME} ${PREFIX}/bin
.endfor
	${MKDIR} ${DATADIR}/${PORTNAME}
	${INSTALL_PROGRAM} ${WRKSRC}/omni-bot/omnibot_et.so ${DATADIR}/${PORTNAME}
	${CP} -R ${WRKSRC}/omni-bot/et ${DATADIR}/${PORTNAME}
	${INSTALL_PROGRAM} ${WRKSRC}/omnibot/qagame.mp.i386.so ${DATADIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/omnibot/omnibot_et.pk3 ${DATADIR}/${PORTNAME}
.if defined(WITH_ETPUB)
	cd ${DATADIR}/etpub && ${MV} qagame.mp.i386.so qagame.mp.i386.so.old
	${INSTALL_PROGRAM} ${WRKSRC}/etpub/qagame.mp.i386.so ${DATADIR}/etpub
	${INSTALL_DATA} ${WRKSRC}/etpub/omnibot_etpub.pk3 ${DATADIR}/etpub
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.   for f in *.txt omni-bot/*.txt
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.   endfor
	${CP} -R ${WRKSRC}/omni-bot/docs ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
