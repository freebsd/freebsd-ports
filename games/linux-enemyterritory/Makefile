# New ports collection makefile for:    Enemy Territory
# Date created:                         Sun Jan 18 18:54:00 CET 2004
# Whom:                                 benlutz@datacomm.ch
#
# $FreeBSD$
#

PORTNAME=	enemyterritory
PORTVERSION=	2.56.2
CATEGORIES=	games linux
MASTER_SITES=	http://ftp.wireplay.co.uk/enemyterritory/server/linux/ \
		ftp://3dgamers.in-span.net/pub/3dgamers4/games/wolfensteinet/ \
		http://ftp.algx.net/idsoftware/et/linux/ \
		http://www.sh.nu/download/games/ \
		http://games.gci.net/pub/R2CW/EnemyTerritory/
PKGNAMEPREFIX=	linux-
DISTNAME=	et-linux-2.56-2.x86
EXTRACT_SUFX=	.run

MAINTAINER=	benlutz@datacomm.ch
COMMENT=	Wolfenstein: Enemy Territory (Linux version)

ONLY_FOR_ARCHS=	i386
USE_LINUX_PREFIX=	yes
NO_PACKAGE=	Distfile is 258MB, set FORCE_PACKAGE if you really want to build this package
RESTRICTED=	Redistribution is limited, see license
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
ETDIR=		usr/games/et
PLIST_SUB+=	ETDIR="${ETDIR}"
INSTALL_DIR=	${INSTALL} -d -o ${BINOWN} -g ${BINGRP} -m 755
ETWRKDIR=	${WRKDIR}/${PORTNAME}-${PORTVERSION}

do-extract:
	@${MKDIR} ${WRKDIR}
	@${MKDIR} ${ETWRKDIR}
	@cd ${ETWRKDIR} && \
		${TAIL} +356 ${DISTDIR}/${DISTFILES} | ${TAR} xfz -

do-install:
	${INSTALL_DIR} ${PREFIX}/${ETDIR}

.if !defined(NOPORTDOCS)
	${CP} -R -p ${ETWRKDIR}/Docs ${PREFIX}/${ETDIR} && \
	${CHOWN} -R ${BINOWN}:${BINGRP} ${PREFIX}/${ETDIR}/Docs
	${FIND} ${PREFIX}/${ETDIR}/Docs -type f -print0 | \
		${XARGS} -0 ${CHMOD} 644
	${FIND} ${PREFIX}/${ETDIR}/Docs -type d -print0 | \
		${XARGS} -0 ${CHMOD} 755
.endif

.for DIR in etmain etmain/video pb pb
	${INSTALL_DIR} ${PREFIX}/${ETDIR}/${DIR}
.endfor

	${INSTALL_SCRIPT} ${ETWRKDIR}/openurl.sh ${PREFIX}/${ETDIR}
	${INSTALL_DATA} ${ETWRKDIR}/etmain/video/etintro.roq \
		${PREFIX}/${ETDIR}/etmain/video

.for FILE in campaigncycle.cfg description.txt hunkusage.dat lmscycle.cfg \
	objectivecycle.cfg punkbuster.cfg server.cfg stopwatchcycle.cfg \
	cgame.mp.i386.so qagame.mp.i386.so ui.mp.i386.so mp_bin.pk3 pak0.pk3 \
	pak1.pk3
	${INSTALL_DATA} ${ETWRKDIR}/etmain/${FILE} ${PREFIX}/${ETDIR}/etmain
.endfor

	${CP} -R -p ${ETWRKDIR}/pb/htm ${PREFIX}/${ETDIR}/pb && \
	${CHOWN} -R ${BINOWN}:${BINGRP} ${PREFIX}/${ETDIR}/pb/htm
	${FIND} ${PREFIX}/${ETDIR}/pb/htm -type f -print0 | \
		${XARGS} -0 ${CHMOD} 644
	${FIND} ${PREFIX}/${ETDIR}/pb/htm -type d -print0 | \
		${XARGS} -0 ${CHMOD} 755

.for FILE in PB_EULA.txt pbag.so pbcl.db pbcl.so pbsv.db pbsv.so
	${INSTALL_DATA} ${ETWRKDIR}/pb/${FILE} ${PREFIX}/${ETDIR}/pb
.endfor

	${INSTALL} -m 755 ${ETWRKDIR}/pb/pbweb.x86 ${PREFIX}/${ETDIR}/pb

.for FILE in CHANGES ET.xpm v1.02_Readme.htm
	${INSTALL_DATA} ${ETWRKDIR}/${FILE} ${PREFIX}/${ETDIR}
.endfor

.for FILE in et.x86 etded.x86
	${INSTALL} -m 755 ${ETWRKDIR}/bin/FreeBSD/x86/${FILE} \
		${PREFIX}/${ETDIR}
.endfor

	@${ECHO} 'creating wrapper script: et'
	@${ECHO} '#!/bin/sh' > ${PREFIX}/${ETDIR}/et
	@${ECHO} '# Needed to make symlinks/shortcuts work.' >> \
		${PREFIX}/${ETDIR}/et
	@${ECHO} '# the binaries must run with correct working directory' >> \
		${PREFIX}/${ETDIR}/et
	@${ECHO} 'cd "${PREFIX}/${ETDIR}"' >> ${PREFIX}/${ETDIR}/et
	@${ECHO} './et.x86 \$*' >> ${PREFIX}/${ETDIR}/et
	@${ECHO} 'exit \$?' >> ${PREFIX}/${ETDIR}/et
	@${CHMOD} 755 ${PREFIX}/${ETDIR}/et
	@${CHOWN} ${BINOWN}:${BINGRP} ${PREFIX}/${ETDIR}/et

	@${ECHO} 'creating wrapper script: etded'
	@${ECHO} '#!/bin/sh' > ${PREFIX}/${ETDIR}/etded
	@${ECHO} '# Needed to make symlinks/shortcuts work.' >> \
		${PREFIX}/${ETDIR}/etded
	@${ECHO} '# the binaries must run with correct working directory' >> \
		${PREFIX}/${ETDIR}/etded
	@${ECHO} 'cd "${PREFIX}/${ETDIR}"' >> \
		${PREFIX}/${ETDIR}/etded
	@${ECHO} './etded.x86 \$*' >> ${PREFIX}/${ETDIR}/etded
	@${ECHO} 'exit \$?' >> ${PREFIX}/${ETDIR}/etded
	@${CHMOD} 755 ${PREFIX}/${ETDIR}/etded
	@${CHOWN} ${BINOWN}:${BINGRP} ${PREFIX}/${ETDIR}/etded

.include <bsd.port.mk>
