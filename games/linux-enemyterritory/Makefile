PORTNAME=	enemyterritory
PORTVERSION=	2.60b
PORTREVISION=	5
CATEGORIES=	games linux
MASTER_SITES=	IDSOFTWARE/et/:patch \
		IDSOFTWARE/et/linux/:full
PKGNAMEPREFIX=	linux-
DISTNAME=	et-linux-2.60b.x86
DISTFILES=	et-linux-2.60.x86.run:full ET-2.60b.zip:patch

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Wolfenstein: Enemy Territory (Linux version)
WWW=		https://www.splashdamage.com/games/wolfenstein-enemy-territory/

# Converted from NO_CDROM
LICENSE=	IDSOFTWARE
LICENSE_NAME=	IDSOFTWARE
LICENSE_TEXT=	Redistribution limited
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

ONLY_FOR_ARCHS=	amd64 i386
USES=		linux zip:infozip
USE_LINUX=	dri xorglibs
ETDIR=		${PREFIX}/lib/${PORTNAME}
PATCH_260B_DIR=	Enemy Territory 2.60b

CONFLICTS_INSTALL=	eternalterminal

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

do-extract:
	@${MKDIR} ${WRKSRC}
	@cd ${WRKSRC} && \
		${TAIL} +374 ${_DISTDIR}/et-linux-2.60.x86.run | ${TAR} xfz -
	@cd ${WRKSRC} && \
		${UNZIP_CMD} -q ${_DISTDIR}/ET-2.60b.zip

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
	${MKDIR} ${STAGEDIR}${ETDIR}

.for DIR in etmain etmain/video pb
	${MKDIR} ${STAGEDIR}${ETDIR}/${DIR}
.endfor

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${RMDIR} ${WRKSRC}/Docs/Help/_private
	(cd ${WRKSRC}/Docs && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})
.for FILE in CHANGES pb/PB_EULA.txt
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${STAGEDIR}${DOCSDIR}
.endfor
.endif

	${MKDIR} ${STAGEDIR}${ETDIR}/pb/htm
	(cd ${WRKSRC}/pb/htm && \
		${COPYTREE_SHARE} . ${STAGEDIR}${ETDIR}/pb/htm)

	${INSTALL_SCRIPT} ${WRKSRC}/openurl.sh ${STAGEDIR}${ETDIR}
	${INSTALL_DATA} ${WRKSRC}/etmain/video/etintro.roq \
		${STAGEDIR}${ETDIR}/etmain/video

.for FILE in campaigncycle.cfg cgame.mp.i386.so hunkusage.dat lmscycle.cfg \
	mp_bin.pk3 objectivecycle.cfg pak0.pk3 pak1.pk3 pak2.pk3 \
	punkbuster.cfg qagame.mp.i386.so server.cfg stopwatchcycle.cfg \
	ui.mp.i386.so
	${INSTALL_DATA} ${WRKSRC}/etmain/${FILE} ${STAGEDIR}${ETDIR}/etmain
.endfor

.for FILE in pbag.so pbags.so pbcl.db pbcl.so pbcls.so pbsv.db pbsv.so
	${INSTALL_DATA} ${WRKSRC}/pb/${FILE} ${STAGEDIR}${ETDIR}/pb
.endfor
	${INSTALL_PROGRAM} ${WRKSRC}/pb/pbweb.x86 ${STAGEDIR}${ETDIR}/pb

	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/ET.xpm ${STAGEDIR}${DATADIR}

.for FILE in et.x86 etded.x86
	${INSTALL_PROGRAM} ${WRKSRC}/bin/Linux/x86/${FILE} ${STAGEDIR}${ETDIR}
.endfor

.for FILE in et etded
	${INSTALL_SCRIPT} ${WRKSRC}/${FILE} ${STAGEDIR}${PREFIX}/bin
.endfor

.include <bsd.port.mk>
