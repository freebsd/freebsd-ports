# Created by: alepulver
# $FreeBSD$

PORTNAME=	etpro
DISTVERSION=	3_2_6
CATEGORIES=	games linux
MASTER_SITES=	http://bani.anime.net/etpro/ \
		http://dl.vpclan.de/etpro/ \
		http://www.enemyterritory.sk/files/ \
		ftp://download:etpro@preachers.cz/ \
		http://ftp.freenet.de/pub/4players/hosted/wolfenstein/users/mods/ \
		http://www.dakteam.org/ \
		http://www.enemyterritory.cl/files/
PKGNAMEPREFIX=	linux-enemyterritory-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	ET Pro - Enemy Territory Competition Mod

RUN_DEPENDS=	et:games/linux-enemyterritory

USES=		zip
USE_LINUX=	yes
NO_WRKSUBDIR=	yes

DATADIR=	${PREFIX}/lib/enemyterritory/${PORTNAME}

PLIST_SUB=	VERSION="${DISTVERSION}"

do-build:
.for f in et etded
	@(${ECHO} "#!/bin/sh"; \
	${ECHO} 'exec ${PREFIX}/bin/${f} +set fs_game ${PORTNAME} "$$@"') > \
		${WRKSRC}/${f}-${PORTNAME}
.endfor

do-install:
.for f in et etded
	${INSTALL_SCRIPT} ${WRKSRC}/${f}-${PORTNAME} ${STAGEDIR}${PREFIX}/bin
.endfor
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${CP} -R ${WRKSRC}/${PORTNAME}/* ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
