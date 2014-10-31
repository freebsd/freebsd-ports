# Created by: Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	warsow-data
PORTVERSION=	1.51
CATEGORIES=	games
MASTER_SITES=	SF/warsow.mirror/Warsow%20${PORTVERSION} \
		http://www.warsow.net:1337/~warsow/${PORTVERSION}/ \
		http://www.warsow.eu/:mappack \
		LOCAL/nemysis/games:mappack
DISTNAME=	warsow_${PORTVERSION}_unified
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Warsow data files

LICENSE=	WARSOW GPLv2
LICENSE_COMB=	multi
LICENSE_NAME_WARSOW=	Warsow Content License
LICENSE_FILE_WARSOW=	${WRKSRC}/docs/license.txt
LICENSE_PERMS_WARSOW=	dist-mirror pkg-mirror auto-accept

# Game port is restricted to these architectures, so it makes no sense to
# package game data port as well (even it is not being technically built)
ONLY_FOR_ARCHS=	i386 amd64

WRKSRC=		${WRKDIR}/warsow_15
NO_BUILD=	yes
DATADIR=	${PREFIX}/share/warsow
DOCSDIR=	${PREFIX}/share/doc/warsow

PORTDATA=	basewsw
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS MAPPACK
OPTIONS_DEFAULT=	MAPPACK
MAPPACK_DESC=		Install community map pack

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMAPPACK}
MAPPACK_FILE=	warsow_comunity_map_pack_01.zip
DISTFILES+=	${MAPPACK_FILE}:mappack
EXTRACT_DEPENDS+=	${UNZIP_CMD}:${PORTSDIR}/archivers/unzip
PORTDATA+=	previews

post-extract:
	@${UNZIP_CMD} -qo ${DISTDIR}/${MAPPACK_FILE} -d ${WRKSRC}
.endif

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} "${PORTDATA}" ${STAGEDIR}${DATADIR}
	cd ${WRKSRC}/docs && ${COPYTREE_SHARE} "${PORTDOCS}" ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
