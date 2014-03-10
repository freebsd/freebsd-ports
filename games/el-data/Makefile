# Created by: Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	data
PORTVERSION=	193
CATEGORIES=	games
MASTER_SITES=	http://el.beplacid.net/downloads/:data \
		http://www.eternal-lands.com/:data \
		http://el.rauchs-home.de/client/:data \
		http://www.gm.fh-koeln.de/~linke/EL-Downloads/:sound \
		http://www.gm.fh-koeln.de/~linke/EL-Downloads/:music
PKGNAMEPREFIX=	el-
DISTFILES=	${EL_DATA}:data
DIST_SUBDIR=	${PKGNAMEPREFIX:S/-//}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Eternal Lands data, sound, and music files

NO_ARCH=	yes
NO_BUILD=	yes
USES=		dos2unix zip
DOS2UNIX_GLOB=	*.ini *.txt

DATADIR=	${PREFIX}/share/${PKGNAMEPREFIX:S/-//}
PLIST=		${WRKDIR}/pkg-plist
WRKSRC=		${WRKDIR}/${PKGNAMEPREFIX:S/-/_/}linux
EL_DATA=	${PKGNAMEPREFIX:S/-/_/}linux_${PORTVERSION}.zip

OPTIONS_DEFINE=	ELSOUND ELMUSIC
OPTIONS_DEFAULT=	ELSOUND ELMUSIC
ELSOUND_DESC=	Install additional sound files
ELMUSIC_DESC=	Install additional music files

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MELSOUND}
DISTFILES+=	EL_sound_191${EXTRACT_SUFX}:sound
HAVE_ESOUND=	yes
.endif

.if ${PORT_OPTIONS:MELMUSIC}
DISTFILES+=	EL_music_full${EXTRACT_SUFX}:music
HAVE_EMUSIC=	yes
.endif

do-extract:
	@${MKDIR} ${WRKDIR}
	@${UNZIP_CMD} -q ${_DISTDIR}/${EL_DATA} -d ${WRKDIR}
.if ${PORT_OPTIONS:MELSOUND}
	@${UNZIP_CMD} -q ${_DISTDIR}/EL_sound_191${EXTRACT_SUFX} -d ${WRKSRC}
.endif
.if ${PORT_OPTIONS:MELMUSIC}
	@${MKDIR} ${WRKSRC}/music
	@${UNZIP_CMD} -q ${_DISTDIR}/EL_music_full${EXTRACT_SUFX} -d ${WRKSRC}/music
.endif

post-extract:
	@${FIND} ${WRKSRC} -type d -name CVS -print0 | \
		${XARGS} -0 ${RM} -R
	@${FIND} ${WRKSRC} -type f -name "*.dll" -print0 | \
		${XARGS} -0 ${RM} -R
	@${FIND} ${WRKSRC} -type f -name "*.exe" -print0 | \
		${XARGS} -0 ${RM} -R
	@${FIND} ${WRKSRC} -type f -name "*.bin" -print0 | \
		${XARGS} -0 ${RM} -R

pre-install:
	@${RM} -f ${PLIST}
	@cd ${WRKSRC} && \
		${FIND} * -type f | ${SORT} | ${SED} -e 's|^|%%DATADIR%%/|' >> ${PLIST} && \
			${FIND} * -type d | ${SORT} -r | ${SED} -e 's|^|@dirrm %%DATADIR%%/|' >> ${PLIST}
	@${ECHO_CMD} "@dirrm %%DATADIR%%" >> ${PLIST}

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	@cd ${WRKSRC} && \
		${FIND} * -type d -exec ${MKDIR} "${STAGEDIR}${DATADIR}/{}" \; && \
			${FIND} * -type f -exec ${INSTALL_DATA} "{}" "${STAGEDIR}${DATADIR}/{}" \;

.include <bsd.port.mk>
