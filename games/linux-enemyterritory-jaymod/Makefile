# Created by: alepulver
# $FreeBSD$

PORTNAME=	jaymod
PORTVERSION=	2.2.0
CATEGORIES=	games linux
MASTER_SITES=	http://jaymod.clanfu.org/lib/downloads/ \
		http://www.zenenterprises.biz/bud/jaymod/
PKGNAMEPREFIX=	linux-enemyterritory-

MAINTAINER=	bar@FreeBSD.org
COMMENT=	Jaymod - An Enemy Territory Modification

RUN_DEPENDS=	et:${PORTSDIR}/games/linux-enemyterritory

USE_LINUX=	yes

OPTIONS_DEFINE=	DOCS OMNIBOT
OMNIBOT_DESC=	Install Omni-Bot for bot support

DATADIR=	${PREFIX}/lib/enemyterritory/${PORTNAME}
DOCSDIR=	${PREFIX}/share/doc/enemyterritory-${PORTNAME}

CLIENT_PK3=	${PORTNAME}-${PORTVERSION}.pk3
PLIST_SUB=	CLIENT_PK3="${CLIENT_PK3}"

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOMNIBOT}
RUN_DEPENDS+=	et-omni-bot:${PORTSDIR}/games/linux-enemyterritory-omni-bot
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
	cd ${WRKSRC} && ${INSTALL_DATA} ${CLIENT_PK3} ${DATADIR}
.for f in jaymod.cfg server.cfg
	${CP} -p ${WRKSRC}/${f} ${DATADIR}/${f}.sample
.endfor
	${CP} -r ${WRKSRC}/linux ${WRKSRC}/mapscripts ${DATADIR}
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} README.txt doc/jaymod.pdf ${DOCSDIR}
.endif

post-install:
	@if [ ! -f ${DATADIR}/jaymod.cfg ]; then \
		${CP} -p ${DATADIR}/jaymod.cfg.sample ${DATADIR}/jaymod.cfg ; \
	fi
	@if [ ! -f ${DATADIR}/server.cfg ]; then \
		${CP} -p ${DATADIR}/server.cfg.sample ${DATADIR}/server.cfg ; \
	fi

.include <bsd.port.mk>
