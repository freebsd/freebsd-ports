# New ports collection makefile for:	flobopuyo
# Date created:		24 Feb 2006
# Whom:			Dmitry Marakasov <amdmi3@mail.ru>
#
# $FreeBSD$
#

PORTNAME=	flobopuyo
PORTVERSION=	0.20
CATEGORIES=	games
MASTER_SITES=	http://www.ios-software.com/flobopuyo/
EXTRACT_SUFX=	.tgz

MAINTAINER=	amdmi3@mail.ru
COMMENT=	Clone of the famous PuyoPuyo

USE_BISON=	yes
USE_GMAKE=	yes
USE_SDL=	sdl mixer image
USE_GCC=	3.4+

post-patch:
	@${REINPLACE_CMD} -e 's|SDL/|SDL11/|' ${WRKSRC}/audio.h ${WRKSRC}/glSDL.h ${WRKSRC}/main.cpp
	@${REINPLACE_CMD} -e 's|sdl-config|${SDL_CONFIG}|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|g++|${CXX}|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|^CFLAGS=|CFLAGS+=|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|^DATADIR=.*$$|DATADIR=${DATADIR}|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|^INSTALL_DATADIR=.*$$|INSTALL_DATADIR=${DATADIR}|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|^INSTALL_BINDIR=.*$$|INSTALL_BINDIR=${PREFIX}/bin|' ${WRKSRC}/Makefile

.include <bsd.port.mk>
