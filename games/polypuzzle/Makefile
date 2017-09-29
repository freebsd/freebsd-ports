# Created by: janos.mohacsi@bsd.hu
# $FreeBSD$

PORTNAME=	polypuzzle
PORTVERSION=	1.8.2
CATEGORIES=	games tcl tk
MASTER_SITES=	SF/tkgames/${PORTNAME}/main

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tessellation puzzle game

DEPRECATED=		This port depends on Tcl/Tk 8.4 , which is no longer\
			maintained. Please port it to 8.5+
EXPIRATION_DATE=	2017-10-15

USES= 		tar:tgz tk:84,run
WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes
NO_ARCH=	yes
DESKTOP_ENTRIES="PolyPuzzle" "" "" "polypuzzle" "" ""

post-patch:
	 @${REINPLACE_CMD} -e 's|%%WISH%%|${WISH:T}|' \
			-e 's|%%DATADIR%%|${DATADIR}|g' \
			${WRKSRC}/polypuzzle

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/polypuzzle ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} colours menus pieces.* *.gif *.xbm \
		${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
