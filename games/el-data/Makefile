# Created by: Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	data
PORTVERSION=	1.9.4
PORTEPOCH=	1
CATEGORIES=	games
MASTER_SITES=	http://www.eternal-lands.com/:data \
		http://www.gm.fh-koeln.de/~linke/EL-Downloads/:sound \
		http://www.gm.fh-koeln.de/~linke/EL-Downloads/:music
PKGNAMEPREFIX=	el-
DISTFILES=	${EL_DATA}:data
DIST_SUBDIR=	${PKGNAMEPREFIX:S/-//}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Eternal Lands data, sound, and music files

NO_ARCH=	yes
NO_BUILD=	yes
USES=		dos2unix zip:infozip
DOS2UNIX_GLOB=	*.ini *.txt

DATADIR=	${PREFIX}/share/${PKGNAMEPREFIX:S/-//}
WRKSRC=		${WRKDIR}/${PKGNAMEPREFIX:S/-/_/}linux
EL_DATA=	${PKGNAMEPREFIX:S/-/_/}linux_installer_${PORTVERSION:S/.//g}.sh

PORTDATA=	*

OPTIONS_DEFINE=	ELSOUND ELMUSIC
OPTIONS_DEFAULT=	ELSOUND ELMUSIC
ELSOUND_DESC=	Install additional sound files
ELMUSIC_DESC=	Install additional music files

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MELSOUND}
DISTFILES+=	EL_sound_191${EXTRACT_SUFX}:sound
.endif

.if ${PORT_OPTIONS:MELMUSIC}
DISTFILES+=	EL_music_full${EXTRACT_SUFX}:music
.endif

do-extract:
	@${MKDIR} ${WRKSRC}
	@cd ${WRKDIR} && ${TAIL} +440 ${_DISTDIR}/${EL_DATA} | \
		${TAR} zxf - subarch
	@cd ${WRKDIR} && ${TAR} -zxf subarch  - instarchive_all
	@cd ${WRKDIR} && ${TAR} -zxf ${WRKDIR}/instarchive_all -C ${WRKSRC}
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

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
