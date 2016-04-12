# Created by: alepulver
# $FreeBSD$

PORTNAME=	legends
PORTVERSION=	0.4.1.43
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://legendsthegame.net/files/:game \
		http://legendsthegame.net/files/maps/:maps
DISTNAME=	${PORTNAME}_linux_gui-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:game \
		${MAP_PACK}:maps
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
EXTRACT_SUFX=	.run

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fast-paced first-person-perspective online multiplayer game

RUN_DEPENDS=	bash:shells/bash

USES=		makeself
USE_LINUX=	yes
USE_LINUX_APPS+=dri
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
DATADIR=	${PREFIX}/lib/${PORTNAME}

# Standard map pack used in official servers.
MAP_PACK=	BTMappack-1.05.unf
PLIST_SUB=	MAP_PACK="${MAP_PACK}"

OPTIONS_DEFINE=	DOCS

post-extract:
	@cd ${WRKSRC} && ${TAR} xf legends.tar

post-patch:
	@${REINPLACE_CMD} -e 's|#!/bin/bash|#!${LOCALBASE}/bin/bash|; \
	    s|`dirname $$0`|${DATADIR}|; s|./LinLegends|exec &|; s| &$$||' \
	    ${WRKSRC}/bin/runlegends

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && \
		${INSTALL_PROGRAM} LinLegends lindedicated *.so* ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/runlegends ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/legends.ico ${STAGEDIR}${PREFIX}/share/pixmaps
	${LN} -sf ${DATADIR}/runlegends ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
.for f in common legends main.cs show
	${CP} -r ${WRKSRC}/${f} ${STAGEDIR}${DATADIR}
.endfor
	${INSTALL_DATA} ${DISTDIR}/${MAP_PACK} ${STAGEDIR}${DATADIR}/legends
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
