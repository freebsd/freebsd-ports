# New ports collection makefile for:	warsow-data
# Date created:		2006-08-03
# Whom:			Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	data
PORTVERSION=	0.12
CATEGORIES=	games
MASTER_SITES=	http://ftp.club-internet.fr/pub/games/nofrag/warsow/
MASTER_SITES=	http://ftp.club-internet.fr/pub/games/nofrag/warsow/ \
		http://mirrors-av.club-internet.fr/pub/games/nofrag/warsow/ \
		http://kenh.rxvt.net/ \
		http://turkeyfiles.escapedturkey.net/warsow/versions/ \
		http://www.gizmo.fi/warsow/ \
		http://warsow.as-mirror.net/ \
		http://wsw.surreal-xenotronic.com/ \
		http://tmp.death-row.org/
PKGNAMEPREFIX=	warsow-
DISTNAME=	${PKGNAMEPREFIX:S/-//}_${PORTVERSION}_linux
DIST_SUBDIR=	${PKGNAMEPREFIX:S/-//}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Warsow data files

NO_BUILD=	yes
WARSOW_EXTRACT=	${PKGNAMEPREFIX:S/-//}/basewsw ${PKGNAMEPREFIX:S/-//}/docs
DATADIR=	${PREFIX}/share/${PKGNAMEPREFIX:S/-//}
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX:S/-//}
WRKSRC=		${WRKDIR}/${PKGNAMEPREFIX:S/-//}
EXTRACT_AFTER_ARGS=	| ${TAR} -xf - ${WARSOW_EXTRACT}

post-extract:
	${RM} -R ${WRKSRC}/basewsw/*.so
	${RM} -R ${WRKSRC}/basewsw/screenshots ${WRKSRC}/basewsw/demos

do-install:
	@${MKDIR} ${DATADIR}/basewsw
	@cd ${WRKSRC}/basewsw && \
		${FIND} * -type d -exec ${MKDIR} "${DATADIR}/basewsw/{}" \; && \
			${FIND} -E * -type f -iregex ".*\.(pk3|cfg|hud)" \
				-exec ${INSTALL_DATA} "{}" "${DATADIR}/basewsw/{}" \;
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.	for FILE in Shader* bots_navigation.txt changelog.txt contact.txt dedicated* demoavi.txt \
		huds.txt linux_sound_sdl.txt new* query*
			${INSTALL_DATA} ${WRKSRC}/docs/${FILE} ${DOCSDIR}
.	endfor
.endif

post-install:
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
