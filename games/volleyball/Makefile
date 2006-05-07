# New ports collection makefile for:	volleyball
# Date created:		09 Oct 2005
# Whom:			Dmitry Marakasov <amdmi3@mail.ru>
#
# $FreeBSD$
#

PORTNAME=	volleyball
PORTVERSION=	0.8
CATEGORIES=	games
MASTER_SITES=	http://www.losersjuegos.com.ar/juegos/volleyball/descargas/
DISTNAME=	${PORTNAME}20051004

MAINTAINER=	amdmi3@mail.ru
COMMENT=	A game similar to GNU Arcade Volleyball

USE_SDL=	sdl
USE_GMAKE=	yes
MAKE_ARGS=	CC="${CC}" CFLAGS="`${SDL_CONFIG} --cflags` ${CFLAGS}" \
		LDFLAGS="`${SDL_CONFIG} --libs`"
ALL_TARGET=	volleyball

WRKSRC=	${WRKDIR}/${PORTNAME}/paso_8

post-patch:
	@${REINPLACE_CMD} -e 's|ima/|${DATADIR}/|' ${WRKSRC}/*.c
	@${REINPLACE_CMD} -e 's|^\([LDC]*FLAGS\)|#\1|' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/volleyball ${PREFIX}/bin/
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/ima/* ${DATADIR}/

.include <bsd.port.mk>
