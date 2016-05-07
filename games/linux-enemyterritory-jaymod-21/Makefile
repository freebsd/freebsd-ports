# Created by: alepulver
# $FreeBSD$

PORTNAME=	jaymod
PORTVERSION=	2.1.7
PORTREVISION=	4
CATEGORIES=	games linux
MASTER_SITES=	https://storage.googleapis.com/google-code-archive-downloads/v1/code.google.com/etmod/
PKGNAMEPREFIX=	linux-enemyterritory-

MAINTAINER=	bar@FreeBSD.org
COMMENT=	Jaymod - An Enemy Territory Modification

RUN_DEPENDS=	et:games/linux-enemyterritory

VERSTR=		${PORTVERSION:C/([0-9])\.([0-9])\.([0-9]+)/\1\2\3/}
PKGNAMESUFFIX=	-${VERSTR}
PLIST_SUB=	VERSTR="${VERSTR}"

USES=		shebangfix
SHEBANG_FILES=	linux/convert_shrub
perl_OLD_CMD=	"/bin/env perl"
USE_LINUX=	yes

PORTSCOUT=	limit:^2\.1\.7

OPTIONS_DEFINE=	DOCS OMNIBOT
OMNIBOT_DESC=	Install Omni-Bot 0.660 for bot support

DATADIR=	${PREFIX}/lib/enemyterritory/${PORTNAME}-${VERSTR}
DOCSDIR=	${PREFIX}/share/doc/enemyterritory-${PORTNAME}-${VERSTR}

CLIENT_PK3=	${PORTNAME}-${PORTVERSION}.pk3
PLIST_SUB+=	CLIENT_PK3="${CLIENT_PK3}"

OB_VERSTR=	0660
OMNIBOT_RUN_DEPENDS=	et-omni-bot-${OB_VERSTR}:games/linux-enemyterritory-omni-bot-${OB_VERSTR}

do-build:
.for f in et etded
	@(${ECHO_CMD} "#!/bin/sh"; \
	${ECHO_CMD} 'exec ${PREFIX}/bin/${f} +set fs_game ${PORTNAME}-${VERSTR} +set omnibot_path "${DATADIR}/../omni-bot-${OB_VERSTR}" "$$@"') > \
		${WRKSRC}/${f}-${PORTNAME}-${VERSTR}
.endfor

do-install:
.for f in et etded
	@${INSTALL_SCRIPT} ${WRKSRC}/${f}-${PORTNAME}-${VERSTR} ${STAGEDIR}${PREFIX}/bin
.endfor
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@${INSTALL_PROGRAM} ${WRKSRC}/qagame.mp.i386.so ${STAGEDIR}${DATADIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${CLIENT_PK3} ${STAGEDIR}${DATADIR}
.for f in jaymod.cfg server.cfg
	@${CP} -p ${WRKSRC}/${f} ${STAGEDIR}${DATADIR}/${f}.sample
.endfor
	@${CP} -r ${WRKSRC}/linux ${WRKSRC}/mapscripts ${STAGEDIR}${DATADIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in README.txt doc/jaymod.pdf
	@cd ${WRKSRC} && ${INSTALL_DATA} ${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
