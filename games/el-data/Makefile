# New ports collection makefile for:	el-data
# Date created:		2006-08-18
# Whom:			Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	data
PORTVERSION=	192
CATEGORIES=	games
MASTER_SITES=	http://el.beplacid.net/downloads/:data \
		http://www.eternal-lands.com/:data \
		http://el.rauchs-home.de/client/:data \
		http://www.eternallands.co.uk/:sound \
		http://www.eternallands.co.uk/:music
PKGNAMEPREFIX=	el-
DISTFILES=	${EL_DATA}:data
DIST_SUBDIR=	${PKGNAMEPREFIX:S/-//}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Eternal Lands data, sound and music files

USE_ZIP=	yes
NO_PACKAGE=	Package will be 140MB, set FORCE_PACKAGE if you really want it
NO_BUILD=	yes
USE_DOS2UNIX=	*.ini *.txt

DATADIR=	${PREFIX}/share/${PKGNAMEPREFIX:S/-//}
PLIST=		${WRKDIR}/pkg-plist
WRKSRC=		${WRKDIR}/${PKGNAMEPREFIX:S/-/_/}linux
EL_DATA=	${PKGNAMEPREFIX:S/-/_/}linux_${PORTVERSION}.zip

OPTIONS=	ELSOUND	"Install additional sound files"	on \
		ELMUSIC	"Install additional music files"	on

.include <bsd.port.pre.mk>

.if defined(WITH_ELSOUND)
DISTFILES+=	EL_sound_191${EXTRACT_SUFX}:sound
HAVE_ESOUND=	yes
.endif

.if defined(WITH_ELMUSIC)
DISTFILES+=	music_full${EXTRACT_SUFX}:music
HAVE_EMUSIC=	yes
.endif

do-extract:
	@${MKDIR} ${WRKDIR}
	@${UNZIP_CMD} -q ${_DISTDIR}/${EL_DATA} -d ${WRKDIR}
.if defined(HAVE_ESOUND)
	@${UNZIP_CMD} -q ${_DISTDIR}/EL_sound_191${EXTRACT_SUFX} -d ${WRKSRC}
.endif
.if defined(HAVE_EMUSIC)
	@${MKDIR} ${WRKSRC}/music
	@${UNZIP_CMD} -q ${_DISTDIR}/music_full${EXTRACT_SUFX} -d ${WRKSRC}/music
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
	${MKDIR} ${DATADIR}
	@cd ${WRKSRC} && \
		${FIND} * -type d -exec ${MKDIR} "${DATADIR}/{}" \; && \
			${FIND} * -type f -exec ${INSTALL_DATA} "{}" "${DATADIR}/{}" \;

.include <bsd.port.post.mk>
