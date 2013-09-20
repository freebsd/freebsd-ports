# Created by: acardenas@bsd.org.pe
# $FreeBSD$

PORTNAME=	americasarmy
PORTVERSION=	2.5.0
PORTREVISION=	1
CATEGORIES=	games linux
MASTER_SITES=	ftp://195.222.33.239/pub/games/americasarmy/ \
		ftp://ftp.bih.net.ba/pub/games/americasarmy/ \
		ftp://ftp.free.fr/.mirrors4/AmericasArmy/Linux_v2.50/ \
		ftp://140.128.99.3/FreeBSD/ports/distfiles/ \
		ftp://ftp.thu.edu.tw/FreeBSD/ports/distfiles/ \
		ftp://ftp.csie.ncu.edu.tw/pub/FreeBSD/ports/distfiles/ \
		ftp://130.89.175.1/pub/games/americasarmy/client/linux/ \
		ftp://ftp.snt.utwente.nl/pub/games/americasarmy/client/linux/ \
		ftp://130.88.203.90/pub/odd-dists/ \
		ftp://ftp5.uk.freebsd.org/pub/FreeBSD/ports/distfiles/ \
		ftp://ftp.freebsd.org.tw/pub/ports/distfiles/
PKGNAMEPREFIX=	linux-
DISTNAME=	armyops250-linux
EXTRACT_SUFX=	.run

MAINTAINER=	acm@FreeBSD.org
COMMENT=	America's Army (Linux version)

USE_LINUX=	yes
NO_BUILD=	yes
RESTRICTED=	Redistribution is limited, see license
NO_PACKAGE=	Package will be 745MB, set FORCE_PACKAGE if you really
NO_WRKSUBDIR=	yes
ARMYDIR=	${PREFIX}/lib/${PORTNAME}
INSTALL_DIR=	${INSTALL} -d -o ${BINOWN} -g ${BINGRP} -m ${BINMODE}

NO_STAGE=	yes
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
