# New ports collection makefile for:	etpub
# Date created:				7 May 2006
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	etpub
PORTVERSION=	0.8.1
PORTREVISION=	2
CATEGORIES=	games linux
MASTER_SITES=	http://et.tjw.org/etpub/dist/
PKGNAMEPREFIX=	linux-enemyterritory-
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${CLIENT_PK3}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	ET Pub - An Enemy Territory Modification

RUN_DEPENDS=	et:${PORTSDIR}/games/linux-enemyterritory

USE_ZIP=	yes
USE_LINUX=	yes

OPTIONS=	OMNIBOT "Install Omni-Bot for bot support" off

DATADIR=	${PREFIX}/lib/enemyterritory/${PORTNAME}
DOCSDIR=	${PREFIX}/share/doc/enemyterritory-${PORTNAME}

CLIENT_PK3=	${PORTNAME}_client-20070801.pk3
PLIST_SUB=	CLIENT_PK3="${CLIENT_PK3}"

.include <bsd.port.pre.mk>

.if defined(WITH_OMNIBOT)
RUN_DEPENDS+=	et-omni-bot:${PORTSDIR}/games/linux-enemyterritory-omni-bot
.endif

pre-patch:
	@${FIND} ${WRKSRC} -type f -exec ${SH} -c \
		'${FILE} "$$0" | ${GREP} -q text && \
		${REINPLACE_CMD} -i "" -e "s/$$//" "$$0"' {} \;

do-build:
.for f in et etded
	@(${ECHO_CMD} "#!/bin/sh"; \
	${ECHO_CMD} 'exec ${PREFIX}/bin/${f} +set fs_game ${PORTNAME} +set omnibot_path "${DATADIR}/../omni-bot" "$$@"') > \
		${WRKSRC}/${f}-${PORTNAME}
.endfor

do-install:
.for f in et etded
	${INSTALL_SCRIPT} ${WRKSRC}/${f}-${PORTNAME} ${PREFIX}/bin
.endfor
	${MKDIR} ${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/glibc-2.1/qagame.mp.i386.so ${DATADIR}
	${INSTALL_DATA} ${DISTDIR}/${CLIENT_PK3} ${DATADIR}
	${MKDIR} ${DATADIR}/extra
.for f in PHP etadmin_mod
	${CP} -R ${WRKSRC}/extra/${f} ${DATADIR}/extra
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.   for f in ChangeLog.txt Install.txt Upgrade-0.8.txt
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.   endfor
	${CP} -R ${WRKSRC}/docs ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
