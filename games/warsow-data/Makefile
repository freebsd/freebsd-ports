# Created by: Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	data
PORTVERSION=	1.0.2
CATEGORIES=	games
MASTER_SITES=	SF/warsow.mirror/Warsow%20${PORTVERSION:R}${PORTVERSION:E} \
		http://www.warsow.net:1337/~warsow/${PORTVERSION:R}${PORTVERSION:E}/ \
		http://static.warsow.net/release/:mappack \
		http://rewq.de/scratch/wsw05/:mappack
PKGNAMEPREFIX=	warsow-
DISTNAME=	${PKGNAMEPREFIX:S/-//}_${PORTVERSION:R}${PORTVERSION:E}
DIST_SUBDIR=	${PKGNAMEPREFIX:S/-//}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Warsow data files

LICENSE=	WARSOW GPLv2
LICENSE_COMB=	multi
LICENSE_NAME_WARSOW=	Warsow Content License
LICENSE_FILE_WARSOW=	${WRKSRC}/docs/license.txt
LICENSE_PERMS_WARSOW=	dist-mirror pkg-mirror auto-accept

# Game port is restricted to these architectures, so it makes no sense to
# package game data port as well (even it is not being technically built)
ONLY_FOR_ARCHS=	i386 amd64

NO_BUILD=	yes
DATADIR=	${PREFIX}/share/${PKGNAMEPREFIX:S/-//}
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX:S/-//}

PORTDATA=	basewsw
PORTDOCS=	*

OPTIONS_DEFINE=	MAPPACK DOCS
OPTIONS_DEFAULT=	MAPPACK
MAPPACK_DESC=		Install community map pack

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMAPPACK}
MAPPACK_FILE= warsow_comunity_map_pack_01.zip
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${MAPPACK_FILE}:mappack
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
EXTRACT_DEPENDS+=	${UNZIP_CMD}:${PORTSDIR}/archivers/unzip
PORTDATA+=	previews
.endif

post-extract:
.if ${PORT_OPTIONS:MMAPPACK}
	@${UNZIP_CMD} -qo ${DISTDIR}/${DIST_SUBDIR}/${MAPPACK_FILE} -d ${WRKSRC}
.endif

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} "${PORTDATA}" ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
