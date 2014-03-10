# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD$

PORTNAME=	moagg
PORTVERSION=	1.95b
PORTREVISION=	1
CATEGORIES=	games java
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}2/${DISTVERSION:S/b//}/ \
		SF/nemysisfreebsdp/games/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}-bin.zip \
		${PORTNAME}.png:icons
DIST_SUBDIR=	java
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}-bin.zip

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Pilot a small space ship

LICENSE=	GPLv2

DATADIR=	${JAVASHAREDIR}/${PORTNAME}

USES=		zip
USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	yes

PORTDOCS=	AUTHORS README.txt

OPTIONS_DEFINE=	DOCS

DESKTOP_ENTRIES="MOAGG, Mother of all gravity Games" "" ${PORTNAME} \
		"${PORTNAME}" "Game;ArcadeGame;" ""

post-patch:
	@${REINPLACE_CMD} -e 's|%%JAVASHAREDIR%%|${JAVASHAREDIR}|' \
		${WRKSRC}/run.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/run.sh \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "data ghosts jar" \
		${STAGEDIR}${DATADIR})
.for d in hiscores.dat log4j.properties
	${INSTALL_DATA} ${WRKSRC}/${d} ${STAGEDIR}${DATADIR}
.endfor

	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
