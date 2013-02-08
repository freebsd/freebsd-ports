# Created by: alepulver
# $FreeBSD$

PORTNAME=	jaymod
PORTVERSION=	2.1.7
PORTREVISION=	3
CATEGORIES=	games linux
MASTER_SITES=	http://etmod.googlecode.com/files/ \
		http://www.zenenterprises.biz/bud/jaymod/ \
		http://bud.zenenterprises.biz/jaymod/ \
		http://et.lsdfunweb.fr/et/jaymod/
PKGNAMEPREFIX=	linux-enemyterritory-

MAINTAINER=	bar@FreeBSD.org
COMMENT=	Jaymod - An Enemy Territory Modification

RUN_DEPENDS=	et:${PORTSDIR}/games/linux-enemyterritory

VERSTR=		${PORTVERSION:C/([0-9])\.([0-9])\.([0-9]+)/\1\2\3/}
PKGNAMESUFFIX=	-${VERSTR}
PLIST_SUB=	VERSTR="${VERSTR}"

USE_LINUX=	yes

OPTIONS_DEFINE=	DOCS OMNIBOT
OMNIBOT_DESC=	Install Omni-Bot 0.660 for bot support

DATADIR=	${PREFIX}/lib/enemyterritory/${PORTNAME}-${VERSTR}
DOCSDIR=	${PREFIX}/share/doc/enemyterritory-${PORTNAME}-${VERSTR}

CLIENT_PK3=	${PORTNAME}-${PORTVERSION}.pk3
PLIST_SUB+=	CLIENT_PK3="${CLIENT_PK3}"

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOMNIBOT}
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
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} README.txt doc/jaymod.pdf ${DOCSDIR}
.endif

.include <bsd.port.mk>
