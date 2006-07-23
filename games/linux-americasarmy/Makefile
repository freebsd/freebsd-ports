# New ports collection makefile for:    America's Army
# Date created:                         Sun Sep 11 15:45:00 PET 2005
# Whom:                                 acardenas@bsd.org.pe
#
# $FreeBSD$
#

PORTNAME=	americasarmy
PORTVERSION=	2.5.0
CATEGORIES=	games linux
MASTER_SITES=	http://3dgamers.iinet.net.au/pub/3dgamers/games/americasarmy/ \
		http://downloads-3dg.planetmirror.com/pub/3dgamers/games/americasarmy/ \
		http://downloads-3dg.planetmirror.com/pub/3dgamers/games/americasarmy/ \
		http://0day.icculus.org/armyops/
PKGNAMEPREFIX=	linux-
DISTNAME=	armyops250-linux
EXTRACT_SUFX=	.run

MAINTAINER=	acm@FreeBSD.org
COMMENT=	America's Army (Linux version)

ONLY_FOR_ARCHS=	i386 amd64
USE_X_PREFIX=	yes
USE_LINUX=	yes
NO_BUILD=	yes
RESTRICTED=	Redistribution is limited, see license
NO_PACKAGE=	Package will be 745MB, set FORCE_PACKAGE if you really
NO_WRKSUBDIR=	yes
ARMYDIR=	${PREFIX}/lib/${PORTNAME}
INSTALL_DIR=	${INSTALL} -d -o ${BINOWN} -g ${BINGRP} -m ${BINMODE}

do-extract:
	@${MKDIR} ${WRKSRC}
	@cd ${WRKSRC} && \
		${TAIL} -c +8844 ${_DISTDIR}/${DISTFILES} | ${TAR} xf -
	@${TAR} xfz ${WRKSRC}/setupstuff.tar.gz -C ${WRKSRC}
	@${MV} ${WRKSRC}/bin/armyops ${WRKSRC}/armyops

do-install:
	@${MKDIR} ${ARMYDIR}
.for FILE in ArmyOps.xpm README.linux ArmyOps250_EULA.txt
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${ARMYDIR}
.endfor
.for FILE in armyops250.tar.bz2 binaries.tar.bz2
	@${TAR} xfpj ${WRKSRC}/${FILE} -C ${ARMYDIR}/
.endfor
.for DIR in Animations Briefings Demos Help KarmaData Maps Movies Music Sounds StaticMeshes \
	System Textures
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${ARMYDIR}/${DIR}
	@${FIND} ${ARMYDIR}/${DIR} -type f -print0 | \
		${XARGS} -0 ${CHMOD} ${SHAREMODE}
	@${FIND} ${ARMYDIR}/${DIR} -type d -print0 | \
		${XARGS} -0 ${CHMOD} ${BINMODE}
.endfor
.for FILE in System/armyops-bin System/server-bin System/pb/pbweb.x86
	@${CHMOD} ${BINMODE} ${ARMYDIR}/${FILE}
.endfor
	@${INSTALL_SCRIPT} ${WRKSRC}/armyops ${ARMYDIR}
	@${LN} -s ${ARMYDIR}/armyops ${PREFIX}/bin/armyops

.include <bsd.port.mk>
