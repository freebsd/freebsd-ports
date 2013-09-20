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

USE_XORG=	x11 xpm

DESKTOP_ENTRIES="xtron" \
		"Avoid running into walls, your own tail, and that of your opponent" \
		"${DATADIR}/Xtron_icon.xpm" \
		"xtron" \
		"Game;ArcadeGame;" \
		false

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/xtronrc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xtron ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/pixmaps/* ${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/xtronrc ${PREFIX}/lib/X11/app-defaults/Tron
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGES ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
