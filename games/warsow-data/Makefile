# New ports collection makefile for:	Warsow game data
# Date created:				2006-08-03
# Whom:				Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	data
PORTVERSION=	0.6
CATEGORIES=	games
MASTER_SITES=	http://www.zcdn.org/dl/ \
		http://www.derchris.eu/warsow/ \
		http://www.derchris.eu/warsow/:mappack \
		http://static.warsow.net/release/:mappack \
		http://rewq.de/scratch/wsw05/:mappack \
		http://weseo.de/downloads/:mappack
PKGNAMEPREFIX=	warsow-
DISTNAME=	${PKGNAMEPREFIX:S/-//}_${PORTVERSION}_unified
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
DIST_SUBDIR=	${PKGNAMEPREFIX:S/-//}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Warsow data files

# Package size below is for default set of OPTIONS
NO_PACKAGE=	Package will be 550MB, set FORCE_PACKAGE if you really want it

ONLY_FOR_ARCHS=	i386 amd64
USE_ZIP=	yes

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
DATADIR=	${PREFIX}/share/${PKGNAMEPREFIX:S/-//}
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX:S/-//}
TXTDOCS=	bots_navigation.txt changelog.txt contact.txt \
		dedicated_server_quide.txt demoavi.txt democams.txt \
		features.txt huds.txt license.txt mousefilter.txt \
		query_protocols.txt
PORTDOCS=	0.4_renderer_changes.png ${TXTDOCS}

OPTIONS=	MAPPACK		"Install community map pack"	on

.include <bsd.port.options.mk>

.if defined(WITH_MAPPACK)
DISTFILES+=	warsow_comunity_map_pack_01${EXTRACT_SUFX}:mappack
PLIST_SUB+=	MAPPACK=""
.else
PLIST_SUB+=	MAPPACK="@comment "
.endif

do-install:
	@${MKDIR} ${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} basewsw ${DATADIR}
.if defined(WITH_MAPPACK)
	cd ${WRKSRC} && ${COPYTREE_SHARE} previews ${DATADIR}
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/docs && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
