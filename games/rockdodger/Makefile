# Created by: Neil Blakey-Milner <nbm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rockdodger
PORTVERSION=	1.1.4
CATEGORIES=	games
MASTER_SITES=	https://bitbucket.org/rpkrawczyk/rockdodger/downloads/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Addictive rock-dodging greeblie-killing platform game

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libogg.so:audio/libogg

USES=		gmake sdl
USE_SDL=	mixer image sdl

PORTDATA=	*

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/rockdodger.icon.64x64.xpm ${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.xpm
	${INSTALL_DATA} ${WRKSRC}/rockdodger.desktop ${STAGEDIR}${PREFIX}/share/applications/
	${MV} ${STAGEDIR}/var/games/rockdodger.scores ${STAGEDIR}/var/games/rockdodger.scores.sample

.include <bsd.port.mk>
