# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	flobopuyo
PORTVERSION=	0.20
PORTREVISION=	12
CATEGORIES=	games
MASTER_SITES=	http://www.ios-software.com/flobopuyo/ \
		http://mirror.amdmi3.ru/distfiles/
EXTRACT_SUFX=	.tgz

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Clone of the famous PuyoPuyo

USES=		bison
USE_GMAKE=	yes
USE_SDL=	sdl mixer image
USE_DOS2UNIX=	yes
MAKE_JOBS_SAFE=	yes

DESKTOP_ENTRIES="FloboPuyo" \
		"Clone of the famous PuyoPuyo" \
		"${DATADIR}/gfx/Neutral.png" \
		"flobopuyo" \
		"Game;BlocksGame;" \
		false

post-extract:
	@${FIND} ${WRKSRC} -name '._*' -delete

post-patch:
	@${REINPLACE_CMD} -e 's|sdl-config|${SDL_CONFIG}|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|g++|${CXX}|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|^CFLAGS=|CFLAGS+=|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|^DATADIR=.*$$|DATADIR=${DATADIR}|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|^INSTALL_DATADIR=.*$$|INSTALL_DATADIR=${DATADIR}|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|^INSTALL_BINDIR=.*$$|INSTALL_BINDIR=${PREFIX}/bin|' ${WRKSRC}/Makefile

.include <bsd.port.mk>
