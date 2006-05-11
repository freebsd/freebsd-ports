# New ports collection makefile for:	jaymod
# Date created:				7 May 2006
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	jaymod
PORTVERSION=	1.4
CATEGORIES=	games linux
MASTER_SITES=	http://jaymod.clanfu.org/lib/downloads/ \
		http://budjb.com/lib/downloads/ \
		http://www.zenenterprises.org/bud/jaymod/ \
		http://www.spherens.com/zen/et/distro/
PKGNAMEPREFIX=	linux-enemyterritory-

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	Jaymod - An Enemy Territory Modification

RUN_DEPENDS=	et:${PORTSDIR}/games/linux-enemyterritory

ONLY_FOR_ARCHS=	i386
USE_X_PREFIX=	yes
USE_LINUX=	yes
NO_WRKSUBDIR=	yes

DATADIR=	${PREFIX}/lib/enemyterritory/${PORTNAME}
DOCSDIR=	${PREFIX}/share/doc/enemyterritory-${PORTNAME}

PLIST_SUB=	VERSION="${PORTVERSION}"

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
	${MKDIR} ${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/qagame.mp.i386.so ${DATADIR}
.for f in jaymod-${PORTVERSION}.pk3 jaymod.cfg-sample
	${INSTALL_DATA} ${WRKSRC}/${f} ${DATADIR}
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.   for f in jaymod-${PORTVERSION}.pdf readme.txt
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.   endfor
.endif

.include <bsd.port.mk>
