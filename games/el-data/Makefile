PORTNAME=	data
DISTVERSION=	1.9.5.9-1
PORTEPOCH=	1
CATEGORIES=	games
MASTER_SITES=	https://github.com/raduprv/Eternal-Lands/releases/download/${DISTVERSION}/
PKGNAMEPREFIX=	el-
DISTFILES=	${EL_DATA}
DIST_SUBDIR=	${PKGNAMEPREFIX:S/-//}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Eternal Lands data, sound, and music files
WWW=		https://www.eternal-lands.com/

NO_ARCH=	yes
NO_BUILD=	yes
USES=		dos2unix zip:infozip
DOS2UNIX_GLOB=	*.ini *.txt

DATADIR=	${PREFIX}/share/${PKGNAMEPREFIX:S/-//}
WRKSRC=		${WRKDIR}/${PKGNAMEPREFIX:S/-/_/}data
EL_DATA=	eternallands-data_${DISTVERSION}${EXTRACT_SUFX}

PORTDATA=	*

OPTIONS_DEFINE=	ELSOUND ELMUSIC
OPTIONS_DEFAULT=	ELSOUND ELMUSIC
ELSOUND_DESC=	Install additional sound files
ELMUSIC_DESC=	Install additional music files

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MELSOUND}
DISTFILES+=	eternallands-sound_${DISTVERSION:S/-1//}${EXTRACT_SUFX}
.endif

.if ${PORT_OPTIONS:MELMUSIC}
DISTFILES+=	eternallands-music_${DISTVERSION:S/-1//}${EXTRACT_SUFX}
.endif

do-extract:
	@${MKDIR} ${WRKSRC}
	@${UNZIP_CMD} -q ${_DISTDIR}/${EL_DATA} -d ${WRKDIR}
.if ${PORT_OPTIONS:MELSOUND}
	@${UNZIP_CMD} -q ${_DISTDIR}/eternallands-sound_${DISTVERSION:S/-1//}${EXTRACT_SUFX} -d ${WRKSRC}
.endif
.if ${PORT_OPTIONS:MELMUSIC}
	@${MKDIR} ${WRKSRC}/music
	@${UNZIP_CMD} -q ${_DISTDIR}/eternallands-music_${DISTVERSION:S/-1//}${EXTRACT_SUFX} -d ${WRKSRC}/music
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

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
