# New ports collection makefile for:	jaymod
# Date created:				7 May 2006
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	jaymod
PORTVERSION=	2.1.7
PORTREVISION=	2
CATEGORIES=	games linux
MASTER_SITES=	http://jaymod.clanfu.org/lib/downloads/ \
		http://budjb.com/lib/downloads/ \
		http://www.zenenterprises.org/bud/jaymod/ \
		http://www.spherens.com/zen/et/distro/
PKGNAMEPREFIX=	linux-enemyterritory-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Jaymod - An Enemy Territory Modification

RUN_DEPENDS=	et:${PORTSDIR}/games/linux-enemyterritory

USE_LINUX=	yes

OPTIONS=	OMNIBOT "Install Omni-Bot for bot support" off

DATADIR=	${PREFIX}/lib/enemyterritory/${PORTNAME}
DOCSDIR=	${PREFIX}/share/doc/enemyterritory-${PORTNAME}

CLIENT_PK3=	${PORTNAME}-${PORTVERSION}.pk3
PLIST_SUB=	CLIENT_PK3="${CLIENT_PK3}"

.include <bsd.port.pre.mk>

.if defined(WITH_OMNIBOT)
RUN_DEPENDS+=	et-omni-bot:${PORTSDIR}/games/linux-enemyterritory-omni-bot-0660
.endif

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
	${INSTALL_PROGRAM} ${WRKSRC}/qagame.mp.i386.so ${DATADIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${CLIENT_PK3} *.cfg ${DATADIR}
	${CP} -r ${WRKSRC}/linux ${WRKSRC}/mapscripts ${DATADIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} README.txt doc/jaymod.pdf ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
