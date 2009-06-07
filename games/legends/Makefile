# New ports collection makefile for:	legends
# Date created:				2007-12-16
# Whom:					alepulver
#
# $FreeBSD$
#

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

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	Fast-paced first-person-perspective online multiplayer game

RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

USE_MAKESELF=	yes
USE_LINUX=	yes
USE_LINUX_APPS+=dri
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
DATADIR=	${PREFIX}/lib/${PORTNAME}

# Standard map pack used in official servers.
MAP_PACK=	BTMappack-1.05.unf
PLIST_SUB=	MAP_PACK="${MAP_PACK}"

post-extract:
	@cd ${WRKDIR} && ${TAR} xf legends.tar

post-patch:
	@${REINPLACE_CMD} -e 's|#!/bin/bash|#!${LOCALBASE}/bin/bash|; \
	    s|`dirname $$0`|${DATADIR}|; s|./LinLegends|exec &|; s| &$$||' \
	    ${WRKSRC}/bin/runlegends

do-install:
	${MKDIR} ${DATADIR}
	cd ${WRKSRC} && \
		${INSTALL_PROGRAM} LinLegends lindedicated *.so* ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/runlegends ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/legends.ico ${PREFIX}/share/pixmaps
	${LN} -sf ${DATADIR}/runlegends ${PREFIX}/bin/${PORTNAME}
.for f in common legends main.cs show
	${CP} -r ${WRKSRC}/${f} ${DATADIR}
.endfor
	${INSTALL_DATA} ${DISTDIR}/${MAP_PACK} ${DATADIR}/legends
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
