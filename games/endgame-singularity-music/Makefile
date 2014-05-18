# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	endgame-singularity-music
PORTVERSION=	007
CATEGORIES=	games
MASTER_SITES=	GOOGLE_CODE
PROJECTHOST=	endgame-singularity

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Music pack for endgame-singularity

NO_ARCH=	yes
NO_BUILD=	yes

USES=		zip

DATADIR=	${PREFIX}/share/singularity

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/music
	@(cd ${WRKSRC} && ${INSTALL_DATA} *.ogg \
		${STAGEDIR}${DATADIR}/music)
	@${MKDIR} ${STAGEDIR}${DATADIR}/music/lose
	@(cd ${WRKSRC}/lose && ${INSTALL_DATA} *.ogg \
		${STAGEDIR}${DATADIR}/music/lose)
	@${MKDIR} ${STAGEDIR}${DATADIR}/music/win
	@(cd ${WRKSRC}/win && ${INSTALL_DATA} *.ogg \
		${STAGEDIR}${DATADIR}/music/win)

.include <bsd.port.mk>
