# New ports collection makefile for:	xtron
# Date created:				29 March 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	xtron
PORTVERSION=	1.1a
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	games/arcade
EXTRACT_SUFX=	.tgz

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Avoid running into walls, your own tail, and that of your opponent

USE_XORG=	x11 xpm
MAKE_JOBS_SAFE=	yes

DESKTOP_ENTRIES="xtron" \
		"Avoid running into walls, your own tail, and that of your opponent" \
		"${DATADIR}/Xtron_icon.xpm" \
		"xtron" \
		"Game;ArcadeGame;" \
		false

post-patch:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/xtronrc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xtron ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/pixmaps/* ${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/xtronrc ${PREFIX}/lib/X11/app-defaults/Tron
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGES ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
