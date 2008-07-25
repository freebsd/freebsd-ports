# New ports collection makefile for:	warsow-data
# Date created:				2006-08-03
# Whom:				Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	data
PORTVERSION=	0.42
CATEGORIES=	games
MASTER_SITES=	http://data.rodix.free.fr/warsow/files/ \
		http://88.191.19.21/wsw/ \
		http://www.derchris.net/warsow/ \
		http://gedankenschlag.de/mirror/ \
		http://uzz.cc/ \
		http://wahs.de/warsow/ \
		http://tastyspleen.net/quake/downloads/mods/warsow/
PKGNAMEPREFIX=	warsow-
DISTNAME=	${PKGNAMEPREFIX:S/-//}_${PORTVERSION}_unified
DIST_SUBDIR=	${PKGNAMEPREFIX:S/-//}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Warsow data files

USE_ZIP=	yes
USE_DOS2UNIX=	${TXTDOCS}

NO_BUILD=	yes
DATADIR=	${PREFIX}/share/${PKGNAMEPREFIX:S/-//}
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX:S/-//}
TXTDOCS=	bots_navigation.txt changelog.txt contact.txt credits.txt \
		dedicated_server_quide.txt demoavi.txt democams.txt \
		features.txt huds.txt license.txt mousefilter.txt \
		query_protocols.txt
PORTDOCS=	0.4_renderer_changes.png ${TXTDOCS}

do-install:
	@${MKDIR} ${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} basewsw ${DATADIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/docs && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
