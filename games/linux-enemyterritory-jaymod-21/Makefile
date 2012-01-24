# New ports collection makefile for:	jaymod
# Date created:				7 May 2006
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	jaymod
PORTVERSION=	2.1.7
PORTREVISION=	3
CATEGORIES=	games linux
MASTER_SITES=	http://etmod.googlecode.com/files/ \
		http://www.zenenterprises.biz/bud/jaymod/ \
		http://bud.zenenterprises.biz/jaymod/ \
		http://et.lsdfunweb.fr/et/jaymod/
PKGNAMEPREFIX=	linux-enemyterritory-

MAINTAINER=	barbara.xxx1975@libero.it
COMMENT=	Jaymod - An Enemy Territory Modification

RUN_DEPENDS=	et:${PORTSDIR}/games/linux-enemyterritory

VERSTR=		${PORTVERSION:C/([0-9])\.([0-9])\.([0-9]+)/\1\2\3/}
PKGNAMESUFFIX=	-${VERSTR}
PLIST_SUB=	VERSTR="${VERSTR}"

USE_LINUX=	yes

OPTIONS=	OMNIBOT "Install Omni-Bot for bot support" off

DATADIR=	${PREFIX}/lib/enemyterritory/${PORTNAME}-${VERSTR}
DOCSDIR=	${PREFIX}/share/doc/enemyterritory-${PORTNAME}-${VERSTR}

CLIENT_PK3=	${PORTNAME}-${PORTVERSION}.pk3
PLIST_SUB+=	CLIENT_PK3="${CLIENT_PK3}"

.include <bsd.port.pre.mk>

.if defined(WITH_OMNIBOT)
OB_VERSTR=	0660
RUN_DEPENDS+=	et-omni-bot-${OB_VERSTR}:${PORTSDIR}/games/linux-enemyterritory-omni-bot-${OB_VERSTR}
.endif

do-build:
.for f in et etded
	@(${ECHO_CMD} "#!/bin/sh"; \
	${ECHO_CMD} 'exec ${PREFIX}/bin/${f} +set fs_game ${PORTNAME}-${VERSTR} +set omnibot_path "${DATADIR}/../omni-bot-${OB_VERSTR}" "$$@"') > \
		${WRKSRC}/${f}-${PORTNAME}-${VERSTR}
.endfor

do-install:
.for f in et etded
	${INSTALL_SCRIPT} ${WRKSRC}/${f}-${PORTNAME}-${VERSTR} ${PREFIX}/bin
.endfor
	${MKDIR} ${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/qagame.mp.i386.so ${DATADIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${CLIENT_PK3} *.cfg ${DATADIR}
	${CP} -r ${WRKSRC}/linux ${WRKSRC}/mapscripts ${DATADIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} README.txt doc/jaymod.pdf ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
