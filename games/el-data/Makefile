# New ports collection makefile for:	el-data
# Date created:		2006-08-18
# Whom:			Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	data
PORTVERSION=	133
CATEGORIES=	games
MASTER_SITES=	http://el.other-life.com/downloads/:data \
		http://www.eternalmusik.org/music/:sound \
		http://www.el-development.com/music/:sound
PKGNAMEPREFIX=	el-
DISTFILES=	${EL_DATA}:data \
		${EL_SOUND}:sound
DIST_SUBDIR=	${PKGNAMEPREFIX:S/-//}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Eternal Lands data and sound files

USE_ZIP=	yes
NO_BUILD=	yes
USE_DOS2UNIX=	*.ini *.txt

DATADIR=	${PREFIX}/share/${PKGNAMEPREFIX:S/-//}
WRKSRC=		${WRKDIR}/Eternal\ Lands-${PORTVERSION:S/1/1./}
EL_DATA=	${PKGNAMEPREFIX:S/-/_/}${PORTVERSION}_linux_full.zip
EL_SOUND=	music_full.zip

do-extract:
	@${MKDIR} ${WRKDIR}
	@${UNZIP_CMD} -q ${_DISTDIR}/${EL_DATA} -d ${WRKDIR}
	@${UNZIP_CMD} -q ${_DISTDIR}/${EL_SOUND} -d ${WRKSRC}/music

post-extract:
	@${FIND} ${WRKSRC} -type d -name CVS -print0 | \
		${XARGS} -0 ${RM} -R
	@${FIND} ${WRKSRC} -type f -name "*.dll" -print0 | \
		${XARGS} -0 ${RM} -R
	@${FIND} ${WRKSRC} -type f -name "*.exe" -print0 | \
		${XARGS} -0 ${RM} -R
	@${RM} ${WRKSRC}/el-${PORTVERSION}.* \
		${WRKSRC}/languages/en/strings/options.xml~
.for DIRE in languages/po/books languages/po/strings languages/tr/strings
	@${RMDIR} ${WRKSRC}/${DIRE}
.endfor

do-install:
	${MKDIR} ${DATADIR}
	@cd ${WRKSRC} && \
		${FIND} * -type d -exec ${MKDIR} "${DATADIR}/{}" \; && \
			${FIND} * -type f -exec ${INSTALL_DATA} "{}" "${DATADIR}/{}" \;

.include <bsd.port.mk>
