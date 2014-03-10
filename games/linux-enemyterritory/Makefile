# Created by: benlutz@datacomm.ch
# $FreeBSD$

PORTNAME=	enemyterritory
PORTVERSION=	2.60b
PORTREVISION=	1
CATEGORIES=	games linux
MASTER_SITES=		${MASTER_SITE_IDSOFTWARE:S|$|et/:patch|}
#MASTER_SITES=	${MASTER_SITE_IDSOFTWARE:S|$|et/linux/:full|}
PKGNAMEPREFIX=	linux-
DISTNAME=	et-linux-2.60b.x86
DISTFILES=	et-linux-2.60.x86.run:full ET-2.60b.zip:patch

MAINTAINER=	benlutz@datacomm.ch
COMMENT=	Wolfenstein: Enemy Territory (Linux version)

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX=	yes
USES=		zip:infozip
NO_CDROM=	Redistribution is limited, see license
ETDIR=		${PREFIX}/lib/${PORTNAME}
INSTALL_DIR=	${INSTALL} -d -o ${BINOWN} -g ${BINGRP} -m ${BINMODE}
PATCH_260B_DIR=	Enemy Territory 2.60b
USE_LINUX_APPS=	dri

NO_STAGE=	yes
do-extract:
	@${MKDIR} ${WRKSRC}
	@cd ${WRKSRC} && \
		${TAIL} +374 ${_DISTDIR}et-linux-2.60.x86.run | ${TAR} xfz -
	@cd ${WRKSRC} && \
		${UNZIP_CMD} -q ${_DISTDIR}ET-2.60b.zip

post-patch:
.for FILE in et etded
	@${SED} -e 's|@ETDIR@|${ETDIR}|' ${FILESDIR}/${FILE}.in > ${WRKSRC}/${FILE}
.endfor
	@${MV} "${WRKSRC}/${PATCH_260B_DIR}/linux/et.x86" ${WRKSRC}/bin/Linux/x86
	@${MV} "${WRKSRC}/${PATCH_260B_DIR}/linux/etded.x86" ${WRKSRC}/bin/Linux/x86

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
	${RMDIR} ${WRKSRC}/Docs/Help/_private
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

.for FILE in et etded
	${INSTALL_SCRIPT} ${WRKSRC}/${FILE} ${PREFIX}/bin
.endfor

.include <bsd.port.mk>
