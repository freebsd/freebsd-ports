# New ports collection makefile for:    Enemy Territory
# Date created:                         Sun Jan 18 18:54:00 CET 2004
# Whom:                                 benlutz@datacomm.ch
#
# $FreeBSD$
#

PORTNAME=	enemyterritory
PORTVERSION=	2.60
PORTREVISION=	1
CATEGORIES=	games linux
MASTER_SITES=	http://mirrors.xmission.com/idsoftware/et/linux/ \
		http://3dgamers.intelenet.net/pub/3dgamers/games/wolfensteinet/ \
		http://ftp7.3dgamers.com/pub/3dgamers/games/wolfensteinet/ \
		http://ftp4.3dgamers.com/pub/3dgamers/games/wolfensteinet/ \
		http://3dgamers.gameservers.net/pub/3dgamers/games/wolfensteinet/ \
		http://downloads-3dg.planetmirror.com/pub/3dgamers/games/wolfensteinet/ \
		http://3dgamers.iinet.net.au/pub/3dgamers/games/wolfensteinet/
PKGNAMEPREFIX=	linux-
DISTNAME=	et-linux-2.60.x86
EXTRACT_SUFX=	.run

MAINTAINER=	benlutz@datacomm.ch
COMMENT=	Wolfenstein: Enemy Territory (Linux version)

ONLY_FOR_ARCHS=	i386
USE_LINUX=	yes
USE_X_PREFIX=	yes
NO_PACKAGE=	Package will be 257MB, set FORCE_PACKAGE if you really want to build it
RESTRICTED=	Redistribution is limited, see license
NO_WRKSUBDIR=	yes
ETDIR=		${PREFIX}/lib/${PORTNAME}
INSTALL_DIR=	${INSTALL} -d -o ${BINOWN} -g ${BINGRP} -m ${BINMODE}

do-extract:
	@${MKDIR} ${WRKSRC}
	@cd ${WRKSRC} && \
		${TAIL} +374 ${_DISTDIR}/${DISTFILES} | ${TAR} xfz -

post-patch:
.for FILE in et etded
	@${SED} -e 's|@ETDIR@|${ETDIR}|' ${FILESDIR}/${FILE}.in > ${WRKSRC}/${FILE}
.endfor

do-build:
	${BRANDELF} -t Linux ${WRKSRC}/pb/pbweb.x86
.for FILE in et.x86 etded.x86
	${BRANDELF} -t Linux ${WRKSRC}/bin/Linux/x86/${FILE}
.endfor

do-install:
	${INSTALL_DIR} ${ETDIR}

.for DIR in etmain etmain/video pb
	${INSTALL_DIR} ${ETDIR}/${DIR}
.endfor

.if !defined(NOPORTDOCS)
	${INSTALL_DIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/Docs/* ${DOCSDIR}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}/*
	${FIND} ${DOCSDIR}/* -type f -print0 | \
		${XARGS} -0 ${CHMOD} ${SHAREMODE}
	${FIND} ${DOCSDIR}/* -type d -print0 | \
		${XARGS} -0 ${CHMOD} ${BINMODE}
.for FILE in CHANGES pb/PB_EULA.txt
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
.endif

	${CP} -R ${WRKSRC}/pb/htm ${ETDIR}/pb
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${ETDIR}/pb/htm
	${FIND} ${ETDIR}/pb/htm -type f -print0 | \
		${XARGS} -0 ${CHMOD} ${SHAREMODE}
	${FIND} ${ETDIR}/pb/htm -type d -print0 | \
		${XARGS} -0 ${CHMOD} ${BINMODE}

	${INSTALL_SCRIPT} ${WRKSRC}/openurl.sh ${ETDIR}
	${INSTALL_DATA} ${WRKSRC}/etmain/video/etintro.roq \
		${ETDIR}/etmain/video

.for FILE in campaigncycle.cfg cgame.mp.i386.so hunkusage.dat lmscycle.cfg \
	mp_bin.pk3 objectivecycle.cfg pak0.pk3 pak1.pk3 pak2.pk3 \
	punkbuster.cfg qagame.mp.i386.so server.cfg stopwatchcycle.cfg \
	ui.mp.i386.so
	${INSTALL_DATA} ${WRKSRC}/etmain/${FILE} ${ETDIR}/etmain
.endfor

.for FILE in pbag.so pbags.so pbcl.db pbcl.so pbcls.so pbsv.db pbsv.so
	${INSTALL_DATA} ${WRKSRC}/pb/${FILE} ${ETDIR}/pb
.endfor
	${INSTALL_PROGRAM} ${WRKSRC}/pb/pbweb.x86 ${ETDIR}/pb

	${INSTALL_DIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/ET.xpm ${DATADIR}

.for FILE in et.x86 etded.x86
	${INSTALL_PROGRAM} ${WRKSRC}/bin/Linux/x86/${FILE} ${ETDIR}
.endfor

	${INSTALL_DIR} ${PREFIX}/bin
.for FILE in et etded
	${INSTALL_SCRIPT} ${WRKSRC}/${FILE} ${PREFIX}/bin
.endfor

.include <bsd.port.mk>
