# Created by: alepulver
# $FreeBSD$

PORTNAME=	jaymod
PORTVERSION=	2.2.0
PORTREVISION=	1
CATEGORIES=	games linux
MASTER_SITES=	http://jaymod.clanfu.org/lib/downloads/ \
		http://www.zenenterprises.biz/bud/jaymod/
PKGNAMEPREFIX=	linux-enemyterritory-

MAINTAINER=	bar@FreeBSD.org
COMMENT=	Jaymod - An Enemy Territory Modification

RUN_DEPENDS=	et:games/linux-enemyterritory

USES=		linux shebangfix
SHEBANG_FILES=	linux/convert_shrub
perl_OLD_CMD=	"/bin/env perl"

OPTIONS_DEFINE=	DOCS

DATADIR=	${PREFIX}/lib/enemyterritory/${PORTNAME}
DOCSDIR=	${PREFIX}/share/doc/enemyterritory-${PORTNAME}

CLIENT_PK3=	${PORTNAME}-${PORTVERSION}.pk3
PLIST_SUB=	CLIENT_PK3="${CLIENT_PK3}"

do-build:
.for f in et etded
	@(${ECHO_CMD} "#!/bin/sh"; \
	${ECHO_CMD} 'exec ${PREFIX}/bin/${f} +set fs_game ${PORTNAME} +set omnibot_path "${DATADIR}/../omni-bot" "$$@"') > \
		${WRKSRC}/${f}-${PORTNAME}
.endfor

do-install:
.for f in et etded
	@${INSTALL_SCRIPT} ${WRKSRC}/${f}-${PORTNAME} ${STAGEDIR}${PREFIX}/bin
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
