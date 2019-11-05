# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	xtron
PORTVERSION=	1.1a
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	SUNSITE/games/arcade
EXTRACT_SUFX=	.tgz

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Avoid running into walls, your own tail, and that of your opponent

USES=		xorg
USE_XORG=	x11 xpm

PLIST_FILES=	bin/${PORTNAME} lib/X11/app-defaults/Tron
PORTDOCS=	*
PORTDATA=	*

DESKTOP_ENTRIES="xtron" \
		"Avoid running into walls, your own tail, and that of your opponent" \
		"${DATADIR}/Xtron_icon.xpm" \
		"${PORTNAME}" \
		"Game;ArcadeGame;" \
		false

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/xtronrc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/pixmaps/* ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/xtronrc ${STAGEDIR}${PREFIX}/lib/X11/app-defaults/Tron
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGES ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
