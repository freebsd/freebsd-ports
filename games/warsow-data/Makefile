# Created by: Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	data
PORTVERSION=	1.5
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	SF/warsow.mirror/Warsow%20${PORTVERSION} \
		http://www.warsow.net:1337/~warsow/${PORTVERSION}/ \
		http://www.warsow.eu/:mappack \
		LOCAL/nemysis/games:mappack

PKGNAMEPREFIX=	warsow-
DISTNAME=	${PKGNAMEPREFIX:S/-//}_${PORTVERSION:S/.//}_unified
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
DIST_SUBDIR=	${PKGNAMEPREFIX:S/-//}

MAINTAINER=	games@FreeBSD.org
COMMENT=	Warsow data files

LICENSE=	WARSOW GPLv2
LICENSE_COMB=	multi
LICENSE_NAME_WARSOW=	Warsow Content License
LICENSE_FILE_WARSOW=	${WRKSRC}/docs/license.txt
LICENSE_PERMS_WARSOW=	dist-mirror pkg-mirror auto-accept

RUN_DEPENDS=	warsow:${PORTSDIR}/games/warsow

# Game port is restricted to these architectures, so it makes no sense to
# package game data port as well (even it is not being technically built)
ONLY_FOR_ARCHS=	i386 amd64

WRKSRC=		${WRKDIR}/${PKGNAMEPREFIX:S/-//}_15
NO_BUILD=	yes
DATADIR=	${PREFIX}/share/${PKGNAMEPREFIX:S/-//}
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX:S/-//}

PORTDOCS=	*.txt

OPTIONS_DEFINE=	DOCS MAPPACK
OPTIONS_DEFAULT=	MAPPACK
MAPPACK_DESC=		Install community map pack

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMAPPACK}
MAPPACK_FILE=	warsow_comunity_map_pack_01.zip
DISTFILES+=	 ${MAPPACK_FILE}:mappack
EXTRACT_DEPENDS+=	${UNZIP_CMD}:${PORTSDIR}/archivers/unzip
.endif

post-extract:
.if ${PORT_OPTIONS:MMAPPACK}
	@${UNZIP_CMD} -qo ${DISTDIR}/${DIST_SUBDIR}/${MAPPACK_FILE} -d ${WRKSRC}
.endif

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} basewsw ${STAGEDIR}${DATADIR}

.if ${PORT_OPTIONS:MMAPPACK}
	cd ${WRKSRC} && ${COPYTREE_SHARE} previews ${STAGEDIR}${DATADIR}
.endif

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/docs/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
