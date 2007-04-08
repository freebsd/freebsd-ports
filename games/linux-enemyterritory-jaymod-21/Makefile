# New ports collection makefile for:	jaymod
# Date created:				7 May 2006
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	jaymod
PORTVERSION=	2.0.5
CATEGORIES=	games linux
MASTER_SITES=	http://jaymod.clanfu.org/lib/downloads/ \
		http://budjb.com/lib/downloads/ \
		http://www.zenenterprises.org/bud/jaymod/ \
		http://www.spherens.com/zen/et/distro/
PKGNAMEPREFIX=	linux-enemyterritory-
DISTNAME=	${PORTNAME}-${PORTVERSION}-linux

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	Jaymod - An Enemy Territory Modification

RUN_DEPENDS=	et:${PORTSDIR}/games/linux-enemyterritory

USE_LINUX=	yes

DATADIR=	${PREFIX}/lib/enemyterritory/${PORTNAME}
DOCSDIR=	${PREFIX}/share/doc/enemyterritory-${PORTNAME}

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
	${INSTALL_PROGRAM} ${WRKSRC}/pentium4/qagame.mp.i386.so ${DATADIR}

.include <bsd.port.mk>
