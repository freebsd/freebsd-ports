# Created by: alepulver
# $FreeBSD$

PORTNAME=	shrub
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	games linux
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	alepulver
PKGNAMEPREFIX=	linux-enemyterritory-
DISTNAME=	1.2-test13-l

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Shrub - An Enemy Territory Modification

RUN_DEPENDS=	et:${PORTSDIR}/games/linux-enemyterritory

USES=		zip
USE_LINUX=	yes
NO_WRKSUBDIR=	yes

DATADIR=	${PREFIX}/lib/enemyterritory/${PORTNAME}

PLIST_FILES=	bin/et-${PORTNAME} \
		bin/etded-${PORTNAME} \
		%%DATADIR%%/qagame.mp.i386.so
PLIST_DIRS=	%%DATADIR%%

NO_STAGE=	yes
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

.include <bsd.port.mk>
